#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "ListUserSettingEntry.h"
#include "EnumUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UEnumUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> DisabledValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FListUserSettingEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
public:
    UEnumUserSetting();
    UFUNCTION(BlueprintCallable)
    void EnableValue(int32 InValue);
    
    UFUNCTION(BlueprintCallable)
    void DisableValue(int32 InValue);
    
};

