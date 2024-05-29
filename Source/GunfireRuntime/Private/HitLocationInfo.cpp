#include "HitLocationInfo.h"

FHitLocationInfo::FHitLocationInfo() {
    this->PhysMat = NULL;
    this->bCollisionInitiallyEnabled = false;
    this->DamageScalar = 0.00f;
    this->HealthRatio = 0.00f;
    this->KillOnDestroyed = false;
    this->DebrisOnDestroy = NULL;
    this->bResistSpot = false;
    this->bIsWeakSpot = false;
    this->Destroyed = false;
    this->AoEPriority = 0;
    this->bAoERequiresLoS = false;
    this->DamageTaken = 0.00f;
}

