#include "ProjectileBase.h"
#include "ActionComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProjectileMovementComponentGunfire.h"
#include "ReplicatedMovementComponent.h"
#include "Templates/SubclassOf.h"

bool AProjectileBase::ValidateHit_Implementation(const FHitResult& Hit, bool bSimulating) {
    return false;
}

void AProjectileBase::StopLoopingFX(float FadeOut) {
}

void AProjectileBase::SetMaxLifeTime(float NewMaxLifeTime) {
}

void AProjectileBase::SetDamageType(TSubclassOf<UDamageTypeGunfire> Type) {
}

bool AProjectileBase::RequiresClientCameraTransform() const {
    return false;
}

void AProjectileBase::OnStop(const FHitResult& Hit) {
}






void AProjectileBase::OnHit(const FHitResult& Hit) {
}

void AProjectileBase::MulticastStop_Implementation() {
}

void AProjectileBase::MulticastLifeSpanExpired_Implementation() {
}

void AProjectileBase::MulticastImpactEffect_Implementation(const FReplicatedHit& ReplicatedHit, bool bFinalHit) {
}

bool AProjectileBase::IsSprayHit_Implementation(const FHitResult& Hit) {
    return false;
}

void AProjectileBase::IncrementNumPenetrations() {
}

UProjectileMovementComponentGunfire* AProjectileBase::GetProjectileMovement() const {
    return NULL;
}

int32 AProjectileBase::GetNumPenetrations() {
    return 0;
}

UShapeComponent* AProjectileBase::GetCollisionShape() const {
    return NULL;
}

bool AProjectileBase::GetClientCameraTransform(FVector& CameraLocation, FRotator& CameraRotation) const {
    return false;
}

TArray<UFXSystemComponent*> AProjectileBase::GatherPooledProjectileComponentsForDeactivation_Implementation() {
    return TArray<UFXSystemComponent*>();
}

void AProjectileBase::FilterIncomingDamage_Implementation(const FDamageInfo& DamageInfo, float& DamageOut, bool& ShouldApplyDamage) {
}

void AProjectileBase::AttachToHitObject(const FHitResult& Hit) {
}

void AProjectileBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AProjectileBase, Cause);
}

AProjectileBase::AProjectileBase() {
    this->Cause = NULL;
    this->MaxLifetime = 10.00f;
    this->PostBounceMaxLifeTime = -1.00f;
    this->Collision = NULL;
    this->ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponentGunfire>(TEXT("ProjectileMovement"));
    this->ProjectileReplication = CreateDefaultSubobject<UReplicatedMovementComponent>(TEXT("ProjectileReplication"));
    this->ActionComp = CreateDefaultSubobject<UActionComponent>(TEXT("Action"));
    this->DestroyAfterImpactEffects = true;
    this->DisableCollisionOnStop = false;
    this->AttachOnHit = false;
    this->OrientPitchToSurfaceOnAttach = false;
    this->AttachIgnoreBones = TEXT("_Head");
    this->TargetCooldownTime = 0.00f;
    this->bDelayDestroyUntilAfterActionsFinish = false;
    this->DestroyBreakables = false;
    this->bIgnorePenetratesOnValidHits = false;
    this->bActivateNearbyCharacters = true;
    this->AdditionalActivateRadius = 200.00f;
    this->ActivateSimulationTime = 0.20f;
    this->ApplyDamage = false;
    this->DamageScalar = 1.00f;
    this->DamageMod = 0.00f;
    this->DamageType = NULL;
    this->PowerOverride = -1;
    this->Evadable = true;
    this->SoftDeactivatePooledFXComponents = false;
    this->bPenetrate = false;
    this->MaxPenetrations = 1;
    this->PenetrateDelay = 0.50f;
    this->PenetrationDamageScalarInitial = 0.50f;
    this->PenetrationDamageScalarIncrement = 1.00f;
    this->CameraShake = NULL;
    this->InnerRadius = 0.00f;
    this->OuterRadius = 0.00f;
    this->Falloff = 1.00f;
    this->LoopFadeInDuration = 0.00f;
    this->ImpactVFX = NULL;
    this->bFFAOE = false;
    this->ForceFeedback = NULL;
    this->FFAttenuationSettings = NULL;
    this->SimulationWorld = NULL;
    this->bIsDamageable = false;
    this->DestroyOnTakeDamage = false;
    this->bHasGroupDoneHit = false;
    this->bRequiresClientCameraTransform = false;
    this->bAlignToClientCameraTransform = false;
}

