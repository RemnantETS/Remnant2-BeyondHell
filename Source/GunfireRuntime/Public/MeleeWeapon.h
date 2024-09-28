#pragma once
#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "MeleeWeapon.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMeleeWeapon : public AWeaponBase {
    GENERATED_BODY()
public:
    AMeleeWeapon(const FObjectInitializer& ObjectInitializer);

};

