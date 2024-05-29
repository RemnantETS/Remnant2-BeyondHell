#include "RemnantWeaponMod.h"

bool ARemnantWeaponMod::ShowReticule_Implementation() {
    return false;
}

void ARemnantWeaponMod::SetMinHoldTime(float HoldTime) {
}

void ARemnantWeaponMod::OnUse_Implementation() {
}


void ARemnantWeaponMod::OnSecondaryActivate_Implementation() {
}

void ARemnantWeaponMod::OnPreviewStart_Implementation() {
}

void ARemnantWeaponMod::OnPreviewEnd_Implementation() {
}

void ARemnantWeaponMod::OnPreFireEnd_Implementation() {
}

void ARemnantWeaponMod::OnPreFireBegin_Implementation() {
}

void ARemnantWeaponMod::OnPreActivate_Implementation() {
}

void ARemnantWeaponMod::OnFireEnd_Implementation() {
}

void ARemnantWeaponMod::OnFireBegin_Implementation() {
}

void ARemnantWeaponMod::OnFire_Implementation(const FVector& From, const FVector& To, float WeaponSpread) {
}

void ARemnantWeaponMod::OnEndUse_Implementation() {
}


void ARemnantWeaponMod::OnDeactivate_Implementation() {
}


void ARemnantWeaponMod::OnCharacterHitTarget(const FDamageInfo& DamageInfo) {
}

void ARemnantWeaponMod::OnBeginUse_Implementation() {
}

void ARemnantWeaponMod::OnActivate_Implementation() {
}

void ARemnantWeaponMod::ModifyModPowerEx(AActor* TargetActor, EEquipmentTarget EquipmentTarget, float Delta, FName TargetSlotNameID) {
}

void ARemnantWeaponMod::ModifyModPower(float Delta) {
}

void ARemnantWeaponMod::ModifyIsSecondaryUse_Implementation(bool& bIsSecondaryUse) {
}

bool ARemnantWeaponMod::IsUseState(FName State) const {
    return false;
}

bool ARemnantWeaponMod::IsPreviewing() const {
    return false;
}

float ARemnantWeaponMod::GetWindupProgress_Implementation(const float TimePassed) const {
    return 0.0f;
}

float ARemnantWeaponMod::GetWindupOverdrawnProgress_Implementation(const float TimePassed) const {
    return 0.0f;
}

TArray<ARemnantWeaponMod*> ARemnantWeaponMod::GetWeaponModsForModTarget(AActor* TargetActor, EEquipmentTarget EquipmentTarget, FName TargetSlotNameID) {
    return TArray<ARemnantWeaponMod*>();
}

ARemnantRangedWeapon* ARemnantWeaponMod::GetWeapon() const {
    return NULL;
}

FName ARemnantWeaponMod::GetUseState() const {
    return NAME_None;
}

float ARemnantWeaponMod::GetPowerBasis() const {
    return 0.0f;
}

FName ARemnantWeaponMod::GetModDeactivateAnimation_Implementation() {
    return NAME_None;
}

float ARemnantWeaponMod::GetModActiveRemainingPct_Implementation() {
    return 0.0f;
}

FName ARemnantWeaponMod::GetModActivateAnimation_Implementation() {
    return NAME_None;
}

int32 ARemnantWeaponMod::GetMaxCharges_Implementation() const {
    return 0;
}

bool ARemnantWeaponMod::GetLastAltFireStateHeld() {
    return false;
}

bool ARemnantWeaponMod::GetClientAimVector(FVector& AimOrigin, FVector& AimEnd) {
    return false;
}

void ARemnantWeaponMod::DoInstantHit(const FVector& Origin, const FVector& End, float WeaponSpread) {
}

bool ARemnantWeaponMod::CanUse_Implementation(bool IsSecondaryActivation) {
    return false;
}

bool ARemnantWeaponMod::CanDeactivateMod_Implementation() {
    return false;
}

bool ARemnantWeaponMod::CanAddModPowerFromDamage_Implementation(const FDamageInfo& DamageInfo) {
    return false;
}

bool ARemnantWeaponMod::CalculateClientAimVector_Implementation(FVector& AimOrigin, FVector& AimEnd) {
    return false;
}

void ARemnantWeaponMod::ApplyDamageInfoToModPower(const FDamageInfo& DamageInfo, float ModPowerScalar, bool bForce, bool bIgnorePenalties, bool bFillActiveMods) {
}

void ARemnantWeaponMod::AddModPowerEx(FAddModPowerParams Params) {
}

void ARemnantWeaponMod::AddModPower_Implementation(float Damage, float BonusModPowerMod, bool bFillActiveMods) {
}

ARemnantWeaponMod::ARemnantWeaponMod() {
    this->PowerBasis = 100.00f;
    this->MaxCharges = 1;
    this->InputMode = EModInputMode::Press;
    this->PreviewAnimTags.AddDefaulted(1);
    this->bStowWeaponForPreview = true;
    this->MinimumHoldTime = 0.20f;
    this->MaximumHoldTime = 0.00f;
    this->bShouldUseChargesDuringWeaponMode = true;
    this->bUseAllChargesOnConsume = false;
    this->NumChargesConsumedOnUse = 1;
    this->WeaponModeHasInfiniteClip = false;
    this->bToggleable = true;
    this->bHasSecondaryAction = false;
    this->bAllowDeactivateIfNotSecondaryUse = false;
    this->bRequiresAllowActionForUse = true;
    this->bBlocksActionsWhileInUse = true;
    this->AllowWeaponModeDuringAction = false;
    this->NoModGenWhileModActive = false;
    this->SkipDeactivateAnimForLastCharge = false;
    this->LoopUseAnimation = false;
    this->bStowWeaponForUseAnimation = false;
}

