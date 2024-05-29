#pragma once
#include "CoreMinimal.h"
#include "OnRootVariableContextCreatedDelegate.generated.h"

class URootVariableContext;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRootVariableContextCreated, URootVariableContext*, NewContext);

