#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "UpscalerUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UUpscalerUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UUpscalerUserSetting();
};

