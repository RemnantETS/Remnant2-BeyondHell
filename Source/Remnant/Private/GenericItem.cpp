#include "GenericItem.h"
#include "Net/UnrealNetwork.h"

AGenericItem::AGenericItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RandomizedDrop = NULL;
    this->GenerationType = EGenerationType::TargetPlayerOnly;
    this->UsePlayerLevel = true;
    this->bUseGeneratedObjectLabel = true;
    this->bUseGeneratedObjectIcon = true;
    this->bUseGeneratedObjectPickupSound = false;
    this->bAddToInventory = false;
    this->bSaveOnAward = true;
    this->ForceSyncLoad = false;
}

bool AGenericItem::ValidatePickupHandled_Implementation(UInventoryComponent* Inventory) {
    return false;
}

bool AGenericItem::ValidateAddToInventory_Implementation(UInventoryComponent* Inventory) {
    return false;
}

void AGenericItem::OnRep_CachedSpawnInfo() {
}


bool AGenericItem::HasMaxSpawnsForCharacter_Implementation(AActor* Actor) {
    return false;
}

void AGenericItem::HandleAward_Implementation(UInventoryComponent* Inventory, bool bForceNoSharing) {
}

int32 AGenericItem::GetRewardItemLevel_Implementation(AActor* Receipient) {
    return 0;
}

void AGenericItem::FinishSpawnInit() {
}

void AGenericItem::ClientSetSpawnInfo_Implementation(const TArray<FGenericDropInfo>& SpawnInfo) {
}

void AGenericItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGenericItem, CachedSpawnInfo);
}


