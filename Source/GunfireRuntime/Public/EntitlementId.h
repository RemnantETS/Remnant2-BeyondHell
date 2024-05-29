#pragma once
#include "CoreMinimal.h"
#include "EntitlementId.generated.h"

USTRUCT(BlueprintType)
struct FEntitlementId {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ID;
    
    GUNFIRERUNTIME_API FEntitlementId();
};

