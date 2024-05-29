#pragma once
#include "CoreMinimal.h"
#include "EPerfTimeType.generated.h"

UENUM(BlueprintType)
enum class EPerfTimeType : uint8 {
    Frame,
    Game,
    Render,
    RHI,
    GPU,
    Draws,
    Prims,
    None,
};

