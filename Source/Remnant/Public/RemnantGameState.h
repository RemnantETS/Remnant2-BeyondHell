#pragma once
#include "CoreMinimal.h"
#include "GameStateGunfire.h"
#include "EZoneTravelLock.h"
#include "FinishTravelEventDelegate.h"
#include "OnClientJoinBeginSpectateDelegate.h"
#include "OnZoneTravelStateChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "ZoneTravelState.h"
#include "RemnantGameState.generated.h"

class AActor;
class ACheckpoint;
class APlayerState;
class UObject;
class URemnantPingManager;
class UTwitchIntegrationManager;

UCLASS(Blueprintable)
class REMNANT_API ARemnantGameState : public AGameStateGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bTestMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelCountdownAdditionalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Replicated, Transient, meta=(AllowPrivateAccess=true))
    URemnantPingManager* PingManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URemnantPingManager> PingManagerType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnZoneTravelStateChanged OnZoneTravelStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFinishTravelEvent OnAllPlayersFinishedTravel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnClientJoinBeginSpectate OnClientJoinBeginSpectate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ZoneTravelState, meta=(AllowPrivateAccess=true))
    FZoneTravelState ZoneTravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActivatedCheckpoint, meta=(AllowPrivateAccess=true))
    ACheckpoint* ActivatedCheckpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACheckpoint* DeactivatingCheckpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTwitchIntegrationManager* TwitchIntegrationManager;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACheckpoint* PreviouslyActivatingCheckpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TravelCountdownSource;
    
public:
    ARemnantGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ZoneTravelState();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActivatedCheckpoint();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NotifyClientJoinBeginSpectate(APlayerState* Player);
    
private:
    UFUNCTION(BlueprintCallable)
    void LogStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsZoneTravelPending(const UObject* WorldContextObject, float& OutTimeRemaining);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsZoneTravelAvailable(const UObject* WorldContextObject, EZoneTravelLock& OutReason, AActor* Source, bool bIsTravelMenu, float AdditionalDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTravelPending(float& OutTimeRemaining) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTravelAvailable(EZoneTravelLock& OutReason, AActor* Source, bool bIsTravelMenu, float AdditionalDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ACheckpoint* GetActivatedCheckpoint(const UObject* WorldContextObject, bool bIncludeDeactivatingCheckpoint);
    
};

