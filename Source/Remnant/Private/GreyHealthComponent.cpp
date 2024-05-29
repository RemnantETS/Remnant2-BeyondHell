#include "GreyHealthComponent.h"
#include "Net/UnrealNetwork.h"

void UGreyHealthComponent::Reset(float InitialValue, bool Notify) {
}

void UGreyHealthComponent::OnRep_GreyHealth(const TArray<float>& PreviousSegments) {
}

void UGreyHealthComponent::OnPostComputeStats() {
}

void UGreyHealthComponent::OnOwnerHealthRegen(ACharacterGunfire* Character, float RegenAmount) {
}

void UGreyHealthComponent::OnOwnerHealed(const FHealingInfo& HealingInfo) {
}

void UGreyHealthComponent::OnOwnerDamageTaken(const FDamageInfo& DamageInfo) {
}

bool UGreyHealthComponent::IsGreyHealthDisabled() const {
    return false;
}

int32 UGreyHealthComponent::GetNumSegments() const {
    return 0;
}

int32 UGreyHealthComponent::GetMaxSegments() const {
    return 0;
}

float UGreyHealthComponent::GetHealableGreyHealth() const {
    return 0.0f;
}

UGreyHealthComponent* UGreyHealthComponent::GetGreyHealthComponent(AActor* Actor) {
    return NULL;
}

float UGreyHealthComponent::GetGreyHealth() const {
    return 0.0f;
}

float UGreyHealthComponent::GetForcedGreyHealthPercent() const {
    return 0.0f;
}

FString UGreyHealthComponent::GetDebugInfo(int32 DebugLevel) {
    return TEXT("");
}

bool UGreyHealthComponent::CanRegenHealth_Implementation() {
    return false;
}

void UGreyHealthComponent::ApplyDeltaReplicated_Implementation(float Delta) {
}

void UGreyHealthComponent::ApplyDelta(float Delta) {
}

void UGreyHealthComponent::Append(float AppendAmount, bool CreateNewSegment, bool Notify) {
}

void UGreyHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UGreyHealthComponent, GreyHealthSegments);
}

UGreyHealthComponent::UGreyHealthComponent() {
    this->InitialGreyhealthSegments = 1;
    this->TimeThresholdForMultiHitGrouping = 0.10f;
    this->TimeAfterHitForRegenStart = 0.20f;
    this->GreyHealthDisabled = false;
}

