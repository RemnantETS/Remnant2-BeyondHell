#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EQuestResult.h"
#include "EntitlementInterface.h"
#include "Quest.h"
#include "QuestVoidDelegateDelegate.h"
#include "EQuestMode.h"
#include "ERemnantQuestDebugState.h"
#include "ERemnantQuestRarity.h"
#include "ERemnantQuestRewardType.h"
#include "ERemnantQuestStatus.h"
#include "ERemnantQuestType.h"
#include "QuestZonelinkEventDelegate.h"
#include "RemnantQuestBreadcrumb.h"
#include "RemnantQuestBreadcrumbInfo.h"
#include "RemnantQuestReward.h"
#include "Templates/SubclassOf.h"
#include "WorldResetInterface.h"
#include "ZoneLinkInfo.h"
#include "RemnantQuest.generated.h"

class AItem;
class ARemnantCharacter;
class ARemnantPlayerController;
class UAccountAward;
class UDataTable;
class UEntitlementType;
class UInventoryComponent;
class ULevelStreaming;
class UPersistenceComponent;
class USpawnTable;
class UVariableComponent;
class UWorld;

UCLASS(Blueprintable)
class REMNANT_API ARemnantQuest : public AQuest, public IWorldResetInterface, public IEntitlementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersistenceComponent* PersistenceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVariableComponent* VariableComponent;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestType Type;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestRarity Rarity;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUsageCount;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERemnantQuestDebugState DebugState;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsOneShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IgnoreTileExclusivity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IgnoresTileIDRequirement;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestMode QuestGameMode;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAccountAward> RequiredAward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpawnTable*> ResourceCachedSpawns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> Container;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMin;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestBreadcrumb> Breadcrumbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Difficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTimespan PlayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString BiomeName;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEntitlementType> RequiredEntitlement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableMultiplayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ItemValueTable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnCheckpointSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestZonelinkEvent OnSetRespawn;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnPreZoneLoaded;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnQuestLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnUpdateBreadcrumbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_BreadcrumbInfo, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestBreadcrumbInfo> BreadcrumbInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Status, meta=(AllowPrivateAccess=true))
    ERemnantQuestStatus Status;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastCheckpointZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FName LastCheckpointNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 RespawnZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName RespawnLinkNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* ContainerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Created;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FString, int32> UsageCount;
    
public:
    ARemnantQuest();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ShowQuestBreadcrumbs();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool ShouldBreadcrumbForName(FName Objective);
    
    UFUNCTION(BlueprintCallable)
    bool ShouldBreadcrumb(FZoneLinkInfo ZoneLink);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetRespawn(const FZoneLinkInfo& Respawn);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLastCheckpoint(const FZoneLinkInfo& Checkpoint);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Status();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_BreadcrumbInfo();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastUnloadContainerLevel();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetCheckpoint();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStaticQuest() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRootQuest() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadingOrLoaded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoaded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRespawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasQuestEntitlements() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLastCheckpoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFailedToLoad() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool HasActiveBreadcrumbs();
    
public:
    UFUNCTION(BlueprintCallable)
    void GiveRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void GiveRewardToPlayer(ARemnantCharacter* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType);
    
    UFUNCTION(BlueprintCallable)
    void GiveReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType);
    
    UFUNCTION(BlueprintCallable)
    void GiveDetailedRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, UPARAM(Ref) FRemnantQuestReward& Reward, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void GiveDetailedReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, UPARAM(Ref) FRemnantQuestReward& Reward);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FZoneLinkInfo GetRespawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetQuestLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetQuestInventory();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetQuestEntitlements(TArray<TSubclassOf<UEntitlementType>>& OutEntitlements, bool bGetMissingOnly) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetObjectQuestValue(UClass* ObjectBP, UPARAM(Ref) int32& ObjectValue, UPARAM(Ref) float& OutSellScalar, int32& OutPickupValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FZoneLinkInfo GetLastCheckpoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetBiomeName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FZoneLinkInfo> GetAutoJoinZoneLinks();
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventSetRespawn(FZoneLinkInfo ZoneLink);
    
    UFUNCTION(BlueprintCallable)
    void EventQuestComplete(AQuest* Quest, EQuestResult Result);
    
    UFUNCTION(BlueprintCallable)
    void EventAddItem(TSubclassOf<AItem> ItemBP, int32 Quantity);
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateQuest();
    
protected:
    UFUNCTION(BlueprintCallable)
    void CompleteBreadcrumb(FName BreadcrumbNameID);
    
public:
    UFUNCTION(BlueprintCallable)
    void ActivateQuestItemEvents();
    
    UFUNCTION(BlueprintCallable)
    ERemnantQuestStatus ActivateQuest();
    
    
    // Fix for true pure virtual functions not being implemented
};

