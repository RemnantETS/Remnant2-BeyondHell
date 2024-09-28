#pragma once
#include "CoreMinimal.h"
#include "DialogEndEventDelegate.generated.h"

class UEventTreeComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogEndEvent, UEventTreeComponent*, Component);

