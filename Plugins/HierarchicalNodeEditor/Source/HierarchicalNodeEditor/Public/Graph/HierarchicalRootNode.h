#pragma once

#include "HierarchicalNode_Base.h"
#include "HierarchicalRootNode.generated.h"

UCLASS()
class UHierarchicalRootNode : public UHierarchicalNode_Base {
	GENERATED_BODY()
public:
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(FColor::Green); }
	virtual bool CanUserDeleteNode() const override { return false; }
};