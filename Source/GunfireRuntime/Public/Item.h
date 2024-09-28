#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "EntitlementInterface.h"
#include "ImpactEffectSelector.h"
#include "InspectInfo.h"
#include "InventoryItem.h"
#include "ItemInventoryInteractionDelegateDelegate.h"
#include "SoundGunfire.h"
#include "StatValue.h"
#include "Templates/SubclassOf.h"
#include "Item.generated.h"

class AItem;
class APawn;
class APlayerControllerGunfire;
class UEntitlementType;
class UInventoryComponent;
class UItemCategory;
class UItemInstanceData;
class UItemSocketComponent;
class UItemType;
class UNiagaraComponent;
class UNiagaraSystem;
class UPersistenceComponent;
class UTexture2D;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AItem : public AActor, public IEntitlementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersistenceComponent* PersistenceComp;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemCategory> Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> FilterTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxStackCount;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseMaxQuantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatValue MaxQuantityBonusStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatValue MaxQuantityMultiplierStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool KeepInInventoryWithNoQuantity;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    UItemInstanceData* InstanceData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Stats;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Unique;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsQuantityToSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = "true"))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = "true"))
    FText PickupDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = "true"))
    FText FlavorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> LargeIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* HUDIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> InspectActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Interactable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseInteractInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InteractLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InteractIconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* InteractIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire PickupSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupChanceApplyModStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupModStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupScalarStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LootFxAttachNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* LootFxOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoBounce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BounceAnimRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire BounceFlipSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire BounceSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactEffectSelector DroppedImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* RequiredAccountAward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEntitlementType> RequiredEntitlement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool bOnGround;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemInventoryInteractionDelegate OnCollected;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* LootFxParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Inspecting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemSocketComponent* ItemSocket;
    
public:
    AItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateAdd(UInventoryComponent* Inventory, int32 DesiredQuantity, int32& AllowedQuantity);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void SetupItemInInventory(UInventoryComponent* Inventory, const FInventoryItem& Item);
    
    UFUNCTION(BlueprintCallable)
    void SetQuantity(int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void SetNewStatsHandle(FDataTableRowHandle InStatsHandle);
    
    UFUNCTION(BlueprintCallable)
    void SetLevel(uint8 Level);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void SetFallLocation(FVector NewRootLocation, FVector NewRelativeLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PreAdd(UInventoryComponent* Inventory, UPARAM(Ref) int32& Quantity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PickupPreAdd(UInventoryComponent* Inventory, UPARAM(Ref) int32& Quantity, int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PickupItem(UInventoryComponent* Inventory);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_InstanceData(UItemInstanceData* PrevData);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPickupFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPickedUp(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDropped();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, UPARAM(Ref) FInspectInfo& Info, bool& HideBaseStats);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LevelChanged(UInventoryComponent* Inventory, int32 ItemId, UItemInstanceData* ItemInstanceData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitializeLootFxForLocalPawn(APawn* Pawn);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetSubLabel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetRewardForMaxStackPickup(UInventoryComponent* Inventory, int32 Level, TSubclassOf<AItem>& OutRewardClass, int32& OutQuantity, int32& OutLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetRewardForLowerQualityPickup(UInventoryComponent* Inventory, int32 Level, TSubclassOf<AItem>& OutRewardClass, int32& OutQuantity, int32& OutLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetQuantity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxQuantity(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetLabel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemSocketComponent* GetItemSocket() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    uint8 GetItemLevel() const;
    
    UFUNCTION(BlueprintCallable)
    FInspectInfo GetInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, int32 LevelOverride);
    
    UFUNCTION(BlueprintCallable)
    void FallTo(const FVector& NewLocation);
    
    UFUNCTION(BlueprintCallable)
    void Fall(float MaxHeight);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DropBounce();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Bounce();
    

    // Fix for true pure virtual functions not being implemented
};

