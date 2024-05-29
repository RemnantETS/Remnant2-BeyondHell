#include "RemnantQuestManager.h"

TArray<FRemnantQuestEntry> URemnantQuestManager::SortQuestList(const TArray<FRemnantQuestEntry>& QuestList) {
    return TArray<FRemnantQuestEntry>();
}

void URemnantQuestManager::ResetTransientRootQuests() {
}

void URemnantQuestManager::MarkOneShotRolled(const FRemnantQuestEntry& Quest) {
}

bool URemnantQuestManager::IsQuestValid(ARemnantQuest* Quest, AActor* Actor) {
    return false;
}

bool URemnantQuestManager::IsOneShotRolled(const FRemnantQuestEntry& Quest) {
    return false;
}

TArray<ARemnantQuest*> URemnantQuestManager::GetRootQuests() const {
    return TArray<ARemnantQuest*>();
}

ARemnantQuest* URemnantQuestManager::GetRootQuestForSlot(int32 SlotID) const {
    return NULL;
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredRootQuestsForMode(EQuestMode Mode) {
    return TArray<FRemnantQuestEntry>();
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredRootQuests() {
    return TArray<FRemnantQuestEntry>();
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredQuests() {
    return TArray<FRemnantQuestEntry>();
}

FRemnantQuestEntry URemnantQuestManager::GetRegisteredQuestByID(const FString& QuestID) {
    return FRemnantQuestEntry{};
}

FRemnantQuestEntry URemnantQuestManager::GetRegisteredQuestByClass(TSoftClassPtr<ARemnantQuest> QuestBP) {
    return FRemnantQuestEntry{};
}

void URemnantQuestManager::GetQuestsForActor(AActor* Actor, bool IncludeInjectedQuests, TArray<ARemnantQuest*>& Rtn) {
}

UQuestObjective* URemnantQuestManager::GetCurrentQuestObjective(ARemnantQuest* Quest) {
    return NULL;
}

ARemnantQuest* URemnantQuestManager::GetActiveRootQuest() const {
    return NULL;
}

void URemnantQuestManager::DestroyRootQuest(ARemnantQuest* Quest) const {
}

ARemnantQuest* URemnantQuestManager::CreateRootQuest(int32 SlotID, const FString& QuestID, int32 Difficulty) {
    return NULL;
}

bool URemnantQuestManager::ActivateRootQuest(ARemnantQuest* Quest) const {
    return false;
}

URemnantQuestManager::URemnantQuestManager() {
    this->RootQuestVariables = NULL;
}

