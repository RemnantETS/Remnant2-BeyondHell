#pragma once
#include "CoreMinimal.h"
#include "EEquipmentTarget.generated.h"

UENUM(BlueprintType)
enum class EEquipmentTarget : uint8 {
    BothWeapons,
    ActiveWeapon,
    TargetSlot,
};

