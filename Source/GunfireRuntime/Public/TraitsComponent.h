#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ETraitPointModType.h"
#include "OnTraitDelegateDelegate.h"
#include "OnTraitLevelChangedDelegateDelegate.h"
#include "OnTraitPointAddedDelegate.h"
#include "OnTraitsInitializedDelegateDelegate.h"
#include "OnTraitsPreviewCompleteDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "TraitDeferredDelegateDelegate.h"
#include "TraitInfo.h"
#include "TraitSlot.h"
#include "TraitsComponent.generated.h"

class UDataTable;
class UProgressionComponent;
class UTrait;
class UTraitType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTraitsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TraitPointsPerLevelTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TraitPointsPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxTraitPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTrait>> AvailableTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTraitSlot> TraitSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UnlockedTraitLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TraitPoints, meta=(AllowPrivateAccess=true))
    int32 TraitPoints;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTraitType>> TransientTraitTypes;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitDelegate OnTraitAddFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitLevelChangedDelegate OnTraitLevelChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitPointAdded OnTraitPointAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitsInitializedDelegate OnPostTraitsInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTraitsPreviewCompleteDelegate OnFinishPreviewing;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Traits, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> Traits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> OldTraits;
    
public:
    UTraitsComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Unequip(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetTraitInstanceData(TSubclassOf<UTrait> TraitBP, int32 NewInstanceDataValue);
    
    UFUNCTION(BlueprintCallable)
    void SetMaxLevelMod(TSubclassOf<UTrait> TraitBP, uint8 MaxLevelMod, ETraitPointModType ModType, bool bOverrideExistingLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetLevelMod(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, ETraitPointModType ModType, bool bOverrideExistingLevel);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_CorrectTraitPoints(int32 InTraitPoints);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTraitModifier(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, uint8 MaxLevelMod, ETraitPointModType ModType);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveTrait(TSoftClassPtr<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void RefundToLevel(TSubclassOf<UTrait> TraitBP, int32 DesiredLevel);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Refund(TSubclassOf<UTrait> TraitBP, int32 Amount);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Purchase(TSubclassOf<UTrait> TraitBP);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Traits();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TraitPoints();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUp();
    
    UFUNCTION(BlueprintCallable)
    void OnComputeStats();
    
public:
    UFUNCTION(BlueprintCallable)
    void MarkTraitNoLongerNew(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    void MarkPreviewingChangesComplete(bool bCanceled);
    
    UFUNCTION(BlueprintCallable)
    void MarkPreviewingChanges();
    
    UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm = "OnUnlockedTrait"))
    void K2_UnlockTraitSoft(TSoftClassPtr<UTrait> TraitBP, const FTraitDeferredDelegate& OnUnlockedTrait, int32 StartingLevel, bool bAllowAutoEquip);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTraitInfo K2_GetTraitInfoForSlot(int32 SlotIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTraitInfo K2_GetTraitInfo(TSoftClassPtr<UTrait> TraitBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTraitTransient(TSubclassOf<UTrait> TraitBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTraitSlotUnlocked(int32 SlotIndex, bool ValidateHasTraits) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTraitOfType(TSubclassOf<UTrait> TraitBP, TSubclassOf<UTraitType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPreviewingTraitChanges() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTraitByType(TSubclassOf<UTraitType> Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTraitByName(const FName& NameID, int32 RequiredLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTrait(TSoftClassPtr<UTrait> TraitBP, int32 RequiredLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitMaxLevel(TSubclassOf<UTrait> TraitBP, bool ApplyModifiers) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitLevel(TSoftClassPtr<UTrait> TraitBP, bool ApplyModifiers) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitInstanceData(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalArchetypeLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UProgressionComponent* GetProgression() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetOverallocatedPoints(TSubclassOf<UTrait> TraitBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetMaxLevelMods(TSubclassOf<UTrait> TraitBP, bool bGetAllMods, ETraitPointModType ModType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetLevelMods(TSubclassOf<UTrait> TraitBP, bool bGetAllMods, ETraitPointModType ModType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquippedArchetypeLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTraitInfo> GetAvailableTraits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAvailableTraitPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTraitInfo> GetAllTraits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAllocatedTraitPoints() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Equip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyTraitPointsAdded(int32 Points);
    
    UFUNCTION(BlueprintCallable)
    bool CanPurchase(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    bool CanEquip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    int32 AddTraitPoints(int32 Points, bool BroadcastNotify);
    
    UFUNCTION(BlueprintCallable)
    void AddTraitModifier(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, uint8 MaxLevelMod, ETraitPointModType ModType, bool OverrideExistingLevel);
    
};

