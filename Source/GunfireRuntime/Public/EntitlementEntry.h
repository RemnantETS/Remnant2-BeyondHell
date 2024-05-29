#pragma once
#include "CoreMinimal.h"
#include "EEntitlementPlatform.h"
#include "EntitlementId.h"
#include "EntitlementEntry.generated.h"

USTRUCT(BlueprintType)
struct FEntitlementEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEntitlementPlatform Platform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEntitlementId> EntitlementIDs;
    
    GUNFIRERUNTIME_API FEntitlementEntry();
};

