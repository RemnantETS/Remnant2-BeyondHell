#pragma once
#include "CoreMinimal.h"
#include "TwitchConnectionEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTwitchConnectionEvent, bool, Connected);

