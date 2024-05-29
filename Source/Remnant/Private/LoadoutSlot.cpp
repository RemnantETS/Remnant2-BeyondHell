#include "LoadoutSlot.h"

bool ULoadoutSlot::ShouldLoadSlot(ACharacterGunfire* Character) const {
    return false;
}

int32 ULoadoutSlot::GetRecordLevelForEntry(ACharacterGunfire* Character, int32 RecordIndex, int32 EntryIndex) const {
    return 0;
}

int32 ULoadoutSlot::GetNumEntriesForSlot(ACharacterGunfire* Character, int32 RecordIndex) const {
    return 0;
}

TSoftClassPtr<UObject> ULoadoutSlot::GetDisplayClassForEntry(ACharacterGunfire* Character, int32 RecordIndex, int32 EntryIndex) const {
    return NULL;
}

TSoftClassPtr<UObject> ULoadoutSlot::GetDispalyClass(ACharacterGunfire* Character, int32 RecordIndex) const {
    return NULL;
}

ULoadoutSlot::ULoadoutSlot() {
    this->Priority = 0;
}

