#pragma once

#include "HierarchicalChildNode.h"
#include "HierarchicalTransitionNode.generated.h"

UCLASS()
class UHierarchicalTransitionNode : public UHierarchicalChildNode {
	GENERATED_BODY()

public:
	virtual void SetUpOutputPins() override;
	UObject* GetFinalizedAssetRecursive() const override;
	virtual TArray<FString> GetFieldNamesToIgnore() const override;
};