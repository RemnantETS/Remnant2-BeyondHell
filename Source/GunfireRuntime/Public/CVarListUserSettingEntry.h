#pragma once
#include "CoreMinimal.h"
#include "CVarListValue.h"
#include "ListUserSettingEntry.h"
#include "CVarListUserSettingEntry.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FCVarListUserSettingEntry : public FListUserSettingEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCVarListValue> Values;
    
    FCVarListUserSettingEntry();
};

