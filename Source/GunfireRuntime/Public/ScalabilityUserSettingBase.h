#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "ScalabilityUserSettingBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UScalabilityUserSettingBase : public UListUserSetting {
    GENERATED_BODY()
public:
    UScalabilityUserSettingBase();
};

