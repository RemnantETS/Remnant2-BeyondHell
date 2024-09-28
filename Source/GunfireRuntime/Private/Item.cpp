#include "Item.h"
#include "PersistenceComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AItem::AItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->PersistenceComp = CreateDefaultSubobject<UPersistenceComponent>(TEXT("Persistence"));
    this->Type = NULL;
    this->Category = NULL;
    this->MaxStackCount = 1;
    this->BaseMaxQuantity = -1;
    this->KeepInInventoryWithNoQuantity = false;
    this->InstanceData = NULL;
    this->Unique = false;
    this->bNeedsQuantityToSelect = true;
    this->Icon = NULL;
    this->HUDIcon = NULL;
    this->Interactable = true;
    this->UseInteractInfo = false;
    this->InteractIcon = NULL;
    this->LootFxAttachNode = TEXT("LootFX");
    this->LootFxOverride = NULL;
    this->DoBounce = true;
    this->RequiredAccountAward = NULL;
    this->RequiredEntitlement = NULL;
    this->bOnGround = true;
    this->LootFxParticles = NULL;
    this->Inspecting = false;
    this->ItemSocket = NULL;
}

bool AItem::ValidateAdd_Implementation(UInventoryComponent* Inventory, int32 DesiredQuantity, int32& AllowedQuantity) {
    return false;
}


void AItem::SetQuantity(int32 Quantity) {
}

void AItem::SetNewStatsHandle(FDataTableRowHandle InStatsHandle) {
}

void AItem::SetLevel(uint8 Level) {
}

void AItem::SetFallLocation_Implementation(FVector NewRootLocation, FVector NewRelativeLocation) {
}

bool AItem::PreAdd_Implementation(UInventoryComponent* Inventory, int32& Quantity) {
    return false;
}

bool AItem::PickupPreAdd_Implementation(UInventoryComponent* Inventory, int32& Quantity, int32 Level) {
    return false;
}

void AItem::PickupItem_Implementation(UInventoryComponent* Inventory) {
}

void AItem::OnRep_InstanceData(UItemInstanceData* PrevData) {
}

void AItem::OnPickupFailed_Implementation() {
}



void AItem::OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode) {
}


void AItem::LevelChanged_Implementation(UInventoryComponent* Inventory, int32 ItemId, UItemInstanceData* ItemInstanceData) {
}

void AItem::InitializeLootFxForLocalPawn(APawn* Pawn) {
}

FText AItem::GetSubLabel_Implementation() const {
    return FText::GetEmpty();
}

bool AItem::GetRewardForMaxStackPickup_Implementation(UInventoryComponent* Inventory, int32 Level, TSubclassOf<AItem>& OutRewardClass, int32& OutQuantity, int32& OutLevel) const {
    return false;
}

bool AItem::GetRewardForLowerQualityPickup_Implementation(UInventoryComponent* Inventory, int32 Level, TSubclassOf<AItem>& OutRewardClass, int32& OutQuantity, int32& OutLevel) const {
    return false;
}

int32 AItem::GetQuantity() {
    return 0;
}

int32 AItem::GetMaxQuantity(AActor* Actor) {
    return 0;
}

FText AItem::GetLabel_Implementation() const {
    return FText::GetEmpty();
}

UItemSocketComponent* AItem::GetItemSocket() const {
    return NULL;
}

uint8 AItem::GetItemLevel_Implementation() const {
    return 0;
}

FInspectInfo AItem::GetInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, int32 LevelOverride) {
    return FInspectInfo{};
}

void AItem::FallTo(const FVector& NewLocation) {
}

void AItem::Fall(float MaxHeight) {
}

void AItem::DropBounce_Implementation() {
}

void AItem::Bounce_Implementation() {
}

void AItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AItem, InstanceData);
    DOREPLIFETIME(AItem, bOnGround);
}


