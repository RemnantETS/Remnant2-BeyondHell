#pragma once
#include "CoreMinimal.h"
#include "OnLoadoutLoadedDelegate.generated.h"

class ULoadoutTemplate;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadoutLoaded, ULoadoutTemplate*, Loadout);

