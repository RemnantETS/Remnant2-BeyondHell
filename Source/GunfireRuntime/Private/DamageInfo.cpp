#include "DamageInfo.h"

FDamageInfo::FDamageInfo() {
    this->DamageType = NULL;
    this->Damage = 0.00f;
    this->AbsorbedDamage = 0.00f;
    this->DamageMod = 0.00f;
    this->DamageScalar = 1.00f;
    this->ImpactScalar = 1.00f;
    this->CritChance = 0.00f;
    this->CritDamageMod = 0.00f;
    this->WeakSpotDamageMod = 0.00f;
    this->PowerOverride = -1;
    this->DifficultyDamageScalar = 1.00f;
    this->UnmodifiedDamage = 0.00f;
    this->HealthDelta = 0.00f;
    this->SprayCount = 1;
    this->TotalSprayCount = 1;
    this->NoImpacts = false;
    this->SecondaryDamage = false;
    this->Critical = false;
    this->AllowsCrits = true;
    this->WeakSpot = false;
    this->AllowsWeakSpots = true;
    this->Resisted = false;
    this->HitLocationDestroyed = false;
    this->Wounded = false;
    this->Killed = false;
    this->Blockable = true;
    this->Evadable = true;
    this->Blocked = false;
    this->BlockCounter = false;
    this->Evaded = false;
    this->Spray = false;
    this->IgnoreRange = false;
    this->ConvertDamageToSecondaryHealthPool = false;
    this->Victims = 0;
}

