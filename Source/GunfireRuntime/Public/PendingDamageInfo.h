#pragma once
#include "CoreMinimal.h"
#include "ApplyDamageContextData.h"
#include "DamageInfo.h"
#include "PendingDamageInfo.generated.h"

USTRUCT(BlueprintType)
struct FPendingDamageInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo DamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FApplyDamageContextData ContextData;
    
    GUNFIRERUNTIME_API FPendingDamageInfo();
};

