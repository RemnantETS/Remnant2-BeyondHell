#include "QuestComponent.h"

UQuestComponent::UQuestComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seed = 0;
    this->bQuestAutoActivate = true;
}

void UQuestComponent::OnResetQuest_Implementation() {
}

void UQuestComponent::OnRequiredAssetsLoaded() {
}

void UQuestComponent::OnQuestComplete_Implementation(EQuestResult Result) {
}

void UQuestComponent::OnPostInitializeQuest_Implementation() {
}

void UQuestComponent::OnPostCreateQuest_Implementation() {
}

void UQuestComponent::OnObjectiveComplete_Implementation(FName NameID) {
}

void UQuestComponent::OnObjectiveActivate_Implementation(FName NameID) {
}

void UQuestComponent::OnInitializeQuest_Implementation() {
}

void UQuestComponent::OnDeinitializeQuest_Implementation() {
}

void UQuestComponent::OnCreateQuest_Implementation(const FRandomStream& RandomStream) {
}

bool UQuestComponent::IsQuestActive() {
    return false;
}

bool UQuestComponent::HasErrors() {
    return false;
}

FName UQuestComponent::GetUniqueName() {
    return NAME_None;
}

AQuest* UQuestComponent::GetRootQuest() const {
    return NULL;
}

AQuest* UQuestComponent::GetQuest() const {
    return NULL;
}

void UQuestComponent::GetDebugProperties(TArray<FQuestDebugProperty>& Properties) {
}

FString UQuestComponent::GetDebugLabel() {
    return TEXT("");
}

void UQuestComponent::DebugTravelTo(FName Context, APlayerController* Player) {
}

bool UQuestComponent::DebugCanTravelTo() {
    return false;
}

void UQuestComponent::DeactivateQuest() {
}

bool UQuestComponent::AreAssetsLoaded() {
    return false;
}

void UQuestComponent::ActivateQuest() {
}


