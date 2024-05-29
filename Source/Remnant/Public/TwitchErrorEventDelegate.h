#pragma once
#include "CoreMinimal.h"
#include "TwitchErrorEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTwitchErrorEvent, FText, ErrorText);

