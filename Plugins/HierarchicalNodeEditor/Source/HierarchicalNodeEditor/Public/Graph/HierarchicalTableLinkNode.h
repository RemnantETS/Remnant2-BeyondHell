#pragma once

#include "HierarchicalChildNode.h"
#include "HierarchicalTableLinkNode.generated.h"

UCLASS()
class UHierarchicalTableLinkNode : public UHierarchicalChildNode {
	GENERATED_BODY()

protected:
	virtual TArray<FString> GetFieldNamesToIgnore() const override;
};