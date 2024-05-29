#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EInventoryAccess.h"
#include "EItemNotifyReason.h"
#include "EquipmentSlot.h"
#include "InventoryAddItemDelegate.h"
#include "InventoryAddedItemDelegate.h"
#include "InventoryChangedDelegateDelegate.h"
#include "InventoryEquipEventDelegate.h"
#include "InventoryEquipmentActivationDelegate.h"
#include "InventoryEquipmentModEventDelegate.h"
#include "InventoryFullDelegateDelegate.h"
#include "InventoryInHandEventDelegate.h"
#include "InventoryItem.h"
#include "InventoryItemLeveledUpDelegate.h"
#include "InventoryPickupItemDelegate.h"
#include "InventoryResult.h"
#include "InventorySold.h"
#include "InventoryTransactItemDelegate.h"
#include "InventoryUpgradeItemDelegate.h"
#include "InventoryUseItemDelegate.h"
#include "Templates/SubclassOf.h"
#include "InventoryComponent.generated.h"

class AActor;
class AEquipment;
class AItem;
class UInventoryComponent;
class UItemInstanceData;
class UItemType;
class UNiagaraSystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UInventoryComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMerchant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EInventoryAccess Accessibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> EquipmentInHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> LastEquipmentInHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> CurrencyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> MetalType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* DefaultLootFX;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryChangedDelegate OnInventoryChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryItemLeveledUp OnLeveledUp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryUseItem OnUsedItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryAddItem OnAddItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryTransactItem OnAttemptTakeItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryPickupItem OnPickupItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryPickupItem OnPickupItemServer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryUpgradeItem OnUpgradeItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryFullDelegate OnInventoryFull;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipmentActivation OnEquipmentActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipmentActivation OnEquipmentDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipEvent OnEquippedItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipEvent OnUnequippedItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryInHandEvent OnEquipmentInHand;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipmentModEvent OnEquipmentModAttached;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInventoryEquipmentModEvent OnEquipmentModDetached;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 IDGen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Items, meta=(AllowPrivateAccess=true))
    TArray<FInventoryItem> Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentSlot> EquipmentSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FInventorySold> PriceScaling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoPriceScaling;
    
public:
    UInventoryComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    bool UseItem(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    bool UnequipItemByID(const int32 ItemId);
    
    UFUNCTION(BlueprintCallable)
    bool UnequipItemAtSlotIndex(const int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    bool UnequipItem(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    void ToggleActiveItem(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    void TakeItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity, int32 LevelOverride);
    
    UFUNCTION(BlueprintCallable)
    void TakeAll(AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void SwapItem(TSubclassOf<AItem> From, TSubclassOf<AItem> To);
    
    UFUNCTION(BlueprintCallable)
    bool SetQuantity(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason);
    
    UFUNCTION(BlueprintCallable)
    bool SetItemLevel(TSubclassOf<AItem> ItemBP, int32 LevelToSet);
    
    UFUNCTION(BlueprintCallable)
    void SetEquipmentInHandById(int32 EquipmentId);
    
    UFUNCTION(BlueprintCallable)
    void SetEquipmentInHandByClass(TSubclassOf<AEquipment> Equipment);
    
    UFUNCTION(BlueprintCallable)
    void SetEquipmentInHand(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveItemByClass(TSubclassOf<AEquipment> Equipment);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveItem(TSubclassOf<UItemType> Type);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUseItem(TSubclassOf<AItem> ItemBP);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnequipMod(int32 ItemId, uint8 Slot, bool AddToInventory);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnequipItemByID(int32 ItemId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerToggleActiveItem(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTakeItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTakeAll(AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetEquipmentInHand(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetActiveItem(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPutItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPickupItem(AItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPickupAndEquipItem(AItem* Item, int32 SlotIndex, bool InHand);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerEquipSkin(int32 ItemId, int32 SkinID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerEquipItemByID(int32 ItemId, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropItemByID(int32 ItemId, int32 Quantity, bool Force);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDetachItem(int32 ItemId);
    
public:
    UFUNCTION(BlueprintCallable)
    void RouteNotifyPickupItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveItemByID(int32 ID, int32 Quantity, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveItem(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllItems();
    
    UFUNCTION(BlueprintCallable)
    void PutItemByID(AActor* OtherActor, int32 ItemId, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void PickupItem(AItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void PickupAndEquipItem(AItem* Item, int32 SlotIndex, bool InHand);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Items();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnInstanceDataVisuallyChanged();
    
    UFUNCTION(BlueprintCallable)
    void NotifyUsedItem(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    void NotifyPickupItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastOnInventoryChanged();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void MarkNotNew(const int32 ItemId);
    
    UFUNCTION(BlueprintCallable)
    void MarkFavorited(const int32 ItemId, bool Favorited);
    
    UFUNCTION(BlueprintCallable)
    void K2_AddItemSoft(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason, const FInventoryAddedItem& OnAdded, bool ForceEquip, bool SendNotification);
    
    UFUNCTION(BlueprintCallable)
    FInventoryResult K2_AddItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, EItemNotifyReason Reason, bool bAllowAutoEquip);
    
    UFUNCTION(BlueprintCallable)
    bool IsInventoryItemInfiniteByType(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    bool IsInventoryItemInfiniteByID(UInventoryComponent* Inventory, const int32 ItemId);
    
    UFUNCTION(BlueprintCallable)
    bool IsInventoryItemInfinite(const FInventoryItem& InventoryItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquippedByID(const int32 ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipped(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasNewItemInInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasItemByType(TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasItem(TSoftClassPtr<AItem> ItemBP, int32 Quantity, int32 ItemLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEquippedItemByType(TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEquipmentSlot(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetSellValue(int32 Cost, float SellScalar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetQuantity(TSoftClassPtr<AItem> ItemBP, int32 ItemLevel) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetPreviousItem(int32 CurrentID, FInventoryItem& OutItem, TSubclassOf<UItemType> Type, bool bWrapAround);
    
    UFUNCTION(BlueprintCallable)
    bool GetNextItem(int32 CurrentID, FInventoryItem& OutItem, TSubclassOf<UItemType> Type, bool bWrapAround);
    
    UFUNCTION(BlueprintCallable)
    AEquipment* GetNextActiveItem(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetItemTypeBySlotName(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetItemType(const AItem* Item) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryItem> GetItems();
    
    UFUNCTION(BlueprintCallable)
    UItemInstanceData* GetItemInstanceData(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UInventoryComponent* GetInventoryForItemType(AActor* Actor, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UInventoryComponent* GetInventoryForItemSoft(AActor* Actor, TSoftClassPtr<AItem> Item);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UInventoryComponent* GetInventoryForItem(AActor* Actor, TSubclassOf<AItem> Item);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHighestLevelForItem(TSoftClassPtr<AItem> ItemBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquippedItemBySlotName(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquippedItemByClass(TSubclassOf<AEquipment> Equipment) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquippedItem(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetEquipmentSlotNameForItem(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentSlotIndexBySlotName(FName SlotName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentSlotIndexByNameID(FName SlotNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentSlotIndex(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEquipmentSlot GetEquipmentSlotByNameID(FName SlotNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentItemID(AEquipment* EquippedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquipmentInHand() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetBuyValue(UInventoryComponent* OtherInventory, int32 ItemId, int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetActiveItem(TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemType> GetActivationTypeBySlotName(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    FInventoryItem FindItemByID(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    FInventoryItem FindItemByEquipSlotNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FInventoryItem FindItem(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    void EquipSkin(int32 ItemId, int32 SkinID);
    
    UFUNCTION(BlueprintCallable)
    bool EquipItemWithTransform(const int32 ItemId, const int32 SlotIndex, FTransform Transform);
    
    UFUNCTION(BlueprintCallable)
    bool EquipItemByID(const int32 ItemId, const int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    bool EquipItem(TSubclassOf<AItem> ItemBP, const int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void DropItemByID(const int32 ItemId, int32 Quantity, bool Force);
    
    UFUNCTION(BlueprintCallable)
    void DropItem(TSubclassOf<AItem> ItemBP, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void DropAll();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DidActiveItemChange(TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable)
    void DetachItemByID(const int32 ItemId);
    
    UFUNCTION(BlueprintCallable)
    int32 CountItemByType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyUpgradeItem(TSubclassOf<AItem> ItemBP, int32 Level);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyTakeItemResult(TSubclassOf<AItem> ItemBP, int32 Quantity, bool DidTakeItem);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyPickupItemInstance(AItem* Item, int32 Quantity, int32 Level, EItemNotifyReason Reason, bool bBroadcastNotify);
    
private:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyPickupItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 Level, EItemNotifyReason Reason);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientNotifyInventoryFull(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientForceUseItem(int32 ItemId);
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanEquipItemByID(const int32 ItemId, const int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    bool CanAutoEquip(TSubclassOf<AItem> ItemBP, bool ManualRequest);
    
    UFUNCTION(BlueprintCallable)
    bool CanAddItem(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable)
    void AutoPickupAndEquipItem(AItem* Item, bool InHand);
    
    UFUNCTION(BlueprintCallable)
    bool AutoEquipItemByID(const int32 ItemId, bool ForceEquip);
    
    UFUNCTION(BlueprintCallable)
    bool AutoEquipItem(TSubclassOf<AItem> ItemBP, bool ForceEquip);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddInfiniteItem(TSubclassOf<AItem> ItemBP);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftClassPtr<AItem> ActorToItem(TSoftClassPtr<AActor> Item);
    
};

