// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "HierarchicalEditAsset.h"

#include "Graph/HierarchicalRootNode.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HierarchicalStateNode.h"

#include "ActorState.h"
#include "UObject/SavePackage.h"
#include "AssetRegistryModule.h"
#include "Kismet/KismetSystemLibrary.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

void UHierarchicalEditAsset::CompileGraphToAsset()
{
	UE_LOG(LogTemp, Log, TEXT("Attempting to compile hierarchical graph."));

	if (!ValidateInputPins(WorkingGraph)) {
		UE_LOG(LogTemp, Error, TEXT("Graph failed validation"));
		return;
	}

	TArray<UHierarchicalRootNode*> RootNodes;
	WorkingGraph->GetNodesOfClass<UHierarchicalRootNode>(RootNodes);

	if (RootNodes.Num() != 1) {
		UE_LOG(LogTemp, Error, TEXT("Graph should have exactly one root node."));
		return;
	}

	UHierarchicalRootNode* RootNode = *RootNodes.begin();

	UObject* OutAsset = TargetInfo.OutAsset;

	//if existing out asset, simply try overwrite
	if (OutAsset != nullptr) {
		UE_LOG(LogTemp, Log, TEXT("Attempting to overwrite existing asset."));

		if (OutAsset->GetClass() != RootNode->InnerClass) {

			UE_LOG(LogTemp, Error, TEXT("Existing asset is of incompatible class."));
			return;
		}

		UObject* FinalizedAsset = RootNode->GetFinalizedAssetRecursive();


		TArray<UObject*> SubObjectsToReparent;
		GetObjectsWithOuter(FinalizedAsset, SubObjectsToReparent, /*bIncludeNestedObjects*/ false);

		for (UObject* SubObject : SubObjectsToReparent) {
			SubObject->Rename(nullptr, OutAsset);
		}

		for (TFieldIterator<FProperty> PropIter(RootNode->InnerClass); PropIter; ++PropIter) {
			PropIter->CopyCompleteValue(
				/*Dest*/PropIter->ContainerPtrToValuePtr<void>(OutAsset),
				/*Src*/PropIter->ContainerPtrToValuePtr<void>(FinalizedAsset)
			);
		}


		UE_LOG(LogTemp, Log, TEXT("Finished overwriting."));
		OutAsset->Modify();
		return;
	}


	UE_LOG(LogTemp, Log, TEXT("No existing asset. Must create new."));

	UPackage* GraphOwnerPackage = this->GetPackage();
	
	FSaveAssetDialogConfig SaveAssetDialogConfig;
	SaveAssetDialogConfig.DialogTitleOverride = NSLOCTEXT("", "SaveAssetDialogTitle", "Save Asset As");
	SaveAssetDialogConfig.DefaultPath = GraphOwnerPackage->GetFName().ToString();
	SaveAssetDialogConfig.DefaultAssetName = this->GetFName().ToString()+"_Output";
	SaveAssetDialogConfig.ExistingAssetPolicy = ESaveAssetDialogExistingAssetPolicy::Disallow;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	FString SaveObjectPath = ContentBrowserModule.Get().CreateModalSaveAssetDialog(SaveAssetDialogConfig);

	if (SaveObjectPath.IsEmpty()) return;
	
	const FString SavePackageName = FPackageName::ObjectPathToPackageName(SaveObjectPath);
	const FString SavePackagePath = FPaths::GetPath(SavePackageName);
	const FString SaveAssetName = FPaths::GetBaseFilename(SavePackageName);


	UPackage* OutPackage = CreatePackage(*SavePackageName);

	if (OutPackage == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("No package to save into."));
		return;
	}

	

	

	UObject* FinalizedAsset = RootNode->GetFinalizedAssetRecursive();


	FinalizedAsset->Rename(*SaveAssetName, OutPackage);
	FinalizedAsset->SetFlags(EObjectFlags::RF_Public | EObjectFlags::RF_Standalone);


	FAssetRegistryModule::AssetCreated(FinalizedAsset);
	FinalizedAsset->MarkPackageDirty();

	FString FilePath = FString::Printf(TEXT("%s%s"), *SaveObjectPath, *FPackageName::GetAssetPackageExtension());
	bool bSuccess = UPackage::SavePackage(OutPackage, FinalizedAsset, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);

	UE_LOG(LogTemp, Warning, TEXT("Saved Package: %s"), bSuccess ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, Warning, TEXT("Saved Package to: %s"), *SaveObjectPath);

	TargetInfo.OutAsset = FinalizedAsset;
	this->Modify();

}

bool UHierarchicalEditAsset::ValidateInputPins(UEdGraph* Graph) {
	UE_LOG(LogTemp, Log, TEXT("Validating hierarchical graph"));

	TMap<FString, TArray< UHierarchicalStateNode*>> StateNodesByNameID;
	TArray<FString> DuplicateStateNameIds;

	TArray< UEdGraphNode*> MultiParentStates;

	for (UEdGraphNode* Node : Graph->Nodes) {
		//Clear existing error messages
		Node->ErrorMsg = "";
		Node->bHasCompilerMessage = false;

		//UniqueStateNameIDValidator
		UHierarchicalStateNode* StateNode = Cast< UHierarchicalStateNode>(Node);

		if (StateNode != nullptr) {
			UActorState* StateObject = Cast< UActorState>(StateNode->GetInnerObject());

			if (StateObject != nullptr) {
				FString NameID = StateObject->NameID.ToString();

				TArray< UHierarchicalStateNode*>* NodesOfNameID = StateNodesByNameID.Find(NameID);

				if (NodesOfNameID == nullptr) {
					StateNodesByNameID.Add(NameID, TArray< UHierarchicalStateNode*>());
					NodesOfNameID = StateNodesByNameID.Find(NameID);
				}

				NodesOfNameID->Add(StateNode);
			}
		}

		// UniqueStateParents
		for (UEdGraphPin* Pin : Node->GetAllPins()) {

			if (Pin->Direction != EGPD_Input) continue;

			FEdGraphPinType PinType = Pin->PinType;
			if (PinType.PinSubCategory != UHierarchicalGraphSchema::SC_ChildNode) continue;

			if (PinType.PinSubCategoryObject == nullptr) continue;

			UClass* NodeClass = Cast<UClass>(PinType.PinSubCategoryObject);

			if (NodeClass == nullptr) continue;
			if (!NodeClass->IsChildOf(UActorState::StaticClass())) continue;

			if (Pin->LinkedTo.Num() > 1) {
				MultiParentStates.Add(Node);
			}
		}
	}


	UE_LOG(LogTemp, Log, TEXT("Unique IDs: %d"), StateNodesByNameID.Num());
	for (TPair<FString, TArray< UHierarchicalStateNode*>> Entry : StateNodesByNameID) {
		if (Entry.Value.Num() > 1) {
			UE_LOG(LogTemp, Log, TEXT("Yuuup"));
			DuplicateStateNameIds.Add(Entry.Key);
		}
	}

	//Apply new error messages
	for (FString DuplicateID : DuplicateStateNameIds) {
		TArray< UHierarchicalStateNode*>* NodesOfNameID = StateNodesByNameID.Find(DuplicateID);

		for (UEdGraphNode* InvalidNode : *NodesOfNameID) {
			InvalidNode->ErrorMsg += "NameID must be unique.\n";
			InvalidNode->bHasCompilerMessage = true;
		}
	}

	for (UEdGraphNode* InvalidNode : MultiParentStates) {
		InvalidNode->ErrorMsg += "States cannot have multiple parents.\n";
		InvalidNode->bHasCompilerMessage = true;
	}

	Graph->NotifyGraphChanged();

	return !bool(MultiParentStates.Num() || DuplicateStateNameIds.Num());
}
