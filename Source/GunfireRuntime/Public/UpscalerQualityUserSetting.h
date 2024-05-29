#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "UpscalerQualityUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UUpscalerQualityUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UUpscalerQualityUserSetting();
};

