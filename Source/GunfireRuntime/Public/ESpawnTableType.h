#pragma once
#include "CoreMinimal.h"
#include "ESpawnTableType.generated.h"

UENUM(BlueprintType)
enum class ESpawnTableType : uint8 {
    List,
    Table,
    TableGroup,
    IndividualChance,
    IndividualChanceOneShot,
    IndividualChanceSpawnOnce,
};

