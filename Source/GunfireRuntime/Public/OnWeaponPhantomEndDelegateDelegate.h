#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnWeaponPhantomEndDelegateDelegate.generated.h"

class AActor;
class UDamageTypeGunfire;
class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWeaponPhantomEndDelegate, AActor*, Cause, TSubclassOf<UDamageTypeGunfire>, DamageType, UPrimitiveComponent*, InitialShape);

