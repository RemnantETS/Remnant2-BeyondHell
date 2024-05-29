#pragma once
#include "CoreMinimal.h"
#include "UserSetting.h"
#include "ListUserSetting.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UListUserSetting : public UUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWraps;
    
    UListUserSetting();
    UFUNCTION(BlueprintCallable)
    void SetValue(int32 ValueIn);
    
    UFUNCTION(BlueprintCallable)
    bool SetNextEntry(bool bForwards);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetValue() const;
    
};

