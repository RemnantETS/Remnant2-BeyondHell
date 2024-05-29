#pragma once
#include "CoreMinimal.h"
#include "EMatchmakingPlatform.generated.h"

UENUM()
enum class EMatchmakingPlatform : uint8 {
    Steam = 0x1,
    Epic,
    XBox = 0x4,
    Playstation = 0x8,
    Windows = 0x10,
};

