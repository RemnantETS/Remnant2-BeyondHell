#pragma once
#include "CoreMinimal.h"
#include "EBROptionCategory.generated.h"

UENUM(BlueprintType)
enum class EBROptionCategory : uint8 {
    Damage,
    Util,
    Defense,
    None,
};

