#pragma once
#include "CoreMinimal.h"
#include "EEntitlementPlatform.generated.h"

UENUM(BlueprintType)
enum class EEntitlementPlatform : uint8 {
    Default,
    Steam,
    Epic,
    XboxSeries,
    PS5,
    WinGDK,
};

