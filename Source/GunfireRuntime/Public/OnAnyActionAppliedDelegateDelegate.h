#pragma once
#include "CoreMinimal.h"
#include "OnAnyActionAppliedDelegateDelegate.generated.h"

class UActionBase;
class UActionComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnAnyActionAppliedDelegate, UActionComponent*, ActionComponent, UActionBase*, Action, bool, Reapplied);

