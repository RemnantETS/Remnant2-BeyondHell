#include "QuestRecordsComponent.h"
#include "Net/UnrealNetwork.h"

UQuestRecordsComponent::UQuestRecordsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->QuestRecordsRules = NULL;
}

void UQuestRecordsComponent::StartNewRecordsSession(AQuest* RootQuest) {
}

void UQuestRecordsComponent::InitializeRecordsForQuest(AQuest* Quest) {
}

void UQuestRecordsComponent::InitializeRecordsForPlayer(APlayerState* ContextPlayer) {
}

void UQuestRecordsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UQuestRecordsComponent, Records);
}


