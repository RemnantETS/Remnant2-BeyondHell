#include "ActorModifier.h"
#include "Net/UnrealNetwork.h"

UActorModifier::UActorModifier() {
    this->Scope = EActorModifierScope::StatsOnly;
    this->Level = 0;
    this->Icon = NULL;
    this->InspectStats = NULL;
    this->Owner = NULL;
    this->StatsComponent = NULL;
}

void UActorModifier::SetOwner(AActor* NewOwner) {
}

void UActorModifier::SetLevel(int32 NewLevel) {
}

void UActorModifier::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}

void UActorModifier::PostComputeStats() {
}




void UActorModifier::OnRep_Level() {
}


void UActorModifier::OnLevelChanged_Implementation() {
}






void UActorModifier::NotifyTakeDamage(const FDamageInfo& DamageInfo) {
}

void UActorModifier::NotifyHitTarget(const FDamageInfo& DamageInfo) {
}

void UActorModifier::ModifyStat(FName Stat, float Value) {
}


void UActorModifier::ModifyIncomingHealing_Implementation(FHealingInfo& Info) {
}

void UActorModifier::ModifyIncomingDamage_Implementation(FDamageInfo& Info) {
}

void UActorModifier::ModifyHealing_Implementation(FHealingInfo& Info) {
}

void UActorModifier::ModifyDamage_Implementation(FDamageInfo& Info) {
}

float UActorModifier::GetStat(FName Stat) {
    return 0.0f;
}

ACharacter* UActorModifier::GetOwningCharacter() const {
    return NULL;
}

AActor* UActorModifier::GetOwner() const {
    return NULL;
}

FInspectInfo UActorModifier::GetInspectInfo(AActor* Actor, int32 InspectLevel) {
    return FInspectInfo{};
}

FString UActorModifier::GetDebugText_Implementation() {
    return TEXT("");
}

void UActorModifier::FilterIncomingHealing_Implementation(FHealingInfo& HealingInfo, float& HealingOut, bool& ShouldApplyHealing) {
}

void UActorModifier::FilterIncomingFallDamage_Implementation(const float& Damage, float& DamageInfoOut, bool& ShouldApplyDamage) {
}

void UActorModifier::FilterIncomingDamage_Implementation(FDamageInfo& DamageInfo, float& DamageOut, bool& ShouldApplyDamage) {
}

void UActorModifier::ComputeStats() {
}

void UActorModifier::ComputeDerivedStats() {
}

void UActorModifier::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorModifier, Level);
}

UWorld* UActorModifier::GetWorld() const
{
    //Return null if the called from the CDO, or if the outer is being destroyed
    if (!HasAnyFlags(RF_ClassDefaultObject) && !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
    {
        //Try to get the world from the owning actor if we have one
        AActor* Outer = GetTypedOuter<AActor>();
        if (Outer != nullptr)
        {
            return Outer->GetWorld();
        }
    }
    //Else return null - the latent action will fail to initialize
    return nullptr;
}
