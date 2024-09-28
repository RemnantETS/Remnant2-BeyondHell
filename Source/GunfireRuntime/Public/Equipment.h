#pragma once
#include "CoreMinimal.h"
#include "AnimationHandle.h"
#include "DamageInfo.h"
#include "EquipmentAttachment.h"
#include "EquipmentDelegateDelegate.h"
#include "EquipmentModDelegateDelegate.h"
#include "EquipmentModSlot.h"
#include "InHandDelegateDelegate.h"
#include "Item.h"
#include "LoadableItemAsset.h"
#include "SoundGunfire.h"
#include "Equipment.generated.h"

class ACharacterGunfire;
class AEquipmentMod;
class AUIHud;
class UActorCustomizationComponent;
class UAnimInstanceGunfire;
class UInventoryComponent;
class UObject;
class UStatsComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipment : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomizationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentAttachment> Attachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoEnableInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldUnequip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseEquipmentAnimTimings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FallbackToCharacterTimings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopAnimsRegardlessOfTimingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportSlaveAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentModSlot> ModSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ActiveTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CharacterAnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AdditionalAnimTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire EquipSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLoadableItemAsset> EquipmentAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentDelegate OnEquippedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentDelegate OnUnequippedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentDelegate OnEquipStateUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInHandDelegate OnInHandChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentModDelegate OnModAttached;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentModDelegate OnModDetached;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationHandle CurrentAnimHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* CharacterReplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimInstanceGunfire*> AnimInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AEquipmentMod*> ModInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorCustomizationComponent* CustomizationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsActiveReplicated: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsInHandReplicated: 1;
    
public:
    AEquipment(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateEquip(ACharacterGunfire* ToCharacter);
    
    UFUNCTION(BlueprintCallable)
    void Unequip();
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetInHand(bool InHand);
    
    UFUNCTION(BlueprintCallable)
    void SetAttachmentsVisible(bool Visible);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetInHand(bool InHand);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void PostSetupInventory();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputeStats();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PostComputeCharacterStats();
    
public:
    UFUNCTION(BlueprintCallable)
    float PlayAnimation(FName AnimationID, float PlayRate, bool bCharacterOnly, FName AnimLayerOverride, int32 Seed, float StartTimeOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequipped();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnSkeletalMeshAnimInitialized();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNotInHand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInHand();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnHitTarget(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnFinishLoadingAssets();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEquipmentAssetsLoaded();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetached();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivated();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttachmentsUpdated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ModifyStat(FName Stat, float Value);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInHand() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionAllowed() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void InstanceDataChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    bool HasEquipmentAnimationEntry(FName AnimationID, FName AnimLayerOverride);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetSlaveAnimLayerOverrideFor(FName AnimationID, UPARAM(Ref) FName& InOutLayer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetModSlotIndexByNameID(FName SlotNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEquipmentModSlot GetModSlotByNameID(FName SlotNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetInventoryComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AUIHud* GetHud() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentSlotIdx();
    
    UFUNCTION(BlueprintCallable)
    AEquipmentMod* GetEquipmentMod(uint8 Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UClass* GetEquipmentAssetClass(FName AssetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetEquipmentAsset(FName AssetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCurrentAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacterGunfire* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AEquipmentMod*> GetAttachedMods();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetAnimationLayer();
    
    UFUNCTION(BlueprintCallable)
    void Detach();
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void ComputeCharacterStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAssetsLoaded() const;
    
    UFUNCTION(BlueprintCallable)
    void Activate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void _NotifyTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void _NotifyHitTarget(const FDamageInfo& DamageInfo);
    
};

