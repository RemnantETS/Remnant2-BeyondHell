#pragma once
#include "CoreMinimal.h"
#include "WeaponPhantomInfo.h"
#include "OnWeaponPhantomBeginDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponPhantomBeginDelegate, const FWeaponPhantomInfo&, PhantomInfo);

