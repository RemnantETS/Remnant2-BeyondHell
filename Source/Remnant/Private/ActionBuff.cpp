#include "ActionBuff.h"
#include "Net/UnrealNetwork.h"

UActionBuff::UActionBuff() {
    this->Duration = 5.00f;
    this->Persistent = false;
    this->ContextualDialogTriggerRate = 10.00f;
    this->IgnoreOwnerTimeDilation = true;
    this->VisualPriority = 0;
    this->ElapsedTime = 0.00f;
    this->CachedVisuals = NULL;
    this->CachedActions = NULL;
}


void UActionBuff::ResetTimerWithNewDuration_Implementation(float InDuration) {
}

void UActionBuff::ResetTimer_Implementation() {
}

void UActionBuff::PauseDuration(bool Paused) {
}



bool UActionBuff::IsDurationPaused() const {
    return false;
}

float UActionBuff::GetRemainingTime() const {
    return 0.0f;
}

float UActionBuff::GetElapsedTimePct() const {
    return 0.0f;
}

bool UActionBuff::GetDesiredVisual_Implementation(FName& Slot, FName& ID) {
    return false;
}

void UActionBuff::ApplyTimerDelta_Implementation(float DeltaTime) {
}

void UActionBuff::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActionBuff, Duration);
    DOREPLIFETIME(UActionBuff, ElapsedTime);
}


