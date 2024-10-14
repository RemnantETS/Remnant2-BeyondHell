#include "SpawnTableItem.h"

USpawnTableItem::USpawnTableItem() {
    this->bScaleWeightIfOwned = false;
    this->OwnedWeightScalar = 0.01f;
    this->QuantityMin = 1;
    this->QuantityMax = 1;
    this->QuantityScalarPerLevel = 0.00f;
    this->ItemLevel = -1;
    this->SetGeneratedItemLevel = false;
    this->GeneratedItemLevelOffsetMin = 0;
    this->GeneratedItemLevelOffsetMax = 0;
}


