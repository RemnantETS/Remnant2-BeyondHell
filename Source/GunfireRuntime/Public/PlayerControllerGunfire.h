#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerController.h"
#include "CinematicDelegateDelegate.h"
#include "EPlayerJoinState.h"
#include "OnStartedVisualLoggerDelegate.h"
#include "SpectateTargetChangedDelegateDelegate.h"
#include "PlayerControllerGunfire.generated.h"

class AActor;
class APawn;
class APlayerStateGunfire;
class UDamageValidationComponent;
class UInputMappingContext;
class UObject;
class UPlayStateComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayerControllerGunfire : public APlayerController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStartedVisualLogger OnStartedVisualLogger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputMappingContext* InputMappingContext;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UInputMappingContext* RuntimeManagedMappingContext;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateTargetChangedDelegate OnSpectateTargetChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SpectateTarget, meta=(AllowPrivateAccess=true))
    AActor* SpectateActor;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayStateComponent* PlayState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageValidationComponent* DamageValidationComponent;
    
    APlayerControllerGunfire();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SpectateTarget(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void SpectatePrevPlayer();
    
    UFUNCTION(BlueprintCallable)
    void SpectateNextPlayer();
    
    UFUNCTION(BlueprintCallable)
    void SetGameInputEnabled(bool bEnabled, const bool bFlushInput);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetAdditionalNetRelevanceTarget(bool bAdd, AActor* Actor, FRotator Rot);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateEntitlement(int32 PlayerId, const FSoftObjectPath& Entitlement, bool Grant);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockAllTraitsOfType(const FString& NameOfBP, int32 StartingLevel);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpectateTarget(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpawnCharacter(UClass* ClassToSpawn, FTransform SpawnTransform, AActor* SpawnOwner);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetPlayerNormalizedHealth(float Health);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerRequestTime(uint16 ClientTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveTrait(const FString& NameOfBP);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoConsoleCommand(const FString& Command);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoAction(const FString& NameOfBP, bool bApplyToTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerBeginSpectate();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddTrait(const FString& NameOfBP, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void RestoreSpectateViewTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool RestartPlayer();
    
    UFUNCTION(BlueprintCallable)
    void ResetPauseRefCount();
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCinematicListener(const FCinematicDelegate& Event);
    
protected:
    UFUNCTION(BlueprintCallable)
    void QuitGame();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ProposeToSkipCutscene(UObject* InSequence);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SpectateTarget();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginPlaying();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSynchronizingData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpectating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJoiningAsSpectator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJoiningAsPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJoining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCinematic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGameInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFlaggedAsSpectator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDisconnected() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasLicense(const FString& License);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasJoined() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSpectateTarget();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetRelevantViewTarget();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetRelevantPawn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerIdentifier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPotentialSpectateTargets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPlayerJoinState GetJoinState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerStateGunfire* GetGunfirePlayerState() const;
    
    UFUNCTION(Client, Unreliable)
    void ClientTimeReply(uint16 ServerTime, uint16 ClientTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSpectate() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginSpectate();
    
    UFUNCTION(BlueprintCallable)
    void BeginPlaying();
    
    UFUNCTION(BlueprintCallable)
    static void AddCinematicListener(const FCinematicDelegate& Event);
    
};

