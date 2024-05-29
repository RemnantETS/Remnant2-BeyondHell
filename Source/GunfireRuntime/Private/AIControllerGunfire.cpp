#include "AIControllerGunfire.h"
#include "AIDefaultTargetSelector.h"
#include "CharacterGunfire.h"
#include "Templates/SubclassOf.h"

void AAIControllerGunfire::UpdateAwareness(float DeltaSeconds) {
}

void AAIControllerGunfire::UnlockCurrentTarget() {
}

bool AAIControllerGunfire::TestPathTo(const FVector& Location) {
    return false;
}

void AAIControllerGunfire::SetTargetSelector(TSubclassOf<UAITargetSelector> NewTargetSelector, bool bUpdateTarget) {
}

void AAIControllerGunfire::SetSpawnLocation(FVector SpawnLocation) {
}

void AAIControllerGunfire::SetRelevantActorFilterClass(TSubclassOf<AActor> FilterClass) {
}

void AAIControllerGunfire::SetNavigationFilter(TSubclassOf<UNavigationQueryFilter> NavFilter) {
}

void AAIControllerGunfire::SetCurrentTarget(AActor* Actor, bool bLockOn) {
}

void AAIControllerGunfire::SendAwarenessSignal(EAwarenessSignal Type, AActor* Source, const FVector& Position, float Radius, bool UseSourceForLastKnownPosition, bool bApplySightRangeBonus) {
}

void AAIControllerGunfire::ResetThreat() {
}

void AAIControllerGunfire::ResetAwareness() {
}

void AAIControllerGunfire::OnSetTacticalPoint_Implementation(const FAITacticalPoint& NewTacticalPoint) {
}

void AAIControllerGunfire::OnFactionChanged(ACharacterGunfire* InCharacter) {
}

void AAIControllerGunfire::OnClearTacticalPoint_Implementation() {
}

void AAIControllerGunfire::LockCurrentTarget() {
}

AActor* AAIControllerGunfire::K2_GetBestTarget(TSubclassOf<UAITargetSelector> Selector) {
    return NULL;
}

bool AAIControllerGunfire::IsTargetLocked() const {
    return false;
}

bool AAIControllerGunfire::IsActorCurrentlyRelevant(AActor* TestActor) const {
    return false;
}

bool AAIControllerGunfire::HasLineOfSightToAnyPlayer() const {
    return false;
}

bool AAIControllerGunfire::HasLineOfSight(AActor* Actor) const {
    return false;
}

AActor* AAIControllerGunfire::GetThreatLeader() const {
    return NULL;
}

bool AAIControllerGunfire::GetTargetChangedThisFrame() const {
    return false;
}

bool AAIControllerGunfire::GetTacticalPointValid() {
    return false;
}

FAITacticalPoint AAIControllerGunfire::GetTacticalPoint() const {
    return FAITacticalPoint{};
}

AActor* AAIControllerGunfire::GetPathTarget(FVector& TargetPos, FName PathTargetName) const {
    return NULL;
}

AAIPathPoint* AAIControllerGunfire::GetPathPoint() const {
    return NULL;
}

TArray<AAIControllerGunfire*> AAIControllerGunfire::GetNearbyAI(const UObject* WorldContextObject, FVector Origin, float Radius, TArray<AAIControllerGunfire*> IgnoreList) {
    return TArray<AAIControllerGunfire*>();
}

TSubclassOf<UNavigationQueryFilter> AAIControllerGunfire::GetNavigationFilter() {
    return NULL;
}

TEnumAsByte<EPathFollowingResult::Type> AAIControllerGunfire::GetLastPathFollowingCode() const {
    return EPathFollowingResult::Success;
}

TSubclassOf<UAITargetSelector> AAIControllerGunfire::GetCurrentTargetSelector() const {
    return NULL;
}

AActor* AAIControllerGunfire::GetCurrentTarget() const {
    return NULL;
}

void AAIControllerGunfire::AddThreat(AActor* ThreatCharacter, float Amount, bool bApplySightRangeBonus) {
}

void AAIControllerGunfire::AddPersistentTarget(AActor* Target) {
}

AAIControllerGunfire::AAIControllerGunfire() {
    this->bSeeksTargets = true;
    this->Persistent = false;
    this->SightRange = 2000.00f;
    this->SightAngle = 180.00f;
    this->LostSightRange = 4000.00f;
    this->BonusLostSightRange = 500.00f;
    this->NearSightRange = 300.00f;
    this->bNearSightRequiresLoS = true;
    this->SphereLOSRadius = 10.00f;
    this->SphereLOFRadius = 10.00f;
    this->HearingScalar = 1.00f;
    this->HearingOcclusionScalar = 0.75f;
    this->ThreatWindow = 45.00f;
    this->ThreatBonus = 0.75f;
    this->AlertTimeout = 60.00f;
    this->AlertGiveUpDistance = 100.00f;
    this->AlertGiveUpTimeout = 10.00f;
    this->AwareDistanceThreshold = 300.00f;
    this->AwarePulseRadius = 500.00f;
    this->EvaluateFriendlyTargets = false;
    this->PlayerRelevancy = EPlayerRelevancyMode::None;
    this->ForceEvaluatePlayers = false;
    this->PathToLastKnownPosition = false;
    this->PerceptionScalar = 1.00f;
    this->CoverAimAdjustDistance = 70.00f;
    this->DefaultTargetSelector = UAIDefaultTargetSelector::StaticClass();
    this->CurrentTargetSelector = NULL;
    this->NodePathStatus = ENodePathStatus::Idle;
    this->OverridenByCinematic = false;
    this->RelevantActorClass = ACharacterGunfire::StaticClass();
    this->TacticalPointIsValid = false;
    this->PathToActor = NULL;
    this->PathPoint = NULL;
}

