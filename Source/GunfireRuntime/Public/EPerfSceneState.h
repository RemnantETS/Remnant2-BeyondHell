#pragma once
#include "CoreMinimal.h"
#include "EPerfSceneState.generated.h"

UENUM(BlueprintType)
enum class EPerfSceneState : uint8 {
    None,
    Movable,
    Rendered,
    NonRendered,
    Done,
};

