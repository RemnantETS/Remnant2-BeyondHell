#pragma once
#include "CoreMinimal.h"
#include "MeleeWeapon.h"
#include "Templates/SubclassOf.h"
#include "RemnantMeleeWeapon.generated.h"

class UDamageTypeGunfire;
class UWeaponAffinityComponent;

UCLASS(Blueprintable)
class REMNANT_API ARemnantMeleeWeapon : public AMeleeWeapon {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponAffinityComponent* WeaponAffinity;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> OverridePower2DamageType;
    
    ARemnantMeleeWeapon(const FObjectInitializer& ObjectInitializer);

};

