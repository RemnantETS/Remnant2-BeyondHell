#include "WeaponPhantomInfo.h"

FWeaponPhantomInfo::FWeaponPhantomInfo() {
    this->InitialShape = NULL;
    this->Cause = NULL;
    this->DamageType = NULL;
    this->ImpactDirection = NULL;
    this->EffectSpawnDirection = EEffectSpawnDirection::ImpactNormal;
    this->DamageMod = 0.00f;
    this->DamageScalar = 0.00f;
    this->Blockable = false;
    this->Evadable = false;
    this->PowerOverride = 0;
    this->HitCooldown = 0.00f;
    this->GroupPriority = 0;
    this->bPersistentCooldown = false;
    this->IgnoreEnvironmentHits = false;
    this->IgnoreLagSupersampling = false;
    this->bIgnoreDistanceChecks = false;
    this->CollisionCheckMethod = EWeaponPhantomCollisionCheckMethod::ClosestPoint;
    this->CollisionCheckRadius = 0.00f;
    this->bServerOnlySimulation = false;
}

