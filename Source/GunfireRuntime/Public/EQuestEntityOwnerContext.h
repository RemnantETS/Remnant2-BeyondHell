#pragma once
#include "CoreMinimal.h"
#include "EQuestEntityOwnerContext.generated.h"

UENUM(BlueprintType)
enum class EQuestEntityOwnerContext : uint8 {
    Quest,
    Actor,
    NoOverride,
};

