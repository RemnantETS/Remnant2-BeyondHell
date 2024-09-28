#pragma once
#include "CoreMinimal.h"
#include "AsyncLoadClassesCompleteDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncLoadClassesCompleteDelegate, const TArray<TSoftClassPtr<UObject>>&, Classes);

