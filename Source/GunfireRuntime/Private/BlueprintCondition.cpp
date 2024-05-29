#include "BlueprintCondition.h"

bool UBlueprintCondition::TestCondition_Implementation(AActor* Actor) const {
    return false;
}

void UBlueprintCondition::SetConditionState(UStateMachineComponent* StateMachine, bool State) const {
}

bool UBlueprintCondition::GetConditionState(UStateMachineComponent* StateMachine, bool& State) const {
    return false;
}

UBlueprintCondition::UBlueprintCondition() {
}

