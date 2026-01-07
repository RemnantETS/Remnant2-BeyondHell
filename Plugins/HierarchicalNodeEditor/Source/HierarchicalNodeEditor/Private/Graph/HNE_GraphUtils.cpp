#include "HNE_GraphUtils.h"
#include "Graph/HierarchicalChildNode.h"
#include "HierarchicalEditInterface.h"

#include "ActorState.h"
#include "Graph/HierarchicalStateNode.h"

#include "ActorStateTransition.h"
#include "Graph/HierarchicalTransitionNode.h"

#include "SpawnTableLink.h"
#include "Graph/HierarchicalTableLinkNode.h"

TMap<UClass*, UClass*> AssetClassToNodeClass{
	{UActorState::StaticClass(), UHierarchicalStateNode::StaticClass()},
	{UActorStateTransition::StaticClass(), UHierarchicalTransitionNode::StaticClass()},
	{USpawnTableLink::StaticClass(), UHierarchicalTableLinkNode::StaticClass()}
};

UClass* FHNE_GraphUtils::GetNodeClassForObjectClass(UClass* InClass)
{
	if (!InClass->ImplementsInterface(UHierarchicalEditInterface::StaticClass())) return nullptr;

	bool bHasClassNodeOverride = false;
	UClass** NodeClassPtr = nullptr;


	for (UClass* InnerClassIterator = InClass; InnerClassIterator != nullptr; InnerClassIterator = InnerClassIterator->GetSuperClass()) {

		NodeClassPtr = AssetClassToNodeClass.Find(InnerClassIterator);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *InnerClassIterator->GetName());
		if (NodeClassPtr != nullptr) {
			bHasClassNodeOverride = true;
			UE_LOG(LogTemp, Warning, TEXT("Has Nodeclass override"));
			break;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Check NodeCLass found"))
	UClass* NodeClass = bHasClassNodeOverride ? *NodeClassPtr : UHierarchicalChildNode::StaticClass();

	return NodeClass;
}
