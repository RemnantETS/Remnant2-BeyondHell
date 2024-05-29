#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "OnGameStateDelegateDelegate.h"
#include "OnPlayerStateDelegateDelegate.h"
#include "GameStateGunfire.generated.h"

class AGameStateGunfire;
class APlayerState;
class UInstancedObjectReplicationManager;
class UObject;
class USequencerManager;
class UTimeDilationManager;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AGameStateGunfire : public AGameState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerStateDelegate OnPlayerJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerStateDelegate OnPlayerLeft;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeDilationManager* TimeDilationManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USequencerManager* SequencerManager;
    /*
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedObjectReplicationManager* InstancedObjectRepManager;
    */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APlayerState*> JoinQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APlayerState*> Players;
    
public:
    AGameStateGunfire();
protected:
    UFUNCTION(BlueprintCallable)
    void StartMatch();
    
public:
    UFUNCTION(BlueprintCallable)
    static void RemoveGameStateInitializedListener(const FOnGameStateDelegate& Event);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AGameStateGunfire* GetGunfireGameState(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void AddGameStateInitializedListener(const FOnGameStateDelegate& Event);
    
};

