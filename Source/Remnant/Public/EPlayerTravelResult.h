#pragma once
#include "CoreMinimal.h"
#include "EPlayerTravelResult.generated.h"

UENUM(BlueprintType)
enum class EPlayerTravelResult : uint8 {
    Unknown,
    Success,
    Ignored,
    Ignored_NotServer,
    Ignored_AlreadyTraveling,
    Failure,
    Failure_Timeout,
    Failure_InvalidParameters,
    Failure_NotEntitled,
    Failure_ZoneNotFound,
    Failure_ZoneNotLoaded,
    Failure_ZoneLinkNotFound,
    Failure_ZoneLinkNotLoaded,
    Failure_ZoneLinkMissingComponent,
    Failure_ZoneLinkMissingSpawnPoint,
};

