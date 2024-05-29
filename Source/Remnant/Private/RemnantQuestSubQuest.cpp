#include "RemnantQuestSubQuest.h"

void URemnantQuestSubQuest::SubQuestComplete(AQuest* Quest, EQuestResult Result) {
}

void URemnantQuestSubQuest::OnLinkDeactivated(UQuestComponent* Component) {
}

void URemnantQuestSubQuest::OnLinkActivated(UQuestComponent* Component) {
}

ARemnantQuest* URemnantQuestSubQuest::GetSubQuest() {
    return NULL;
}

URemnantQuestSubQuest::URemnantQuestSubQuest() {
    this->QuestType = ERemnantQuestType::Default;
    this->ChanceToSpawn = 100.00f;
    this->Optional = false;
    this->SubquestIgnoresTileExclusivity = false;
    this->SubquestIgnoresTileIDRequirement = false;
    this->LevelMin = 0;
    this->LevelRemapping = false;
    this->LevelRemappingMin = 1;
    this->LevelRemappingMax = 10;
    this->QuestID = -1;
    this->CachedQuest = NULL;
}

