#pragma once
#include "CoreMinimal.h"
#include "DialogNodeEventDelegate.generated.h"

class UEventTreeComponent;
class UEventTreeNode;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogNodeEvent, const UEventTreeNode*, Node, UEventTreeComponent*, Component);

