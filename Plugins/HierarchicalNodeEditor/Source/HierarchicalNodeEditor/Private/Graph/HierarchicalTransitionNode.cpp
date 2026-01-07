#include "HierarchicalTransitionNode.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HierarchicalStateNode.h"
#include "Graph/HierarchicalArrayNode.h"
#include "ActorStateID.h"
#include "ActorState.h"

void UHierarchicalTransitionNode::SetUpOutputPins()
{
	UHierarchicalChildNode::SetUpOutputPins();

	FEdGraphPinType PinType;
	PinType.PinSubCategory = UHierarchicalGraphSchema::SC_StateTransition;
	PinType.ContainerType = EPinContainerType::None;

	this->CreatePin(
		EGPD_Output,
		PinType,
		FName("DestinationStateID")
	);
}

UObject* UHierarchicalTransitionNode::GetFinalizedAssetRecursive() const
{

	//No caching, 
	UObject* OutObject = UHierarchicalChildNode::GetFinalizedAssetRecursive();

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

TArray<FString> UHierarchicalTransitionNode::GetFieldNamesToIgnore() const
{
	TArray<FString> IgnoreNames = UHierarchicalChildNode::GetFieldNamesToIgnore();
	IgnoreNames.Add("CachedState");
	return IgnoreNames;
}
