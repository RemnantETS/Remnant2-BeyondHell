#pragma once
#include "CoreMinimal.h"
#include "EStageAction.h"
#include "EventTreeAttrib.h"
#include "EventTreeNode.h"
#include "EventTreeNode_Stage.generated.h"

class USequencerShotGroup;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Stage : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStageAction Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USequencerShotGroup> SequenceGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnlyTargetInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> Attributes;
    
    UEventTreeNode_Stage();
};

