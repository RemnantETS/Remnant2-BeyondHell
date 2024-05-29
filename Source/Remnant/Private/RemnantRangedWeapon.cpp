#include "RemnantRangedWeapon.h"
#include "WeaponAffinityComponent.h"
#include "Net/UnrealNetwork.h"

void ARemnantRangedWeapon::UseMod() {
}

void ARemnantRangedWeapon::UseCharges(int32 NumCharges) {
}

void ARemnantRangedWeapon::UseCharge() {
}

void ARemnantRangedWeapon::UseAllCharges() {
}

bool ARemnantRangedWeapon::ShouldModCancelUse() const {
    return false;
}

void ARemnantRangedWeapon::SetOverrideWeaponModeFromMod() {
}

void ARemnantRangedWeapon::SetModActive(EModActiveState ModState, int32 ActionID, bool bForceNotify) {
}

void ARemnantRangedWeapon::SetIgnoreWindUp(bool Ignore) {
}

void ARemnantRangedWeapon::ServerUseWithAim_Implementation(FVector_NetQuantize AimOrigin, FVector_NetQuantize AimEnd, bool bAltFireHeld) {
}
bool ARemnantRangedWeapon::ServerUseWithAim_Validate(FVector_NetQuantize AimOrigin, FVector_NetQuantize AimEnd, bool bAltFireHeld) {
    return true;
}

void ARemnantRangedWeapon::ServerUseHeld_Implementation() {
}
bool ARemnantRangedWeapon::ServerUseHeld_Validate() {
    return true;
}

void ARemnantRangedWeapon::ServerUse_Implementation() {
}
bool ARemnantRangedWeapon::ServerUse_Validate() {
    return true;
}

void ARemnantRangedWeapon::OnRep_Power() {
}

void ARemnantRangedWeapon::OnRep_ModActive() {
}

void ARemnantRangedWeapon::OnRep_Charges() {
}

void ARemnantRangedWeapon::OnFinishWeaponModeAnimation() {
}

void ARemnantRangedWeapon::OnFinishUseState(const FName& StateName, const FName& PreviousStateName) {
}

void ARemnantRangedWeapon::OnFinishUseAnimation() {
}

void ARemnantRangedWeapon::OnAltFireReleased() {
}

void ARemnantRangedWeapon::OnAltFirePressed() {
}

void ARemnantRangedWeapon::OnActivateSecondary_Implementation() {
}

void ARemnantRangedWeapon::OnActivate_Implementation() {
}

void ARemnantRangedWeapon::OnActionRemoved(UActionBase* Action) {
}

void ARemnantRangedWeapon::MulticastUse_Implementation() {
}

bool ARemnantRangedWeapon::IsModSecondaryUse() const {
    return false;
}

bool ARemnantRangedWeapon::IsModActive() const {
    return false;
}

bool ARemnantRangedWeapon::HasCharges() const {
    return false;
}

ARemnantWeaponMod* ARemnantRangedWeapon::GetWeaponMod() const {
    return NULL;
}

float ARemnantRangedWeapon::GetPower() const {
    return 0.0f;
}

EModActiveState ARemnantRangedWeapon::GetModActiveState() const {
    return EModActiveState::NotActive;
}

float ARemnantRangedWeapon::GetModActiveRemainingPct() const {
    return 0.0f;
}

uint8 ARemnantRangedWeapon::GetCharges() const {
    return 0;
}

void ARemnantRangedWeapon::EndUseAnimation() {
}

void ARemnantRangedWeapon::DelayedDeactivate() {
}

void ARemnantRangedWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantRangedWeapon, Power);
    DOREPLIFETIME(ARemnantRangedWeapon, Charges);
    DOREPLIFETIME(ARemnantRangedWeapon, ActiveState);
    DOREPLIFETIME(ARemnantRangedWeapon, ActiveModActionID);
}

ARemnantRangedWeapon::ARemnantRangedWeapon() {
    this->DefaultMod = NULL;
    this->WeaponAffinity = CreateDefaultSubobject<UWeaponAffinityComponent>(TEXT("WeaponAffinity"));
    this->bResetAmmoOnEquip = true;
    this->AltFireInputAction = NULL;
    this->Power = 0.00f;
    this->Charges = 0;
    this->PassiveModPowerRegenFrequency = 1.00f;
    this->IgnoreWindUp = false;
    this->ActiveState = EModActiveState::NotActive;
    this->ActiveModActionID = 0;
    this->AdditionalRadius = 0.00f;
    this->AdditionalDistance = 0.00f;
}

