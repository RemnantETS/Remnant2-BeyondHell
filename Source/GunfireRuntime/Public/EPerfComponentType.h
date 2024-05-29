#pragma once
#include "CoreMinimal.h"
#include "EPerfComponentType.generated.h"

UENUM(BlueprintType)
enum class EPerfComponentType : uint8 {
    Baseline,
    Decal,
    Skeletal,
    Spline,
    Mesh,
    Nanite,
    Foliage,
    Lighting,
    VFX,
    None,
};

