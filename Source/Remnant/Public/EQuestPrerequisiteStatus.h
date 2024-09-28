#pragma once
#include "CoreMinimal.h"
#include "EQuestPrerequisiteStatus.generated.h"

UENUM(BlueprintType)
enum class EQuestPrerequisiteStatus : uint8 {
    NotRequired,
    Required,
    Ready,
    Loaded,
    Failed,
};

