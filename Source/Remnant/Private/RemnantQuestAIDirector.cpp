#include "RemnantQuestAIDirector.h"

void URemnantQuestAIDirector::StopAllGroups(bool DestroyActiveSpawns) {
}

void URemnantQuestAIDirector::SetSpawnTable(USpawnTable* SpawnTable) {
}

void URemnantQuestAIDirector::OnEncounterGroupRemoved(UEncounterGroupInstance* EncounterGroup) {
}

void URemnantQuestAIDirector::OnEncounterGroupActorSpawned(UEncounterGroupInstance* EncounterGroup, AActor* Actor) {
}

void URemnantQuestAIDirector::OnEncounterGroupActorDead(UEncounterGroupInstance* EncounterGroup, AActor* Actor) {
}

bool URemnantQuestAIDirector::HasActiveSpawns(bool IncludeQueuedSpawns) {
    return false;
}

int32 URemnantQuestAIDirector::GetTotalSpawns(bool IncludeQueuedSpawns) {
    return 0;
}

void URemnantQuestAIDirector::EventPlayerExit(FEventRegionCharacter Character) {
}

void URemnantQuestAIDirector::EventPlayerEnter(FEventRegionCharacter Character) {
}

void URemnantQuestAIDirector::EventEncounterEvent(UEncounterGroupInstance* EncounterGroup, FName EventName) {
}

URemnantQuestAIDirector::URemnantQuestAIDirector(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->IncludeZoneGroups = false;
}

