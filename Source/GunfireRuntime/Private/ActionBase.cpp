#include "ActionBase.h"
#include "EActorModifierScope.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UActionBase::UActionBase() {
    this->Scope = EActorModifierScope::Server;
    this->ActionID = 0;
    this->ActionCameraEffectHandleID = -1;
    this->ApplyOnKilled = false;
    this->AllowChildrenClassesToValidate = false;
    this->bStopOnCinematic = false;
}

bool UActionBase::ValidateAction_Implementation(AActor* Actor, AActor* Target) const {
    return false;
}

void UActionBase::SetTarget(AActor* Target) {
}

void UActionBase::SetCause(AActor* Cause) {
}

void UActionBase::OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode) {
}



bool UActionBase::IsActionFinished() const {
    return false;
}

AActor* UActionBase::GetTarget() const {
    return NULL;
}

FHitResult UActionBase::GetHitInfo() const {
    return FHitResult{};
}

TSubclassOf<UDamageType> UActionBase::GetDamageType() const {
    return NULL;
}

AActor* UActionBase::GetCauseOwner() const {
    return NULL;
}

AActor* UActionBase::GetCause() const {
    return NULL;
}

UActionComponent* UActionBase::GetActionComponent() const {
    return NULL;
}

AActor* UActionBase::FireProjectile(AActor* CauseActor, FName SourceSocket, AActor* TargetActor, TSubclassOf<AActor> ProjectileBP, float Speed, bool bOrientTowardsTarget, float AutoArcHeight, float GravityScale) {
    return NULL;
}

void UActionBase::FinishAction() {
}

void UActionBase::DoInstantHitFromAimVector(AActor* CauseActor, const FVector& Start, const FVector& End, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar, FHitResult& OutHit) {
}

void UActionBase::DoInstantHit(AActor* CauseActor, FName SourceSocket, float Range, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar, FHitResult& OutHit) {
}

void UActionBase::ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, FHitResult HitInfo) {
}

bool UActionBase::AllowStopAction_Implementation() {
    return false;
}

bool UActionBase::AllowAction_Implementation(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& InDamageInfo, UActionBase* NewAction) {
    return false;
}

void UActionBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActionBase, ActionID);
    DOREPLIFETIME(UActionBase, DamageInfo);
}


