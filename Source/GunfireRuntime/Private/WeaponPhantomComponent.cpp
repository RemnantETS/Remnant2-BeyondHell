#include "WeaponPhantomComponent.h"

void UWeaponPhantomComponent::StopWeaponPhantom(UPrimitiveComponent* Shape) {
}

void UWeaponPhantomComponent::StopAllWeaponPhantoms() {
}

void UWeaponPhantomComponent::StartWeaponPhantom(const FWeaponPhantomInfo& PhantomInfo) {
}

void UWeaponPhantomComponent::ServerApplyDamage_Implementation(const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit) {
}
bool UWeaponPhantomComponent::ServerApplyDamage_Validate(const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit) {
    return true;
}

void UWeaponPhantomComponent::ServerApplyClientValidatedDamage_Implementation(UWeaponPhantomComponent* Component, const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit, bool bEvaded, bool bWasEvadeCounter, const UObject* EvadeSource) {
}
bool UWeaponPhantomComponent::ServerApplyClientValidatedDamage_Validate(UWeaponPhantomComponent* Component, const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit, bool bEvaded, bool bWasEvadeCounter, const UObject* EvadeSource) {
    return true;
}

void UWeaponPhantomComponent::MarkActorHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) {
}

void UWeaponPhantomComponent::Ignore(UPrimitiveComponent* Shape, AActor* ActorToIgnore) {
}

bool UWeaponPhantomComponent::HasRecentlyHitActor(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) const {
    return false;
}

bool UWeaponPhantomComponent::HasGroupRecentlyHitActor(UObject* WorldContextObject, FName GroupName, AActor* Actor) const {
    return false;
}

bool UWeaponPhantomComponent::HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const {
    return false;
}

bool UWeaponPhantomComponent::DoHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, FHitResult& HitResult) {
    return false;
}

void UWeaponPhantomComponent::ApplyPersistentGroupCooldown(AActor* Actor, float HitCooldown, FName GroupName) {
}

UWeaponPhantomComponent::UWeaponPhantomComponent() {
    this->DefaultDamageType = NULL;
    this->DefaultHitCooldown = -1.00f;
    this->DefaultWeaponDamage = 0.00f;
    this->ReplicationMode = EWeaponPhantomReplicationMode::ClientAuthoritative;
    this->bSkipLagSupersampling = false;
    this->bSkipEnvironmentHits = false;
    this->bAllowEnvironmentHitsAfterEvades = false;
    this->bSkipWallChecks = true;
    this->bDoHitPause = true;
    this->bPausePhantomsDuringHitPause = false;
    this->MaxHitPauses = 3;
    this->HitPausePenalty = 0.50f;
}

