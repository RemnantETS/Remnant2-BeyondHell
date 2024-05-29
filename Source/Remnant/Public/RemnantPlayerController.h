#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/TimerHandle.h"
#include "Engine/NetSerialization.h"
#include "CinematicPlayerSettings.h"
#include "EMusicState.h"
#include "PlayerControllerGunfire.h"
#include "VisitedCoordinates.h"
#include "ActionPing.h"
#include "EPingGenerationResult.h"
#include "EPlayerTravelState.h"
#include "ERemnantQuestRewardType.h"
#include "EZoneTravelLock.h"
#include "OnDeathLockEventDelegate.h"
#include "OnFindingSpawnLocationEventDelegate.h"
#include "OnGivenLicensesEventDelegate.h"
#include "OnLocalPlayerFinishedLevelSequenceDelegate.h"
#include "OnPawnChangedEventDelegate.h"
#include "OnPendingPlayStateActiveDelegate.h"
#include "OnPingFailedEventDelegate.h"
#include "OnReceiveAccountAwardDelegateDelegate.h"
#include "OnSetPawnEventDelegate.h"
#include "PlayerSpawnPrerequisites.h"
#include "QuestRewardDelegateDelegate.h"
#include "RemnantQuestReward.h"
#include "Templates/SubclassOf.h"
#include "TravelCompleteDelegateDelegate.h"
#include "ZoneLinkInfo.h"
#include "RemnantPlayerController.generated.h"

class AActor;
class ACharacterGunfire;
class ACheckpoint;
class AEventRegion;
class AItem;
class APawn;
class AQuest;
class ARemnantQuest;
class AZoneActor;
class UAccountAward;
class UActionBase;
class UArchetypeAward;
class UEmote;
class UInventoryComponent;
class UItemAward;
class UItemType;
class UNetDriver;
class UObject;
class UProgressionComponent;
class URemnantArchetype;
class URemnantTutorial;
class USpawnTable;
class UTraitsComponent;
class UUserWidget;
class UWorld;

UCLASS(Blueprintable)
class REMNANT_API ARemnantPlayerController : public APlayerControllerGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSetPawnEvent OnSetPawn;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPawnChangedEvent OnPawnChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFindingSpawnLocationEvent OnSpawnLocationQueryEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestRewardDelegate OnNotifyQuestReward;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCompleteDelegate OnFinishTravelEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCompleteDelegate OnBeginTravelEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCompleteDelegate OnClientReadyForTravel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActionBase> TravelAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelsOnDuplicateTrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepPawnWhenTraveling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerTravelState TravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelCleanupDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARemnantQuest> IntroQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IntroQuestStartLink;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLocalPlayerFinishedLevelSequence OnLocalPlayerFinishedLevelSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bPrimaryWeaponToggled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 CrossplayPlatform;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPingFailedEvent OnPingFailed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle FinishTravelHandle;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeathLockEvent OnDeathScreenUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPendingPlayStateActive OnPendingPlayStateActive;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URemnantArchetype* CachedArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URemnantArchetype* CachedSecondaryArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PendingDestinationZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DestinationZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName DestinationLink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestReward> QueuedQuestRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestReward> QueuedNotifyQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EMusicState MusicState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Respawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportsJoinAtHost;
    /*
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEQSParametrizedQueryExecutionRequest JoinHostQuery;
    */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> InvalidPlatformTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JoinAtHostTimeout;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AEventRegion*> EventRegions;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> DeathScreenContextOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LoadingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PendingTravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CinematicState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FinalizeResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AliveResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RespawnedResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DeadResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpectatingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DyingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName JoiningState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CinematicFromWorldReset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioListenerPlayerCamLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioListenerPlayerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> TeleportStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    APawn* DeadPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* CachedPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PendingRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PendingCurrencyRewards;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGivenLicensesEvent OnLicensesGiven;
    
    ARemnantPlayerController();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePlayState();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TravelPlayerTo(int32 DestZoneID, const FName& DestLink, bool bForce, bool bInstant);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SwapCharacter(const FZoneLinkInfo& StartingWaypoint);
    
    UFUNCTION(BlueprintCallable)
    void StreamActiveCharacterToServer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowTutorial(TSubclassOf<URemnantTutorial> Tutorial, AActor* ContextActor);
    
    UFUNCTION(BlueprintCallable)
    void SetReadyToTravel();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetIntroComplete();
    
    UFUNCTION(BlueprintCallable)
    void SetDeathScreenLock(bool Locked);
    
    UFUNCTION(BlueprintCallable)
    void SetDeathScreenContextClass(TSubclassOf<UUserWidget> ContextOverride);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerWorldResetComplete();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateUsingMultiplayerFeatures();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateLicensedContent(const TArray<FString>& Licenses);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockItemAward(TSubclassOf<UItemAward> ItemAward, bool bDoNotify, bool bAutoEquip);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockArchetypeAward(TSubclassOf<UArchetypeAward> ArchetypeAward, bool bDoNotify);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockAccountCurrency(TSubclassOf<AItem> CurrencyType, int32 Quantity, bool bDoNotify);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerStreamCharacterFinalize();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerStreamCharacterChunk(const TArray<uint8>& Chunk);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerStreamCharacterBegin(int32 DataSize, int32 DataSize_Compressed);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetCurrentLock(EZoneTravelLock NewLock, bool bNewIsSaving, bool bNewWantsTravelMenuAccess);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetCrossplayPlatform(uint8 ClientCrossplayPlatform);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetArchetype(const FString& NameOfBP, int32 ArchetypeLevel, int32 GearLevel, int32 Slot);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRevokeItemAward(TSubclassOf<UItemAward> ItemAward);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRespawnSwappedCharacter(int32 ZoneID, FName ZoneNameId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveTravelState();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveItem(const FString& NameOfBP, int32 Quantity);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReliableCameraLocationUpdate(FVector_NetQuantize CamLoc);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReadyToTravel();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReadyForWorldReset();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerOnDataSynchronized();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerNotifyPendingPlayStateActive(FName PendingPlayState);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectableUp(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectableToggle(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectablePrev(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectableOpen(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectableNext(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerInspectableDown(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerHandleSkipIntro();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGiveItemSilent(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGiveItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerEndInspect(AActor* Inspectable);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDestinationZoneLoaded();
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerClearWaitingForZones(int32 SyncCounter);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ServerBeginInspect(AActor* Inspectable);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddExperience(UProgressionComponent* Progression, int32 Amount);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Respawn(const FZoneLinkInfo& StartingWaypoint);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event);
    
    UFUNCTION(BlueprintCallable)
    void RefreshAccountAwards();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void QueueManualQuestReward(ARemnantQuest* Quest, const TArray<TSoftClassPtr<AItem>>& Items, bool bSkipDuplicates, bool bAutoEquip, ERemnantQuestRewardType RewardType, int32 Quantity, int32 LevelOverride, bool bIsArchetype, bool bWantsSaveOnAward);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopFindingSpawnLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartFindingSpawnLocation();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSessionDisconnected(UWorld* InWorld, UNetDriver* NetDriver);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnServerFinalizeTravel();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRootQuestLoaded(AQuest* Quest);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReadyToTravel(int32 PendingZoneID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayStateChanged(FName PreviousState, FName NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayInEditor();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDied(uint8 Reason, ACharacterGunfire* DeadCharacter, AActor* Cause);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishWorldReset(ACheckpoint* ActivatedCheckpoint);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishTravelLoad();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishTravel();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinishPlayStateTransition(FName NewState);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEntitlementsChanged();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeceased();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginWorldReset(ACheckpoint* ActivatedCheckpoint, bool bWasDead);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginTravel(int32 PendingZoneID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnAllZonesUnloaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void MarkRevived();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerDead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsIntroQuestDisabled(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsIntroQuestComplete(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool IsDeathScreenLocked();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAwardingArchetype() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasGivenLicenses();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFinishedInitialJoin() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasAccountAward(TSubclassOf<UAccountAward> Award);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSkipIntro();
    
public:
    UFUNCTION(BlueprintCallable)
    void GiveTableRewards(USpawnTable* SpawnTable, TArray<FName> SpawnTags, FRemnantQuestReward& Reward, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void GiveQuestRewards(ARemnantQuest* Quest, USpawnTable* SpawnTable, TArray<FName> SpawnTags, ERemnantQuestRewardType RewardType, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void GiveAccountAward(TSubclassOf<UAccountAward> NewAward);
    
    UFUNCTION(BlueprintCallable)
    float GetTimeSinceLastInput();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool GetTargetZoneLink(FZoneLinkInfo& OutZoneLink, bool bSkipTravelDestination) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetScalingLevelOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetRelevantInventoryComponentForItemType(TSubclassOf<UItemType> ItemType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetRelevantInventoryComponentForItem(TSubclassOf<AItem> Item) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTraitsComponent* GetPlayerTraits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetPlayerInventory() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsAwaitingSpawnLocation() const;
    
public:
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UUserWidget> GetDeathScreenContextClass();
    
    UFUNCTION(BlueprintCallable)
    AZoneActor* GetCurrentZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EZoneTravelLock GetCurrentTravelLock() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetCurrentOrDeadPawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<TSoftClassPtr<AItem>> GetAdditionalItemsForAccountAward(TSubclassOf<AItem> Item);
    
    UFUNCTION(BlueprintCallable)
    EPingGenerationResult GatherPing(FActionPing& OutPing);
    
    UFUNCTION(BlueprintCallable)
    void EnableWidgetComponentInteraction(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    int32 ComputePowerLevel();
    
    UFUNCTION(BlueprintCallable)
    int32 ComputeItemLevel();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateUsingMultiplayerFeatures(bool bEnabled);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateFogOfWar(int32 ZoneID, const FVisitedCoordinates& VisitedCoordinatesMap);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateDeathScreenContextClass(TSubclassOf<UUserWidget> ContextClass);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateAwaitingStartLocation(bool bIsFindingSpawnLocation);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateArchetype(TSubclassOf<URemnantArchetype> Archetype, bool bSecondary);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetWaitingForZones(int32 SyncCounter);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetSpawnPrerequisites(FPlayerSpawnPrerequisites Prerequisites);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetMusicState(EMusicState State);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRequestPendingPlayState(FName PendingPlayState);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRequestCinematicFromWorldReset(bool Request);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientOnSessionChanged();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyQuestReward(const FRemnantQuestReward& QuestReward);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientLoadDestinationZone(int32 DestZoneID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientIncrementBossCounter();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientHandleDeceased(bool bExitToMenu);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientGiveAccountAward(TSubclassOf<UAccountAward> NewAward);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientFinishWorldReset(ACheckpoint* ActivatedCheckpoint);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientFinishTravel(FTransform Destination);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBeginWorldReset(ACheckpoint* ActivatedCheckpoint, bool bWasDead);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBeginTravel(bool bRespawning, int32 PendingZoneID);
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearTravelLock(EZoneTravelLock Lock);
    
    UFUNCTION(BlueprintCallable)
    void ClearPawn(bool SetCurrentAsDead, bool ShouldClearDeadPawn);
    
    UFUNCTION(BlueprintCallable)
    void ClearDeadPawn();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ClearCachedSecondaryArchetype();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ClearCachedArchetype();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanRespawnPlayers() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void BroadcastPing(const FActionPing& PingRequest);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastFinishedLevelSequence(FCinematicPlayerSettings CinematicSettings, UObject* CurrentCinematic, AActor* SequenceInstigator);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastEmote(TSubclassOf<UEmote> Emote);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void BroadcastClientFinishedLevelSequence(FCinematicPlayerSettings CinematicSettings, UObject* CurrentCinematic, AActor* SequenceInstigator);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AwardArchetype(URemnantArchetype* ArchetypeClass, ARemnantQuest* Quest, ERemnantQuestRewardType RewardType, bool bUseWhitelist, TArray<TSubclassOf<AItem>> WhitelistClasses, bool bAddTraits, bool bAutoEquipArchetype, bool bAutoEquipItems, bool bSecondaryArchetype);
    
    UFUNCTION(BlueprintCallable)
    EPingGenerationResult AttemptPing();
    
    UFUNCTION(BlueprintCallable)
    void ApplyTravelLock(EZoneTravelLock Lock);
    
    UFUNCTION(BlueprintCallable)
    static void AddAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event);
    
};

