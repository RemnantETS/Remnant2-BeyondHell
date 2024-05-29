#include "LoadoutTraitSlot.h"

UTraitsComponent* ULoadoutTraitSlot::GetTraitsComponent(ACharacterGunfire* Character) const {
    return NULL;
}

ULoadoutTraitSlot::ULoadoutTraitSlot() {
    this->SlotIndex = 0;
    this->Type = NULL;
}

