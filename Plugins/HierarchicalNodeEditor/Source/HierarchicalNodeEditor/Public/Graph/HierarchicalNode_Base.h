#pragma once 

#include "Graph/HNE_Node.h"
#include "Graph/HNE_RerouteNode.h"
#include "HierarchicalNode_Base.generated.h"

UCLASS()
class UHierarchicalNode_Base : public UHNE_Node
{
	GENERATED_BODY()

public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitelType) const override { return FText::FromName(InnerClass->GetFName()); }
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(FColor::Cyan); }
	virtual bool CanUserDeleteNode() const override { return true; }

public:
	virtual void InitializeNode() override;
	UObject* GetInnerObject() const { return InnerObject; }
	virtual UObject* GetFinalizedAssetRecursive() const;
	virtual void SetInnerObject(UObject* InObject);
	virtual void ClearOutPinValues();
	virtual void CopyPinValues(UObject* InObject);

protected:
	virtual void SetUpInputPins() {};
	virtual void SetUpOutputPins();
	virtual TArray<FString> GetFieldNamesToIgnore() const { return TArray<FString>(); }
	virtual TArray<FString> GetFieldNamesToMakeInput() const { return TArray<FString>(); }

	template <typename TargetNodeClass>
	static TargetNodeClass* GetDownstreamNode(UEdGraphPin* InPin);

public:
	UPROPERTY(EditAnywhere)
	UClass* InnerClass = nullptr;

private:
	UPROPERTY()
	UObject* InnerObject = nullptr;
};

template<typename TargetNodeClass>
inline TargetNodeClass* UHierarchicalNode_Base::GetDownstreamNode(UEdGraphPin* InPin)
{
	if (InPin == nullptr) return nullptr;
	if (InPin->LinkedTo.Num() != 1) return nullptr;

	UEdGraphPin* ConnectedPin = *InPin->LinkedTo.begin();
	UEdGraphNode* ConnectedNode = ConnectedPin->GetOwningNode();

	TargetNodeClass* ConnectedAsTarget = Cast< TargetNodeClass>(ConnectedNode);
	if (ConnectedAsTarget != nullptr) return ConnectedAsTarget;

	UHNE_RerouteNode* ConnectedAsReroute = Cast<UHNE_RerouteNode>(ConnectedNode);
	if (ConnectedAsReroute != nullptr) {
		ConnectedPin = ConnectedAsReroute->GetPassThroughPin(ConnectedPin);
		return UHierarchicalNode_Base::GetDownstreamNode<TargetNodeClass>(ConnectedPin);
	}

	return nullptr;
}
