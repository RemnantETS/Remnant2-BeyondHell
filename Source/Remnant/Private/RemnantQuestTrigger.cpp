#include "RemnantQuestTrigger.h"

void URemnantQuestTrigger::OnActorRegistered(AActor* Actor) {
}

AQuestTrigger* URemnantQuestTrigger::GetTrigger() {
    return NULL;
}

TArray<ARemnantCharacter*> URemnantQuestTrigger::GetPlayersInTrigger() {
    return TArray<ARemnantCharacter*>();
}

int32 URemnantQuestTrigger::GetNumPlayersInTrigger() {
    return 0;
}

void URemnantQuestTrigger::EventPlayerExit(ARemnantCharacter* Player) {
}

void URemnantQuestTrigger::EventPlayerEnter(ARemnantCharacter* Player) {
}

URemnantQuestTrigger::URemnantQuestTrigger(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->Trigger = NULL;
}

