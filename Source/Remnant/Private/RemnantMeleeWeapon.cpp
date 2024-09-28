#include "RemnantMeleeWeapon.h"
#include "WeaponAffinityComponent.h"

ARemnantMeleeWeapon::ARemnantMeleeWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WeaponAffinity = CreateDefaultSubobject<UWeaponAffinityComponent>(TEXT("WeaponAffinity"));
    this->OverridePower2DamageType = NULL;
}


