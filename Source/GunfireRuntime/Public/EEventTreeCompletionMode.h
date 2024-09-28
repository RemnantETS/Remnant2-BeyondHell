#pragma once
#include "CoreMinimal.h"
#include "EEventTreeCompletionMode.generated.h"

UENUM(BlueprintType)
enum class EEventTreeCompletionMode : uint8 {
    KeepState,
    RestoreStateOnCompletion,
    RestoreStateStomped,
    IgnoreOnStomped,
};

