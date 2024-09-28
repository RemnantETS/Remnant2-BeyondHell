#pragma once
#include "CoreMinimal.h"
#include "ERecordType.generated.h"

UENUM(BlueprintType)
enum class ERecordType : uint8 {
    Increment,
    Decrement,
    HighPass,
    LowPass,
};

