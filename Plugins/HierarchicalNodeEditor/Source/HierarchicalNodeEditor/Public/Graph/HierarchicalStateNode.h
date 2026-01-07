#pragma once

#include "HierarchicalChildNode.h"
#include "HierarchicalStateNode.generated.h"

UCLASS()
class UHierarchicalStateNode : public UHierarchicalChildNode {
	GENERATED_BODY()

public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitelType) const override;
	virtual void OnRenameNode(const FString& NewName) override;
	virtual bool GetCanRenameNode() const override { return true; }

public:
	virtual UObject* GetFinalizedAssetRecursive() const override;

protected:
	virtual void SetUpInputPins() override;
	virtual void SetUpOutputPins() override;
	virtual TArray<FString> GetFieldNamesToIgnore() const override;
};