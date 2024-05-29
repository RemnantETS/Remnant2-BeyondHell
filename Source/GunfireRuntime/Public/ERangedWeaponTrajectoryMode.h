#pragma once
#include "CoreMinimal.h"
#include "ERangedWeaponTrajectoryMode.generated.h"

UENUM(BlueprintType)
enum class ERangedWeaponTrajectoryMode : uint8 {
    Socket,
    SocketToAimTarget,
    SocketToAimTargetIgnoreCharacters,
    Camera,
};

