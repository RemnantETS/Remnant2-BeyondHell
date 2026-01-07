#include "HierarchicalStateNode.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HierarchicalArrayNode.h"

#include "ActorState.h"
#include "ActorStateID.h"

FText UHierarchicalStateNode::GetNodeTitle(ENodeTitleType::Type TitelType) const
{
	TArray<FString> TitleLines;
	
	UActorState* InnerState = Cast< UActorState>(GetInnerObject());

	if (!InnerState->NameID.IsNone()) {
		TitleLines.Add( InnerState->NameID.ToString() );
	}

	if (TitelType != ENodeTitleType::EditableTitle || InnerState->NameID.IsNone()) {
		TitleLines.Add(InnerClass->GetFName().ToString() );
	}

	const FString Title = FString::Join(TitleLines, TEXT("\n"));

	return FText::FromString(Title);
}

void UHierarchicalStateNode::OnRenameNode(const FString& NewName)
{
	UHierarchicalChildNode::OnRenameNode(NewName);
	UActorState* InnerState = Cast< UActorState>(GetInnerObject());
	InnerState->Modify();
	InnerState->NameID = FName(NewName);
}

void UHierarchicalStateNode::SetUpInputPins()
{
	UHierarchicalChildNode::SetUpInputPins();

	FEdGraphPinType PinType;
	PinType.PinSubCategory = UHierarchicalGraphSchema::SC_StateTransition;
	PinType.ContainerType = EPinContainerType::None;

	this->CreatePin(
		EGPD_Input,
		PinType,
		FName("UniqueId")
	);
}

void UHierarchicalStateNode::SetUpOutputPins()
{
	UHierarchicalChildNode::SetUpOutputPins();


	for (TFieldIterator<FProperty> PropIterator(InnerClass); PropIterator; ++PropIterator) {

		if (GetFieldNamesToIgnore().Contains(PropIterator->GetName())) continue;

		bool bIsArrayField = false;
		FProperty* TestProperty = *PropIterator;

		FArrayProperty* TestArray = CastField<FArrayProperty>(*PropIterator);
		if (TestArray != nullptr) {
				TestProperty = TestArray->Inner;
			bIsArrayField = true;
		}

		FStructProperty* TestStructProperty = CastField<FStructProperty>(TestProperty);

		if (TestStructProperty == nullptr) continue;

			if (TestStructProperty->Struct == TBaseStructure<FActorStateID>::Get()) {

				FEdGraphPinType PinType;
				PinType.PinSubCategory = UHierarchicalGraphSchema::SC_StateTransition;
				PinType.ContainerType = bIsArrayField ? EPinContainerType::Array : EPinContainerType::None;

				this->CreatePin(
					EGPD_Output,
					PinType,
					PropIterator->GetName()
				);
			}
	}
}

TArray<FString> UHierarchicalStateNode::GetFieldNamesToIgnore() const
{
	TArray<FString> IgnoreNames = UHierarchicalChildNode::GetFieldNamesToIgnore();
	IgnoreNames.Add("UniqueId");
	return IgnoreNames;
}

UObject* UHierarchicalStateNode::GetFinalizedAssetRecursive() const
{
	//No caching, 
	UObject* OutObject = UHierarchicalChildNode::GetFinalizedAssetRecursive();

	UActorState* OutAsState = Cast< UActorState>(OutObject);
	UActorState* InnerAsState = Cast< UActorState>(GetInnerObject());
	OutAsState->UniqueId = InnerAsState->UniqueId;

	for (UEdGraphPin* Pin : Pins) {
		if (Pin->Direction != EGPD_Output) continue; // only consider output pins
		if (!Pin->LinkedTo.Num()) continue; //only consider pins with actual connections

		FEdGraphPinType PinType = Pin->PinType;

		if (PinType.PinSubCategory != UHierarchicalGraphSchema::SC_StateTransition) continue;

		FProperty* Property = InnerClass->FindPropertyByName(Pin->PinName);

		if (PinType.ContainerType == EPinContainerType::Array) {
			TArray<FActorStateID> StateIDs;

			UHierarchicalArrayNode* ArrayNode = GetDownstreamNode<UHierarchicalArrayNode>(Pin);

			if (ArrayNode == nullptr) continue;

			//get connected child nodes from array node and add respective finalized assets
			for (UEdGraphPin* ArrayPin : ArrayNode->Pins) {
				if (ArrayPin->Direction != EGPD_Output) continue;

				UHierarchicalStateNode* ChildNode = GetDownstreamNode< UHierarchicalStateNode>(ArrayPin);

				if (ChildNode == nullptr) continue;

				UActorState* StateObject = Cast< UActorState>(ChildNode->GetInnerObject());
				StateIDs.Add(StateObject->UniqueId);
			}

			TArray<FActorStateID>* ArrayPointer = Property->ContainerPtrToValuePtr<TArray<FActorStateID>>(OutObject);
			*ArrayPointer = StateIDs;
		}
		else {

			UHierarchicalStateNode* ChildNode = GetDownstreamNode< UHierarchicalStateNode>(Pin);

			FActorStateID* StateIDPointer = Property->ContainerPtrToValuePtr<FActorStateID>(OutObject);

			UActorState* StateObject = Cast< UActorState>(ChildNode->GetInnerObject());

			*StateIDPointer = StateObject->UniqueId;
		}
	}

	return OutObject;
}
