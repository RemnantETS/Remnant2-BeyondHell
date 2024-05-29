#pragma once
#include "CoreMinimal.h"
#include "EScalabilityGroup.generated.h"

UENUM(BlueprintType)
enum class EScalabilityGroup : uint8 {
    ShadowQuality,
    PostProcessing,
    FoliageQuality,
    EffectsQuality,
    ViewDistanceQuality,
};

