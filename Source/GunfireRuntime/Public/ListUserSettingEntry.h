#pragma once
#include "CoreMinimal.h"
#include "ListUserSettingEntry.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FListUserSettingEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    FListUserSettingEntry();
};

