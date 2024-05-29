#include "VariableComponent.h"
#include "Net/UnrealNetwork.h"

void UVariableComponent::SetVariableName(const FName& NameID, FName Value, float Expiration) {
}

void UVariableComponent::SetVariableInt(const FName& NameID, int32 Value, float Expiration) {
}

void UVariableComponent::SetVariableFloat(const FName& NameID, float Value, float Expiration) {
}

void UVariableComponent::SetVariableBool(const FName& NameID, bool Value, float Expiration) {
}

FName UVariableComponent::GetVariableName(const FName& NameID) {
    return NAME_None;
}

int32 UVariableComponent::GetVariableInt(const FName& NameID) {
    return 0;
}

float UVariableComponent::GetVariableFloat(const FName& NameID) {
    return 0.0f;
}

bool UVariableComponent::GetVariableBool(const FName& NameID) {
    return false;
}

void UVariableComponent::ExecuteStatements(AActor* ContextActor, const FVariableStatements& Statements) {
}

bool UVariableComponent::EvaluateStatements(AActor* ContextActor, const FVariableStatements& Statements) {
    return false;
}

void UVariableComponent::ClientSetVariable_Implementation(int16 Index, const FVariableValue& NewValue) {
}

void UVariableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UVariableComponent, Variables);
}

UVariableComponent::UVariableComponent() {
    this->VariableDefinitions = NULL;
    this->RegisterOwnerVariables = true;
    this->DummyVar = false;
}

