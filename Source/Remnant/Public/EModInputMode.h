#pragma once
#include "CoreMinimal.h"
#include "EModInputMode.generated.h"

UENUM(BlueprintType)
enum class EModInputMode : uint8 {
    Press,
    Release,
    QuickReleaseAndHold,
};

