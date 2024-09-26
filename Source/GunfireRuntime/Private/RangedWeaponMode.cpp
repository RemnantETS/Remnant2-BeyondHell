#include "RangedWeaponMode.h"

FRangedWeaponMode::FRangedWeaponMode() {
    this->ReadyTime = 0.00f;
    this->Range = 0.00f;
    this->PrimaryFalloff = 0.00f;
    this->SecondaryFalloff = 0.00f;
    this->MinCritRange = 0.00f;
    this->MaxCritRange = 0.00f;
    this->RateOfFire = 0.00f;
    this->RateOfFireAffectsAllFireAnims = false;
    this->BurstCount = 0;
    this->IsAutomatic = false;
    this->RefireWindow = 0.00f;
    this->BurstRateOfFire = 0.00f;
    this->SprayCount = 0.00f;
    this->Reticule = NULL;
    this->HasScope = false;
    this->ScopeFOV = 60.00f;
    this->ScopeReticule = NULL;
    this->ScopeWidget = NULL;
    this->MinimumAimDelayForScope = 0.00f;
    this->DamageType = NULL;
    this->Profile = NULL;
    this->MuzzleFX = NULL;
    this->MergeHitscanHits = false;
    this->AllowReload = false;
    this->ReloadAfterStartLoop = false;
    this->AllowReloadWithNoAmmo = false;
    this->AllowInfiniteClip = false;
    this->RequiredFireEndToRefire = false;
    this->TrajectoryMode = ERangedWeaponTrajectoryMode::Socket;
    this->MuzzleObstructionDistance = 0.00f;
    this->ProjectileToVisualize = NULL;
    this->bAllowCharacterSpreadMods = false;
    this->bAllowCharacterRangeMods = false;
    this->bAllowCharacterAmmoMods = false;
    this->bAllowCharacterSpeedMods = false;
    this->bAllowCharacterSwayMods = false;
    this->bAllowCharacterRecoilMods = false;
    this->bAllowCharacterWindupMods = false;
    this->CachedProfile = NULL;
    this->ScopeMaterial = NULL;
}

