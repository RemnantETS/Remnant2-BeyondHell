#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameModeGunfire.h"
#include "OnAllPlayersDeadDelegateDelegate.h"
#include "OnDebugQuestLoadingDelegate.h"
#include "Templates/SubclassOf.h"
#include "TravelCountdownCompleteDelegateDelegate.h"
#include "WorldResetDelegateDelegate.h"
#include "ZoneLinkInfo.h"
#include "RemnantGameMode.generated.h"

class AActor;
class ACheckpoint;
class AQuest;
class ARemnantPlayerController;
class ARemnantQuest;
class UEntitlementType;
class URemnantQuestZone;
class URemnantQuestZoneLink;

UCLASS(Blueprintable, NonTransient)
class REMNANT_API ARemnantGameMode : public AGameModeGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> BaseQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> AutoLoadQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantQuest> DebugQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DebugWaypointBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DebugWithoutZone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URemnantQuestZone* DebugQuestStartZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URemnantQuestZoneLink* DebugQuestStartWaypoint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDebugQuestLoading EventOnDebugQuestLoading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARemnantQuest* PendingDebugQuestInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARemnantQuest* DebugQuestInstance;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAllPlayersDeadDelegate OnAllPlayersDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAllPlayersDeadDelegate OnFinishRespawnAllPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailResetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFailResetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoneTravelDelay;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldResetDelegate OnWorldReset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldResetDelegate OnWorldResetComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCountdownCompleteDelegate OnTravelCountdownComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle RespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle FailsafeRespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle PostDeathRespawnHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ARemnantPlayerController*> WorldResetPlayers;
    
public:
    ARemnantGameMode();
protected:
    UFUNCTION(BlueprintCallable)
    void TryRespawnPlayersPostDeath();
    
public:
    UFUNCTION(BlueprintCallable)
    void TravelToZone(int32 DestZoneID, const FName& DestLink, AActor* Source, bool bForce, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    void TravelToLastCheckpoint(AActor* Source);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetPostDeathScreenTime(float Time);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void SetChunkDownloaded(const FString& PakPath);
    
    UFUNCTION(BlueprintCallable)
    bool SetAsRootCheckpoint(const FZoneLinkInfo& NewZoneLink, bool IgnoreActive);
    
    UFUNCTION(BlueprintCallable)
    bool SetAsRespawnZoneLink(const FZoneLinkInfo& NewZoneLink, bool bIgnoreWorldState);
    
    UFUNCTION(BlueprintCallable)
    void OnStateDebugQuestLoaded(AQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    void OnSpawnDebugQuestLoaded(AQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    void OnFullGameAvailable();
    
    UFUNCTION(BlueprintCallable)
    bool IsEveryoneEntitled(TSubclassOf<UEntitlementType> RequiredEntitlement, bool ShowFailDialog, bool KickUnentitled);
    
    UFUNCTION(BlueprintCallable)
    void IncrementAllPlayersBossCounters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FZoneLinkInfo GetRespawnZoneLink();
    
    UFUNCTION(BlueprintCallable)
    void ActivateCheckpoint(ACheckpoint* Checkpoint);
    
};

