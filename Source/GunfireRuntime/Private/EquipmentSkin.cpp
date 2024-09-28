#include "EquipmentSkin.h"

AEquipmentSkin::AEquipmentSkin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool AEquipmentSkin::IsSkinEquipped(UInventoryComponent* Inventory, int32 SkinID) {
    return false;
}

TArray<int32> AEquipmentSkin::GetSkinsForItem(UInventoryComponent* Inventory, int32 ItemId) {
    return TArray<int32>();
}

AEquipmentSkin* AEquipmentSkin::GetSkinForBP(UInventoryComponent* Inventory, TSoftClassPtr<AEquipment> ItemBP) {
    return NULL;
}

void AEquipmentSkin::EquipSkin(UInventoryComponent* Inventory, int32 ItemId, int32 SkinID) {
}


