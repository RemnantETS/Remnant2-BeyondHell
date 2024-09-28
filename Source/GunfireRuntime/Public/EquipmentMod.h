#pragma once
#include "CoreMinimal.h"
#include "DamageSourceInterface.h"
#include "EquipmentModData.h"
#include "InspectInfo.h"
#include "Item.h"
#include "LoadableItemAsset.h"
#include "Templates/SubclassOf.h"
#include "EquipmentMod.generated.h"

class AActor;
class ACharacterGunfire;
class AEquipment;
class AEquipmentMod;
class UInventoryComponent;
class UObject;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipmentMod : public AItem, public IDamageSourceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Hidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ReplicateMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanBeRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomizationSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomizationID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AEquipment* EquipOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 EquippedSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 EquippedLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLoadableItemAsset> EquipmentModAssets;
    
public:
    AEquipmentMod(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ValidateAttach(ACharacterGunfire* ToCharacter) const;
    
    UFUNCTION(BlueprintCallable)
    static bool UnequipMod(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, bool AddToInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostComputeStats() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinishLoadingAssets();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEquipmentModAssetsLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipmentInHandEvent(bool InHand);
    
    UFUNCTION(BlueprintCallable)
    void OnEquipmentEquipStateUpdated(AEquipment* Equipment);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDetached();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnComputeStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAttached();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ModifyStat(FName Stat, float Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasItemOrEquippedMod(UInventoryComponent* Inventory, TSoftClassPtr<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetSlot() const;
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetPreviewInspectInfoFromInventory(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, int32 ModItemID);
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetPreviewInspectInfo(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel);
    
    UFUNCTION(BlueprintCallable)
    static bool GetInspectInfoForModBySlotName(AActor* Actor, UInventoryComponent* Inventory, int32 ItemId, FName Slot, FInspectInfo& Rtn);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UClass* GetEquipmentModAssetClass(FName AssetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetEquipmentModAsset(FName AssetName) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquipment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool FindEquippedModInInventory(UInventoryComponent* Inventory, TSoftClassPtr<AItem> Mod, int32& OutItemID, FEquipmentModData& OutModData);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipModFromInventory(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, int32 ModItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipMod(UInventoryComponent* Inventory, int32 ItemId, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel, int32 ModItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool CanEquipMod(ACharacterGunfire* Character, TSubclassOf<AEquipmentMod> Mod);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreEquipmentModAssetsLoaded() const;
    

    // Fix for true pure virtual functions not being implemented
};

