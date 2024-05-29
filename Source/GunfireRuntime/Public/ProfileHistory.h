#pragma once
#include "CoreMinimal.h"
#include "ProfileData.h"
#include "ProfileHistory.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FProfileHistory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProfileData> Profiles;
    
    FProfileHistory();
};

