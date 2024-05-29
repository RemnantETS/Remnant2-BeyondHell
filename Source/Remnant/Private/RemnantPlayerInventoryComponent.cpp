#include "RemnantPlayerInventoryComponent.h"
#include "Templates/SubclassOf.h"

void URemnantPlayerInventoryComponent::RemoveItemTypeOverride(TSubclassOf<AItem> ItemBP) {
}

void URemnantPlayerInventoryComponent::RemoveItemsOnDeath() {
}

int32 URemnantPlayerInventoryComponent::ModifyLevelForNewItem(TSubclassOf<AItem> ItemBP, int32 ItemLevel) {
    return 0;
}

int32 URemnantPlayerInventoryComponent::GetLevelForNewItem(AActor* Actor, TSubclassOf<AItem> ItemBP, int32 ItemLevel) {
    return 0;
}

AEquipment* URemnantPlayerInventoryComponent::GetEquippedItemByType(const TSubclassOf<UItemType> Type) const {
    return NULL;
}

void URemnantPlayerInventoryComponent::AddItemTypeOverride(TSubclassOf<AItem> ItemBP, TSubclassOf<UItemType> Type) {
}

URemnantPlayerInventoryComponent::URemnantPlayerInventoryComponent() {
    this->AutoTransferWeaponMods = true;
}

