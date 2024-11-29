#include "RemnantQuestEventRegion.h"

void URemnantQuestEventRegion::SetMusicState(EMusicState MusicState) {
}

void URemnantQuestEventRegion::OnNotifyTakeDamage(const FDamageInfo& DamageInfo) {
}

void URemnantQuestEventRegion::OnActorRegistered(AActor* Actor) {
}

void URemnantQuestEventRegion::LockEvent() {
}

bool URemnantQuestEventRegion::IsEventRegionActive() const {
    return false;
}

bool URemnantQuestEventRegion::IsComplete() const {
    return false;
}

TArray<ARemnantCharacter*> URemnantQuestEventRegion::GetPlayersInRegion() {
    return TArray<ARemnantCharacter*>();
}

int32 URemnantQuestEventRegion::GetNumPlayersInRegion() {
    return 0;
}

ARemnantCharacter* URemnantQuestEventRegion::GetFirstPlayerInRegion() {
    return NULL;
}

AEventRegion* URemnantQuestEventRegion::GetEventRegion() {
    return NULL;
}

FName URemnantQuestEventRegion::GetAggroGroup() {
    return NAME_None;
}

void URemnantQuestEventRegion::EventPlayerExit(FEventRegionCharacter Player) {
}

void URemnantQuestEventRegion::EventPlayerEnter(FEventRegionCharacter Player) {
}

void URemnantQuestEventRegion::EventOnEnd() {
}

void URemnantQuestEventRegion::EventOnBegin() {
}

void URemnantQuestEventRegion::EventCharacterExit(ACharacterGunfire* Character) {
}

void URemnantQuestEventRegion::EventCharacterEnter(ACharacterGunfire* Character) {
}

void URemnantQuestEventRegion::End() {
}

void URemnantQuestEventRegion::CompleteEvent() {
}

void URemnantQuestEventRegion::Begin() {
}

URemnantQuestEventRegion::URemnantQuestEventRegion(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->MusicSet = NULL;
    this->bOverrideExistingSet = true;
    this->EventRegion = NULL;
}

