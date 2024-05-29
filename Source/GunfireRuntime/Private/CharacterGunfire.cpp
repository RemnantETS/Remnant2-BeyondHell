#include "CharacterGunfire.h"
#include "ActionComponent.h"
#include "HitLogComponent.h"
#include "Net/UnrealNetwork.h"
#include "ReplicatedMovementComponent.h"
#include "StatsComponent.h"
#include "Templates/SubclassOf.h"
#include "WeaponPhantomComponent.h"

void ACharacterGunfire::StopWeaponPhantom(UPrimitiveComponent* Shape) {
}

void ACharacterGunfire::StopAllWeaponPhantoms() {
}

void ACharacterGunfire::StartWeaponPhantom(FWeaponPhantomInfo& PhantomInfo) {
}

void ACharacterGunfire::SetWeaponPhantomsSuspended(bool bIsSuspended) {
}

void ACharacterGunfire::SetTarget(AActor* Character) {
}

void ACharacterGunfire::SetRagdollFXEnabled(bool bEnabled) {
}

void ACharacterGunfire::SetOldController(APlayerControllerGunfire* OldControllerIn) {
}

void ACharacterGunfire::SetIsTargetable(bool Targetable) {
}

void ACharacterGunfire::SetHealth(float Health) {
}

void ACharacterGunfire::SetFaction(TSubclassOf<UFaction> NewFaction) {
}

void ACharacterGunfire::SetCooldown(FName Cooldown, float Time) {
}

void ACharacterGunfire::SetAllNamesCooldown(float Time) {
}

void ACharacterGunfire::SetAimTarget(AActor* InTarget) {
}

void ACharacterGunfire::ServerSetAimTarget_Implementation(AActor* InTarget) {
}
bool ACharacterGunfire::ServerSetAimTarget_Validate(AActor* InTarget) {
    return true;
}

void ACharacterGunfire::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}

void ACharacterGunfire::RestoreAggroGroup(FName PreviousAggroGroup, bool bRemoveAll) {
}

void ACharacterGunfire::ResetHealth(bool bResetHitLocations) {
}

void ACharacterGunfire::ResetCooldown(FName Cooldown) {
}

void ACharacterGunfire::ResetClothingSimulation(bool FullReset) {
}

void ACharacterGunfire::ResetAllNamesCooldown() {
}

void ACharacterGunfire::RemoveTag(const FName& Tag, bool bRemoveAll) {
}

void ACharacterGunfire::ReinitializeCloth() {
}

bool ACharacterGunfire::ReduceCooldown(FName Cooldown, float Time) {
    return false;
}

void ACharacterGunfire::Ragdoll(const FName RootBoneName) {
}

void ACharacterGunfire::PostComputeStats() {
}

void ACharacterGunfire::OnRep_Target(AActor* PreviousTarget) {
}

void ACharacterGunfire::OnRep_Health() {
}

void ACharacterGunfire::OnRagdollHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}



void ACharacterGunfire::OnGameViewportFocusChanged(bool HasFocus) {
}


void ACharacterGunfire::OnCharacterStateChanged(const FName& StateName, const FName& PreviousStateName) {
}

void ACharacterGunfire::OnCharacterDead_Implementation(EDeadReason Reason, AActor* Cause) {
}

void ACharacterGunfire::ModifyStat(FName Stat, float Value) {
}

void ACharacterGunfire::MarkActorHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) {
}

bool ACharacterGunfire::IsWounded() const {
    return false;
}

bool ACharacterGunfire::IsSceneCaptureCharacter() const {
    return false;
}

bool ACharacterGunfire::IsEditor() {
    return false;
}

bool ACharacterGunfire::IsCinematicCharacter() const {
    return false;
}

bool ACharacterGunfire::IsAlive() const {
    return false;
}

void ACharacterGunfire::HitPause(float Duration, float Dilation, float EaseInTime, float EaseOutTime) {
}

bool ACharacterGunfire::HasRecentlyHitActor(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) const {
    return false;
}

bool ACharacterGunfire::HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const {
    return false;
}

FRotator ACharacterGunfire::GetViewRotation() const {
    return FRotator{};
}

AActor* ACharacterGunfire::GetTarget() {
    return NULL;
}

UStateMachineComponent* ACharacterGunfire::GetStateMachine() const {
    return NULL;
}

float ACharacterGunfire::GetStat(FName Stat) {
    return 0.0f;
}

APlayerControllerGunfire* ACharacterGunfire::GetOldController() const {
    return NULL;
}

bool ACharacterGunfire::GetIsTargetable() {
    return false;
}

FInspectStat ACharacterGunfire::GetInspectStatInfo(const FName& Stat) {
    return FInspectStat{};
}

FInspectInfo ACharacterGunfire::GetInspectInfo() {
    return FInspectInfo{};
}

float ACharacterGunfire::GetHealthPercentage() const {
    return 0.0f;
}

float ACharacterGunfire::GetHealthMax() const {
    return 0.0f;
}

float ACharacterGunfire::GetHealth() const {
    return 0.0f;
}

void ACharacterGunfire::GetEyeViewPointOverride_Implementation(FVector& Location, FRotator& Rotation) const {
}

TArray<AActor*> ACharacterGunfire::GetExtraNotifyTargetsForHit_Implementation(const FDamageInfo& DamageInfo) {
    return TArray<AActor*>();
}

FString ACharacterGunfire::GetDebugInfo(int32 DebugLevel) {
    return TEXT("");
}

float ACharacterGunfire::GetCooldownTotalDuration(FName Cooldown) const {
    return 0.0f;
}

float ACharacterGunfire::GetCooldownPct(FName Cooldown) const {
    return 0.0f;
}

UInventoryComponent* ACharacterGunfire::GetCharacterInventory() const {
    return NULL;
}

AActor* ACharacterGunfire::GetAimTarget() {
    return NULL;
}

FName ACharacterGunfire::GetAggroGroup() {
    return NAME_None;
}

void ACharacterGunfire::FilterIncomingDamage_Implementation(const FDamageInfo& DamageInfo, float& DamageOut, bool& ShouldApplyDamage) {
}

void ACharacterGunfire::EnableClothingSimulation() {
}

void ACharacterGunfire::DisableClothingSimulation() {
}

void ACharacterGunfire::ConsumeEntitlement(TSoftClassPtr<AItem> Entitlement) {
}

void ACharacterGunfire::ComputeStats() {
}

void ACharacterGunfire::ClientNotifyTargetResistedHit_Implementation(const FReplicatedDamageInfo& RepDamageInfo) {
}

void ACharacterGunfire::ClientNotifyTakeDamage_Implementation(AActor* Source, float Damage, int32 Power) {
}

void ACharacterGunfire::ClientNotifyHitEvents_Implementation(const TArray<FReplicatedDamageInfo>& RepDamageInfos) {
}

void ACharacterGunfire::ClientApplyKnockback_Implementation(float ImpactHeading, float KnockBackImpulse, float KnockUpImpulse) {
}

void ACharacterGunfire::ClearAggroGroup() {
}

bool ACharacterGunfire::CheckTags(const TArray<FName>& TagsToCheck, bool AllOrNothing) const {
    return false;
}

bool ACharacterGunfire::CheckTag(FName Tag) const {
    return false;
}

bool ACharacterGunfire::CheckCooldown(FName Cooldown) const {
    return false;
}

bool ACharacterGunfire::AreWeaponPhantomsSuspended() const {
    return false;
}

bool ACharacterGunfire::AreCharacterOptimizationsEnabled() {
    return false;
}

void ACharacterGunfire::ApplyHealthDelta(float Delta) {
}

void ACharacterGunfire::AddTag(const FName& Tag) {
}

void ACharacterGunfire::AddAggroGroup(FName NewAggroGroup, bool bUniqueOnly) {
}

void ACharacterGunfire::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACharacterGunfire, Faction);
    DOREPLIFETIME(ACharacterGunfire, Level);
    DOREPLIFETIME(ACharacterGunfire, Seed);
    DOREPLIFETIME(ACharacterGunfire, InitialCharacterTags);
    DOREPLIFETIME(ACharacterGunfire, HealthNormalized);
    DOREPLIFETIME(ACharacterGunfire, Target);
    DOREPLIFETIME(ACharacterGunfire, AimTarget);
    DOREPLIFETIME(ACharacterGunfire, ConsumedEntitlements);
}

ACharacterGunfire::ACharacterGunfire() {
    this->StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComp"));
    this->ActionComp = CreateDefaultSubobject<UActionComponent>(TEXT("ActionComp"));
    this->WeaponPhantomProviderComp = CreateDefaultSubobject<UWeaponPhantomComponent>(TEXT("WeaponPhantomProviderComp"));
    this->HitLogComp = CreateDefaultSubobject<UHitLogComponent>(TEXT("HitLogComp"));
    this->ReplicatedMovementComp = CreateDefaultSubobject<UReplicatedMovementComponent>(TEXT("ReplicatedMovement"));
    this->InspectStats = NULL;
    this->Faction = NULL;
    this->DefaultDamageType = NULL;
    this->GlobalFootImpactOffset = 0.00f;
    this->ReceiveDecals = EDecalReceiverType::Inherit;
    this->NetNotifyHitTarget = false;
    this->Level = 1;
    this->Seed = 0;
    this->HealthNormalized = 1000.00f;
    this->EnableCharacterOptimizations = false;
    this->EnableAnimOptimizations = true;
    this->EnableAnimSignificanceOptimizations = true;
    this->AnimSignificanceScalar = 1.00f;
    this->SuspendClothWhenNotVisible = true;
    this->UpdateRateDistanceMultiplier = true;
    this->ActivationHalfHeightInflation = 60.00f;
    this->ActivationRadiusInflation = 60.00f;
    this->MinimumTimeDilation = 0.00f;
    this->RemoveNetRepReferencesOnDestroy = true;
    this->CachedStateMachine = NULL;
    this->CachedInventory = NULL;
    this->Target = NULL;
    this->CharacterTarget = NULL;
    this->AimTarget = NULL;
    this->DeathCauseActor = NULL;
    this->OldController = NULL;
    this->bPauseClothSimulationOnTimeDilation = true;
    this->bResetAnimDynamicsOnResumeClothingSim = false;
    this->ClothSimulationPauseThreshold = 0.05f;
    this->CharacterManager = NULL;
}

