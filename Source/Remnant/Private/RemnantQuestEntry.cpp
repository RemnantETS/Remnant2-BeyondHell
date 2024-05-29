#include "RemnantQuestEntry.h"

FRemnantQuestEntry::FRemnantQuestEntry() {
    this->Type = ERemnantQuestType::Default;
    this->Rarity = ERemnantQuestRarity::Common;
    this->MaxUsageCount = 0;
    this->IsOneShot = false;
    this->DebugState = ERemnantQuestDebugState::None;
    this->QuestGameMode = EQuestMode::Campaign;
    this->RequiredAward = NULL;
}

