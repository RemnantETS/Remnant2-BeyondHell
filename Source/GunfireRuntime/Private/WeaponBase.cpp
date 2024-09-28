#include "WeaponBase.h"

AWeaponBase::AWeaponBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageType = NULL;
}

float AWeaponBase::GetProcChance() const {
    return 0.0f;
}

FImpactEffectDescriptor AWeaponBase::GetImpactEffect_Implementation() {
    return FImpactEffectDescriptor{};
}

float AWeaponBase::GetAttackSpeed() {
    return 0.0f;
}

void AWeaponBase::ComputeDamage(AActor* Actor, float& Damage, float& AttackRating) {
}

bool AWeaponBase::AttemptProc(float BonusChance) const {
    return false;
}


