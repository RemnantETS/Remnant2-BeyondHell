#pragma once
#include "CoreMinimal.h"
#include "EEnvQueryCancelBehavior.generated.h"

UENUM(BlueprintType)
enum class EEnvQueryCancelBehavior : uint8 {
    Pause,
    Reset,
};

