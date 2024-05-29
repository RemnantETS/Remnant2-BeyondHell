#include "HitLogComponent.h"
#include "Net/UnrealNetwork.h"

void UHitLogComponent::ResetAllHitLocationHealth() {
}

void UHitLogComponent::RepairHitLocation(FName HitLocationName) {
}

void UHitLogComponent::OnRep_LastHitLocation() {
}

void UHitLogComponent::OnRep_DestroyedFlags() {
}

bool UHitLogComponent::IsMaterialWeakspot(UPhysicalMaterial* PhysicsMaterial) {
    return false;
}

bool UHitLogComponent::IsMaterialResisted(UPhysicalMaterial* PhysicsMaterial) {
    return false;
}

UPhysicalMaterial* UHitLogComponent::GetMaterialForHitLocation(FName HitLocation) {
    return NULL;
}

FDamageInfo UHitLogComponent::GetLastHitInfo() {
    return FDamageInfo{};
}

FDamageInfo UHitLogComponent::GetLastDamageInfo() {
    return FDamageInfo{};
}

float UHitLogComponent::GetImpactDamageForHitLocation(const FDateTime& Time, const FName& HitLocation, bool bIgnoreImpactScalar) {
    return 0.0f;
}

float UHitLogComponent::GetDamageScalarForMaterial(UPhysicalMaterial* PhysicsMaterial) {
    return 0.0f;
}

float UHitLogComponent::GetDamageForHitLocation(const FDateTime& Time, const FName& HitLocation) {
    return 0.0f;
}

float UHitLogComponent::GetDamage(const FDateTime& Time) {
    return 0.0f;
}

void UHitLogComponent::DeactivateHitLocation(FName HitLocationName) {
}

void UHitLogComponent::ClearHitLog() {
}

void UHitLogComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UHitLogComponent, RepDestroyedFlags);
    DOREPLIFETIME(UHitLogComponent, LastHitLocation);
}

UHitLogComponent::UHitLogComponent() {
    this->WeakSpotDamageScalar = 1.50f;
    this->ResistSpotDamageScalar = 0.50f;
    this->RepDestroyedFlags = 0;
    this->LastHitLocation = 0;
    this->AnimInstance = NULL;
}

