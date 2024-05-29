#include "LoadoutEquipmentSlot.h"

AEquipment* ULoadoutEquipmentSlot::GetEquipment(ACharacterGunfire* Character) const {
    return NULL;
}

ULoadoutEquipmentSlot::ULoadoutEquipmentSlot() {
    this->SlotType = NULL;
    this->bRecordEquipmentMods = true;
}

