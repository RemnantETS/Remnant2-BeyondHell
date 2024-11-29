#include "RemnantQuestComponent.h"

URemnantQuestComponent::URemnantQuestComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool URemnantQuestComponent::IsZoneLoaded() {
    return false;
}

AZoneActor* URemnantQuestComponent::GetZone() {
    return NULL;
}

ARemnantQuest* URemnantQuestComponent::GetRemnantQuest() {
    return NULL;
}

URemnantQuestZone* URemnantQuestComponent::GetQuestZone() {
    return NULL;
}

URemnantQuestTile* URemnantQuestComponent::GetQuestTile() {
    return NULL;
}

URemnantQuestEntity* URemnantQuestComponent::GetQuestEntity() {
    return NULL;
}


