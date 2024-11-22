#include "StatModTableEntry.h"

FStatModTableEntry::FStatModTableEntry() {
    this->Level = 0;
    this->StatBonus = 0.00f;
    this->ModifierBP = NULL;
    this->ModifierLevel = 0;
    this->ModifierCapacity = 0;
    this->OverrideExistingLevel = false;
    this->LevelScalingOwner = NULL;
    this->RequiredContextSlot = 0;
    this->AllowOverrideRequiredContextSlot = false;
    this->Hidden = false;
}

