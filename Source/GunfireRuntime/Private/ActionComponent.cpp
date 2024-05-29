#include "ActionComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

void UActionComponent::StopActionByType(TSubclassOf<UActionBase> ActionBP) {
}

void UActionComponent::StopAction(int32 ActionID) {
}

void UActionComponent::RemoveAnyActionAppliedListener(const FOnAnyActionAppliedDelegate& Event) {
}

void UActionComponent::OnRep_Actions() {
}

int32 UActionComponent::ModifyActionLevel(TSubclassOf<UActionBase> Action, int32 Level) {
    return 0;
}

bool UActionComponent::IsActionTypeRunning(TSubclassOf<UActionBase> ActionBP) const {
    return false;
}

bool UActionComponent::IsActionRunning(int32 ActionID) const {
    return false;
}

void UActionComponent::InvokeEventOnAll(FName EventName) {
}

void UActionComponent::InvokeEvent(TSubclassOf<UActionBase> ActionType, FName EventName) {
}

int32 UActionComponent::GetNumActionsOfType(TSubclassOf<UActionBase> ActionBP) const {
    return 0;
}

TArray<UActionBase*> UActionComponent::GetAllActionsOfType(TSubclassOf<UActionBase> ActionBP, bool AllowChildClasses) const {
    return TArray<UActionBase*>();
}

UActionBase* UActionComponent::GetActionOfType(TSubclassOf<UActionBase> ActionBP) const {
    return NULL;
}

UActionBase* UActionComponent::GetActionByID(int32 ID) const {
    return NULL;
}

int32 UActionComponent::DoActionInternal(UActionBase* Action, const FDamageInfo& DamageInfo, const TArray<FName>& AdditionalTags) {
    return 0;
}

int32 UActionComponent::DoAction(TSubclassOf<UActionBase> Action, AActor* Cause, AActor* Target, FHitResult HitInfo, TSubclassOf<UDamageType> DamageType) {
    return 0;
}

bool UActionComponent::CanDoActionInternal(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& DamageInfo, UActionBase* NewAction) {
    return false;
}

void UActionComponent::AddAnyActionAppliedListener(const FOnAnyActionAppliedDelegate& Event) {
}

void UActionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActionComponent, Actions);
}

UActionComponent::UActionComponent() {
}

