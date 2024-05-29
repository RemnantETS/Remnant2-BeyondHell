#pragma once
#include "CoreMinimal.h"
#include "ESettingsPlatforms.generated.h"

UENUM()
enum class ESettingsPlatforms : uint8 {
    PC = 0x1,
    XboxSeriesX,
    XboxSeriesS = 0x4,
    PS5 = 0x8,
    SteamDeck = 0x10,
};

