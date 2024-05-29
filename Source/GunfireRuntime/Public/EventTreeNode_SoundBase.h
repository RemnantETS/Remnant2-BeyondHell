#pragma once
#include "CoreMinimal.h"
#include "CameraShotNodeEntryData.h"
#include "EventTreeAttrib.h"
#include "EventTreeNode.h"
#include "EventTreeNode_SoundBase.generated.h"

class UEventTreeComponent;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_SoundBase : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CompleteAfterDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitTimeAfterComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraShotNodeEntryData CameraShotDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> Attributes;
    
    UEventTreeNode_SoundBase();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinishedWaiting(UEventTreeComponent* Component);
    
};

