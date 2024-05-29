#pragma once
#include "CoreMinimal.h"
#include "OnAnyActionAppliedEventDelegate.generated.h"

class UActionBase;
class UActionComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAnyActionAppliedEvent, UActionComponent*, ActionComponent, UActionBase*, Action, bool, Reapplied);

