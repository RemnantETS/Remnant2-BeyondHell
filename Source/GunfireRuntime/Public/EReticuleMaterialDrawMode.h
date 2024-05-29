#pragma once
#include "CoreMinimal.h"
#include "EReticuleMaterialDrawMode.generated.h"

UENUM(BlueprintType)
enum class EReticuleMaterialDrawMode : uint8 {
    FillRadius,
    FixedSize,
    InnerRadius,
};

