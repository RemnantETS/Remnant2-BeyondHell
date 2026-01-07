#pragma once

#include "HierarchicalNode_Base.h"
#include "HierarchicalChildNode.generated.h"

UCLASS()
class UHierarchicalChildNode : public UHierarchicalNode_Base {
	GENERATED_BODY()
protected:
	virtual void SetUpInputPins() override;
};