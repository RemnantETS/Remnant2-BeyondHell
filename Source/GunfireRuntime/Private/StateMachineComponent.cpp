#include "StateMachineComponent.h"
#include "Net/UnrealNetwork.h"

void UStateMachineComponent::SetWindow(const FName& Name) {
}

void UStateMachineComponent::SetEvent(const FName& Name) {
}

void UStateMachineComponent::ServerSetTraversalState_Implementation(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck) {
}
bool UStateMachineComponent::ServerSetTraversalState_Validate(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck) {
    return true;
}

void UStateMachineComponent::ServerSetState_Implementation(FStateID StateID, float LockDirection, uint8 CurrentClientAck) {
}
bool UStateMachineComponent::ServerSetState_Validate(FStateID StateID, float LockDirection, uint8 CurrentClientAck) {
    return true;
}

void UStateMachineComponent::ServerSetLadder_Implementation(const FLadderReference& LadderReference) {
}
bool UStateMachineComponent::ServerSetLadder_Validate(const FLadderReference& LadderReference) {
    return true;
}

void UStateMachineComponent::ServerSetInteractiveResult_Implementation(EInteractiveResult State, float MashValue) {
}
bool UStateMachineComponent::ServerSetInteractiveResult_Validate(EInteractiveResult State, float MashValue) {
    return true;
}

void UStateMachineComponent::ServerSetClimbingState_Implementation(FStateID StateID, const FClimbableSurfaceResult& ClimbableSurface, uint8 CurrentClientAck) {
}
bool UStateMachineComponent::ServerSetClimbingState_Validate(FStateID StateID, const FClimbableSurfaceResult& ClimbableSurface, uint8 CurrentClientAck) {
    return true;
}

void UStateMachineComponent::ServerResendInteractive_Implementation(uint16 StateChangeID) {
}
bool UStateMachineComponent::ServerResendInteractive_Validate(uint16 StateChangeID) {
    return true;
}

void UStateMachineComponent::ServerDoInteractive_Implementation(const FName& NameID, AActor* Other, bool bOnlyIfValid) {
}
bool UStateMachineComponent::ServerDoInteractive_Validate(const FName& NameID, AActor* Other, bool bOnlyIfValid) {
    return true;
}

bool UStateMachineComponent::ResetStateToDefault(bool bOnlySetIfValid) {
    return false;
}

void UStateMachineComponent::OnRep_CurrentStateInfo() {
}

void UStateMachineComponent::OnPostComputeStats() {
}

void UStateMachineComponent::MulticastDoFlinchWithHitLocationIgnoreClient_Implementation(UHitReactionState* HitReaction, const FName& HitLocation) {
}

void UStateMachineComponent::MulticastDoFlinchWithHitLocation_Implementation(UHitReactionState* HitReaction, const FName& HitLocation) {
}

void UStateMachineComponent::MulticastDoFlinchIgnoreClient_Implementation(UHitReactionState* HitReaction) {
}

void UStateMachineComponent::MulticastDoFlinch_Implementation(UHitReactionState* HitReaction) {
}

bool UStateMachineComponent::K2_SetState(FName NameID, bool bOnlySetIfValid) {
    return false;
}

bool UStateMachineComponent::IsWindowSet(const FName& Name) {
    return false;
}

bool UStateMachineComponent::IsInterruptible() const {
    return false;
}

bool UStateMachineComponent::IsEventSet(const FName& Name) {
    return false;
}

void UStateMachineComponent::InitAnimInstance() {
}

bool UStateMachineComponent::InInteractive() {
    return false;
}

bool UStateMachineComponent::HasPendingInterrupt() {
    return false;
}

FName UStateMachineComponent::GetStateName() {
    return NAME_None;
}

AActor* UStateMachineComponent::GetPendingInteractiveOther() const {
    return NULL;
}

AActor* UStateMachineComponent::GetInteractiveOther() const {
    return NULL;
}

HitReactionType UStateMachineComponent::GetHitReactionType() {
    return HitReactionType::Flinch;
}

float UStateMachineComponent::GetElapsedStateTime() const {
    return 0.0f;
}

FString UStateMachineComponent::GetDebugInfo(int32 DebugLevel) {
    return TEXT("");
}

UActorState* UStateMachineComponent::GetCurrentState() {
    return NULL;
}

bool UStateMachineComponent::DoInteractive(const FName& NameID, AActor* Other, bool bOnlyIfValid) {
    return false;
}

void UStateMachineComponent::ClientSetState_Implementation(FStateID State, float LockDirection, uint8 CurrentClientAck) {
}

void UStateMachineComponent::ClientFailedLadderOccupancy_Implementation() {
}

void UStateMachineComponent::ClientDoInteractive_Implementation(FStateInfo Info, uint8 NewClientAck) {
}

void UStateMachineComponent::ClientAbortInteractive_Implementation() {
}

void UStateMachineComponent::ClearWindow(const FName& Name, bool bClearAll) {
}

void UStateMachineComponent::BeginLerp(float Time, bool LerpPosition, bool LerpRotation, bool EaseIn, float EaseExponent, bool ForceClearPreviousLerp) {
}

void UStateMachineComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UStateMachineComponent, StartState);
    DOREPLIFETIME(UStateMachineComponent, CurrentStateInfo);
}

UStateMachineComponent::UStateMachineComponent() {
    this->StateMachine = NULL;
    this->AnimationLayer = TEXT("Base");
    this->FlinchAnimationLayer = TEXT("Flinch");
    this->Secondary = false;
    this->Character = NULL;
    this->CurrentState = NULL;
    this->OverrideAnimInstance = NULL;
    this->AnimInstance = NULL;
    this->CachedInteractCullComponent = NULL;
}

