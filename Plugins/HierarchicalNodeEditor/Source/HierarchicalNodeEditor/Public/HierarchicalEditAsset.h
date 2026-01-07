#pragma once

#include "CoreMinimal.h"
#include "HierarchicalEditAsset.generated.h"

USTRUCT()
struct FAssetTargetInfo {
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, meta = (ToolTip = "The asset to edit. If set to None, prompts creation of a new asset on compilation."))
	UObject* OutAsset = nullptr;
};

UCLASS(BlueprintType)
class HIERARCHICALNODEEDITOR_API UHierarchicalEditAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	class UEdGraph* WorkingGraph;

	UPROPERTY(EditAnywhere)
	FAssetTargetInfo TargetInfo;

public:
	void CompileGraphToAsset();
	bool ValidateInputPins(UEdGraph* Graph);
};
