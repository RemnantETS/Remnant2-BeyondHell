#pragma once
#include "CoreMinimal.h"
#include "EQuestRecordsActiveState.generated.h"

UENUM(BlueprintType)
enum class EQuestRecordsActiveState : uint8 {
    CurrentlyActive,
    MostRecentlyCached,
};

