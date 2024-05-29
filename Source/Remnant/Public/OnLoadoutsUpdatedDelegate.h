#pragma once
#include "CoreMinimal.h"
#include "OnLoadoutsUpdatedDelegate.generated.h"

class ULoadoutTemplate;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoadoutsUpdated, ULoadoutTemplate*, Loadout, int32, Index);

