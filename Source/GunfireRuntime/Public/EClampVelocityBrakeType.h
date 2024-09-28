#pragma once
#include "CoreMinimal.h"
#include "EClampVelocityBrakeType.generated.h"

UENUM(BlueprintType)
enum class EClampVelocityBrakeType : uint8 {
    Full,
    Horizontal,
    Vertical,
};

