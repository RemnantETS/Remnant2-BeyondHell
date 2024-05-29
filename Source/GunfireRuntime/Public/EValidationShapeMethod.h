#pragma once
#include "CoreMinimal.h"
#include "EValidationShapeMethod.generated.h"

UENUM(BlueprintType)
enum class EValidationShapeMethod : uint8 {
    Static,
    ConvergeLoc,
};

