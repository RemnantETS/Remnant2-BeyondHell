#pragma once
#include "CoreMinimal.h"
#include "FloatUserSetting.h"
#include "UpscalerSharpnessUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UUpscalerSharpnessUserSetting : public UFloatUserSetting {
    GENERATED_BODY()
public:
    UUpscalerSharpnessUserSetting();
};

