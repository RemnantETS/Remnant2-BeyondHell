#pragma once
#include "CoreMinimal.h"
#include "OnFindingSpawnLocationEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFindingSpawnLocationEvent, bool, IsFindingStartLocation);

