#pragma once
#include "CoreMinimal.h"
#include "EMVPCompareRule.generated.h"

UENUM(BlueprintType)
enum class EMVPCompareRule : uint8 {
    Higher,
    Lower,
    LowerAllowZero,
};

