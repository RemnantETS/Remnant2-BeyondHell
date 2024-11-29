#include "RemnantQuestWaveEncounter.h"

void URemnantQuestWaveEncounter::WaveComplete(UEncounterInstance* Instance) {
}

void URemnantQuestWaveEncounter::Stop(bool DestroyActiveSpawns) {
}

void URemnantQuestWaveEncounter::SpawnWave() {
}

void URemnantQuestWaveEncounter::Resume() {
}

void URemnantQuestWaveEncounter::Pause() {
}

bool URemnantQuestWaveEncounter::IsQuestWaveActive() const {
    return false;
}

void URemnantQuestWaveEncounter::EventPlayerExit(FEventRegionCharacter Character) {
}

void URemnantQuestWaveEncounter::EventPlayerEnter(FEventRegionCharacter Character) {
}

void URemnantQuestWaveEncounter::EventOnEnd() {
}

void URemnantQuestWaveEncounter::Begin(AActor* Target) {
}

URemnantQuestWaveEncounter::URemnantQuestWaveEncounter(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->SpawnTable = NULL;
    this->EncounterTarget = NULL;
    this->EventRegion = NULL;
    this->EncounterInstance = NULL;
}

