#pragma once
#include "CoreMinimal.h"
#include "EPrismSegmentCategory.generated.h"

UENUM(BlueprintType)
enum class EPrismSegmentCategory : uint8 {
    Red,
    Blue,
    Yellow,
    RedRed,
    BlueBlue,
    YellowYellow,
    RedBlue,
    RedYellow,
    BlueYellow,
    None,
};

