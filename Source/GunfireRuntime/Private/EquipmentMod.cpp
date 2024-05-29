#include "EquipmentMod.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

bool AEquipmentMod::ValidateAttach(ACharacterGunfire* ToCharacter) const {
    return false;
}

bool AEquipmentMod::UnequipMod(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, bool AddToInventory) {
    return false;
}

void AEquipmentMod::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) const {
}

void AEquipmentMod::OnPostComputeStats_Implementation() const {
}

void AEquipmentMod::OnFinishLoadingAssets() {
}

void AEquipmentMod::OnEquipmentModAssetsLoaded_Implementation() {
}


void AEquipmentMod::OnDetached_Implementation() {
}

void AEquipmentMod::OnComputeStats_Implementation() const {
}

void AEquipmentMod::OnAttached_Implementation() {
}

void AEquipmentMod::ModifyStat(FName Stat, float Value) const {
}

bool AEquipmentMod::HasItemOrEquippedMod(UInventoryComponent* Inventory, TSoftClassPtr<AItem> ItemBP) {
    return false;
}

float AEquipmentMod::GetStat(FName Stat) const {
    return 0.0f;
}

uint8 AEquipmentMod::GetSlot() const {
    return 0;
}

FInspectInfo AEquipmentMod::GetPreviewInspectInfoFromInventory(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, int32 ModItemID) {
    return FInspectInfo{};
}

FInspectInfo AEquipmentMod::GetPreviewInspectInfo(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel) {
    return FInspectInfo{};
}

bool AEquipmentMod::GetInspectInfoForModBySlotName(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, FName Slot, FInspectInfo& Rtn) {
    return false;
}

UClass* AEquipmentMod::GetEquipmentModAssetClass(FName AssetName) const {
    return NULL;
}

UObject* AEquipmentMod::GetEquipmentModAsset(FName AssetName) const {
    return NULL;
}

AEquipment* AEquipmentMod::GetEquipment() const {
    return NULL;
}

bool AEquipmentMod::FindEquippedModInInventory(UInventoryComponent* Inventory, TSoftClassPtr<AItem> Mod, int32& OutItemID, FEquipmentModData& OutModData) {
    return false;
}

bool AEquipmentMod::EquipModFromInventory(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, int32 ModItemID) {
    return false;
}

bool AEquipmentMod::EquipMod(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel, int32 ModItemID) {
    return false;
}

bool AEquipmentMod::CanEquipMod(ACharacterGunfire* Character, TSubclassOf<AEquipmentMod> Mod) {
    return false;
}

bool AEquipmentMod::AreEquipmentModAssetsLoaded() const {
    return false;
}

void AEquipmentMod::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEquipmentMod, EquipOwner);
    DOREPLIFETIME(AEquipmentMod, EquippedSlot);
    DOREPLIFETIME(AEquipmentMod, EquippedLevel);
}

AEquipmentMod::AEquipmentMod() {
    this->Hidden = true;
    this->ReplicateMod = false;
    this->CanBeRemoved = true;
    this->CustomizationSlot = TEXT("Default");
    this->EquipOwner = NULL;
    this->EquippedSlot = 0;
    this->EquippedLevel = 0;
}

