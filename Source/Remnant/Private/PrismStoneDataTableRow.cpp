#include "PrismStoneDataTableRow.h"

FPrismStoneDataTableRow::FPrismStoneDataTableRow() {
    this->Rarity = 0;
    this->Category = EPrismSegmentCategory::Red;
    this->ComboSegment = false;
    this->PrismRequirementsToRoll = NULL;
    this->CharacterRequirementsToRoll = NULL;
    this->RowOverridesRequirementEntries = false;
}

