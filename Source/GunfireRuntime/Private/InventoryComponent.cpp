#include "InventoryComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

bool UInventoryComponent::UseItem(TSubclassOf<AItem> ItemBP) {
    return false;
}

bool UInventoryComponent::UnequipItemByID(const int32 ItemId) {
    return false;
}

bool UInventoryComponent::UnequipItemAtSlotIndex(const int32 SlotIndex) {
    return false;
}

bool UInventoryComponent::UnequipItem(TSubclassOf<AItem> ItemBP) {
    return false;
}

void UInventoryComponent::ToggleActiveItem(TSubclassOf<UItemType> Type) {
}

void UInventoryComponent::TakeItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity, int32 LevelOverride) {
}

void UInventoryComponent::TakeAll(AActor* OtherActor) {
}

void UInventoryComponent::SwapItem(TSubclassOf<AItem> From, TSubclassOf<AItem> To) {
}

bool UInventoryComponent::SetQuantity(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason) {
    return false;
}

bool UInventoryComponent::SetItemLevel(TSubclassOf<AItem> ItemBP, int32 LevelToSet) {
    return false;
}

void UInventoryComponent::SetEquipmentInHandById(int32 EquipmentId) {
}

void UInventoryComponent::SetEquipmentInHandByClass(TSubclassOf<AEquipment> Equipment) {
}

void UInventoryComponent::SetEquipmentInHand(TSubclassOf<UItemType> Type) {
}

void UInventoryComponent::SetActiveItemByClass(TSubclassOf<AEquipment> Equipment) {
}

void UInventoryComponent::SetActiveItem(TSubclassOf<UItemType> Type) {
}

void UInventoryComponent::ServerUseItem_Implementation(TSubclassOf<AItem> ItemBP) {
}
bool UInventoryComponent::ServerUseItem_Validate(TSubclassOf<AItem> ItemBP) {
    return true;
}

void UInventoryComponent::ServerUnequipMod_Implementation(int32 ItemId, uint8 Slot, bool AddToInventory) {
}
bool UInventoryComponent::ServerUnequipMod_Validate(int32 ItemId, uint8 Slot, bool AddToInventory) {
    return true;
}

void UInventoryComponent::ServerUnequipItemByID_Implementation(int32 ItemId) {
}
bool UInventoryComponent::ServerUnequipItemByID_Validate(int32 ItemId) {
    return true;
}

void UInventoryComponent::ServerToggleActiveItem_Implementation(TSubclassOf<UItemType> Type) {
}
bool UInventoryComponent::ServerToggleActiveItem_Validate(TSubclassOf<UItemType> Type) {
    return true;
}

void UInventoryComponent::ServerTakeItemByID_Implementation(AActor* OtherActor, int32 ItemId, int32 Quantity) {
}
bool UInventoryComponent::ServerTakeItemByID_Validate(AActor* OtherActor, int32 ItemId, int32 Quantity) {
    return true;
}

void UInventoryComponent::ServerTakeAll_Implementation(AActor* OtherActor) {
}
bool UInventoryComponent::ServerTakeAll_Validate(AActor* OtherActor) {
    return true;
}

void UInventoryComponent::ServerSetEquipmentInHand_Implementation(TSubclassOf<UItemType> Type) {
}
bool UInventoryComponent::ServerSetEquipmentInHand_Validate(TSubclassOf<UItemType> Type) {
    return true;
}

void UInventoryComponent::ServerSetActiveItem_Implementation(TSubclassOf<UItemType> Type) {
}
bool UInventoryComponent::ServerSetActiveItem_Validate(TSubclassOf<UItemType> Type) {
    return true;
}

void UInventoryComponent::ServerPutItemByID_Implementation(AActor* OtherActor, int32 ItemId, int32 Quantity) {
}
bool UInventoryComponent::ServerPutItemByID_Validate(AActor* OtherActor, int32 ItemId, int32 Quantity) {
    return true;
}

void UInventoryComponent::ServerPickupItem_Implementation(AItem* Item) {
}
bool UInventoryComponent::ServerPickupItem_Validate(AItem* Item) {
    return true;
}

void UInventoryComponent::ServerPickupAndEquipItem_Implementation(AItem* Item, int32 SlotIndex, bool InHand) {
}
bool UInventoryComponent::ServerPickupAndEquipItem_Validate(AItem* Item, int32 SlotIndex, bool InHand) {
    return true;
}

void UInventoryComponent::ServerEquipSkin_Implementation(int32 ItemId, int32 SkinID) {
}
bool UInventoryComponent::ServerEquipSkin_Validate(int32 ItemId, int32 SkinID) {
    return true;
}

void UInventoryComponent::ServerEquipItemByID_Implementation(int32 ItemId, int32 SlotIndex) {
}
bool UInventoryComponent::ServerEquipItemByID_Validate(int32 ItemId, int32 SlotIndex) {
    return true;
}

void UInventoryComponent::ServerDropItemByID_Implementation(int32 ItemId, int32 Quantity, bool Force) {
}
bool UInventoryComponent::ServerDropItemByID_Validate(int32 ItemId, int32 Quantity, bool Force) {
    return true;
}

void UInventoryComponent::ServerDetachItem_Implementation(int32 ItemId) {
}
bool UInventoryComponent::ServerDetachItem_Validate(int32 ItemId) {
    return true;
}

void UInventoryComponent::RouteNotifyPickupItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason) {
}

bool UInventoryComponent::RemoveItemByID(int32 ID, int32 Quantity, int32 ItemLevel) {
    return false;
}

bool UInventoryComponent::RemoveItem(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel) {
    return false;
}

void UInventoryComponent::RemoveAllItems() {
}

void UInventoryComponent::PutItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity) {
}

void UInventoryComponent::PickupItem(AItem* Item) {
}

void UInventoryComponent::PickupAndEquipItem(AItem* Item, int32 SlotIndex, bool InHand) {
}

void UInventoryComponent::OnRep_Items() {
}

void UInventoryComponent::OnInstanceDataVisuallyChanged() {
}

void UInventoryComponent::NotifyUsedItem(TSubclassOf<AItem> ItemBP) {
}

void UInventoryComponent::NotifyPickupItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason) {
}

void UInventoryComponent::MulticastOnInventoryChanged_Implementation() {
}

void UInventoryComponent::MarkNotNew_Implementation(const int32 ItemId) {
}
bool UInventoryComponent::MarkNotNew_Validate(const int32 ItemId) {
    return true;
}

void UInventoryComponent::MarkFavorited(const int32 ItemId, bool Favorited) {
}

void UInventoryComponent::K2_AddItemSoft(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason, const FInventoryAddedItem& OnAdded, bool ForceEquip, bool SendNotification) {
}

FInventoryResult UInventoryComponent::K2_AddItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason, bool bAllowAutoEquip) {
    return FInventoryResult{};
}

bool UInventoryComponent::IsInventoryItemInfiniteByType(TSubclassOf<AItem> ItemBP) {
    return false;
}

bool UInventoryComponent::IsInventoryItemInfiniteByID(UInventoryComponent* Inventory, const int32 ItemId) {
    return false;
}

bool UInventoryComponent::IsInventoryItemInfinite(const FInventoryItem& InventoryItem) {
    return false;
}

bool UInventoryComponent::IsEquippedByID(const int32 ItemId) {
    return false;
}

bool UInventoryComponent::IsEquipped(TSubclassOf<AItem> ItemBP) {
    return false;
}

bool UInventoryComponent::HasNewItemInInventory() const {
    return false;
}

bool UInventoryComponent::HasItemByType(TSubclassOf<UItemType> Type) const {
    return false;
}

bool UInventoryComponent::HasItem(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel) const {
    return false;
}

bool UInventoryComponent::HasEquippedItemByType(TSubclassOf<UItemType> Type) const {
    return false;
}

bool UInventoryComponent::HasEquipmentSlot(FName NameID) {
    return false;
}

int32 UInventoryComponent::GetSellValue(int32 Cost, float SellScalar) {
    return 0;
}

int32 UInventoryComponent::GetQuantity(TSoftClassPtr<AItem> ItemBP, int32 ItemLevel) const {
    return 0;
}

bool UInventoryComponent::GetPreviousItem(int32 CurrentID, FInventoryItem& OutItem, TSubclassOf<UItemType> Type, bool bWrapAround) {
    return false;
}

bool UInventoryComponent::GetNextItem(int32 CurrentID, FInventoryItem& OutItem, TSubclassOf<UItemType> Type, bool bWrapAround) {
    return false;
}

AEquipment* UInventoryComponent::GetNextActiveItem(TSubclassOf<UItemType> Type) {
    return NULL;
}

TSubclassOf<UItemType> UInventoryComponent::GetItemTypeBySlotName(FName NameID) {
    return NULL;
}

TSubclassOf<UItemType> UInventoryComponent::GetItemType(const AItem* Item) const {
    return NULL;
}

TArray<FInventoryItem> UInventoryComponent::GetItems() {
    return TArray<FInventoryItem>();
}

UItemInstanceData* UInventoryComponent::GetItemInstanceData(TSubclassOf<AItem> ItemBP) {
    return NULL;
}

int32 UInventoryComponent::GetItemCount() {
    return 0;
}

UInventoryComponent* UInventoryComponent::GetInventoryForItemType(AActor* Actor, TSubclassOf<UItemType> ItemType) {
    return NULL;
}

UInventoryComponent* UInventoryComponent::GetInventoryForItemSoft(AActor* Actor, TSoftClassPtr<AItem> Item) {
    return NULL;
}

UInventoryComponent* UInventoryComponent::GetInventoryForItem(AActor* Actor, TSubclassOf<AItem> Item) {
    return NULL;
}

int32 UInventoryComponent::GetHighestLevelForItem(TSoftClassPtr<AItem> ItemBP) const {
    return 0;
}

AEquipment* UInventoryComponent::GetEquippedItemBySlotName(FName NameID) {
    return NULL;
}

AEquipment* UInventoryComponent::GetEquippedItemByClass(TSubclassOf<AEquipment> Equipment) const {
    return NULL;
}

AEquipment* UInventoryComponent::GetEquippedItem(int32 SlotIndex) {
    return NULL;
}

FName UInventoryComponent::GetEquipmentSlotNameForItem(TSubclassOf<AItem> ItemBP) {
    return NAME_None;
}

int32 UInventoryComponent::GetEquipmentSlotIndexBySlotName(FName SlotName) {
    return 0;
}

int32 UInventoryComponent::GetEquipmentSlotIndexByNameID(FName SlotNameID) {
    return 0;
}

int32 UInventoryComponent::GetEquipmentSlotIndex(TSubclassOf<AItem> ItemBP) {
    return 0;
}

FEquipmentSlot UInventoryComponent::GetEquipmentSlotByNameID(FName SlotNameID) {
    return FEquipmentSlot{};
}

int32 UInventoryComponent::GetEquipmentItemID(AEquipment* EquippedActor) {
    return 0;
}

AEquipment* UInventoryComponent::GetEquipmentInHand() const {
    return NULL;
}

int32 UInventoryComponent::GetBuyValue(UInventoryComponent* OtherInventory, int32 ItemId, int32 Level) {
    return 0;
}

AEquipment* UInventoryComponent::GetActiveItem(TSubclassOf<UItemType> Type) const {
    return NULL;
}

TSubclassOf<UItemType> UInventoryComponent::GetActivationTypeBySlotName(FName NameID) {
    return NULL;
}

FInventoryItem UInventoryComponent::FindItemByID(int32 ID) {
    return FInventoryItem{};
}

FInventoryItem UInventoryComponent::FindItemByEquipSlotNameID(FName NameID) {
    return FInventoryItem{};
}

FInventoryItem UInventoryComponent::FindItem(TSubclassOf<AItem> ItemBP) {
    return FInventoryItem{};
}

void UInventoryComponent::EquipSkin(int32 ItemId, int32 SkinID) {
}

bool UInventoryComponent::EquipItemWithTransform(const int32 ItemId, const int32 SlotIndex, FTransform Transform) {
    return false;
}

bool UInventoryComponent::EquipItemByID(const int32 ItemId, const int32 SlotIndex) {
    return false;
}

bool UInventoryComponent::EquipItem(TSubclassOf<AItem> ItemBP, const int32 SlotIndex) {
    return false;
}

void UInventoryComponent::DropItemByID(const int32 ItemId, int32 Quantity, bool Force) {
}

void UInventoryComponent::DropItem(TSubclassOf<AItem> ItemBP, int32 Quantity) {
}

void UInventoryComponent::DropAll() {
}

bool UInventoryComponent::DidActiveItemChange(TSubclassOf<UItemType> Type) const {
    return false;
}

void UInventoryComponent::DetachItemByID(const int32 ItemId) {
}

int32 UInventoryComponent::CountItemByType(TSubclassOf<UItemType> ItemType) {
    return 0;
}

void UInventoryComponent::ClientNotifyUpgradeItem_Implementation(TSubclassOf<AItem> ItemBP, int32 Level) {
}

void UInventoryComponent::ClientNotifyTakeItemResult_Implementation(TSubclassOf<AItem> ItemBP, int32 Quantity, bool DidTakeItem) {
}

void UInventoryComponent::ClientNotifyPickupItemInstance_Implementation(AItem* Item, int32 Quantity, int32 Level, EItemNotifyReason Reason, bool bBroadcastNotify) {
}

void UInventoryComponent::ClientNotifyPickupItem_Implementation(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason) {
}

void UInventoryComponent::ClientNotifyInventoryFull_Implementation(TSubclassOf<AItem> ItemBP) {
}

void UInventoryComponent::ClientForceUseItem_Implementation(int32 ItemId) {
}

bool UInventoryComponent::CanEquipItemByID(const int32 ItemId, const int32 SlotIndex) {
    return false;
}

bool UInventoryComponent::CanAutoEquip(TSubclassOf<AItem> ItemBP, bool ManualRequest) {
    return false;
}

bool UInventoryComponent::CanAddItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel) {
    return false;
}

void UInventoryComponent::AutoPickupAndEquipItem(AItem* Item, bool InHand) {
}

bool UInventoryComponent::AutoEquipItemByID(const int32 ItemId, bool ForceEquip) {
    return false;
}

bool UInventoryComponent::AutoEquipItem(TSubclassOf<AItem> ItemBP, bool ForceEquip) {
    return false;
}

void UInventoryComponent::AddInfiniteItem(TSubclassOf<AItem> ItemBP) {
}

TSoftClassPtr<AItem> UInventoryComponent::ActorToItem(TSoftClassPtr<AActor> Item) {
    return NULL;
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UInventoryComponent, Items);
    DOREPLIFETIME(UInventoryComponent, PriceScaling);
}

UInventoryComponent::UInventoryComponent() {
    this->IsMerchant = false;
    this->Accessibility = EInventoryAccess::Private;
    this->EquipmentInHand = NULL;
    this->LastEquipmentInHand = NULL;
    this->CurrencyType = NULL;
    this->MetalType = NULL;
    this->DefaultLootFX = NULL;
    this->IDGen = 0;
    this->DoPriceScaling = false;
}

