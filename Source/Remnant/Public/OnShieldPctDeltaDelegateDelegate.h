#pragma once
#include "CoreMinimal.h"
#include "OnShieldPctDeltaDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShieldPctDeltaDelegate, float, CurrentPct, float, CurrentValue);

