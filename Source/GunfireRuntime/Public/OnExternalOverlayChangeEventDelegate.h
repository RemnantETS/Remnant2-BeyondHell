#pragma once
#include "CoreMinimal.h"
#include "OnExternalOverlayChangeEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExternalOverlayChangeEvent, bool, bIsActivating);

