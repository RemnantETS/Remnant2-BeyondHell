#pragma once
#include "CoreMinimal.h"
#include "EMapGenState.generated.h"

UENUM(BlueprintType)
enum class EMapGenState : uint8 {
    Uninitialized,
    WaitForServer,
    LoadingTemplate,
    LoadingTemplateSubLevels,
    Loading,
    LoadingSubLevels,
    ProcessingInitialTiles,
    Initialized,
    Failed,
};

