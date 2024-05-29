#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ClimbableSurfaceResult.h"
#include "EInteractiveResult.h"
#include "HitReactionType.h"
#include "InteractiveDelegateDelegate.h"
#include "LadderReference.h"
#include "ManagedTickInterface.h"
#include "StateChangeDelegateDelegate.h"
#include "StateCompleteDelegateDelegate.h"
#include "StateID.h"
#include "StateInfo.h"
#include "StateMachineComponent.generated.h"

class AActor;
class ACharacterGunfire;
class UActorState;
class UAnimInstanceGunfire;
class UHitReactionState;
class USceneComponent;
class UStateMachine;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UStateMachineComponent : public UActorComponent, public IManagedTickInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateChangeDelegate OnStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateCompleteDelegate OnStateComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateCompleteDelegate OnStateInterruptUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractiveDelegate OnInteractive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStateMachine* StateMachine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FName StartState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlinchAnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Secondary;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InteractCullComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLadderReference CurrentLadder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActorState* CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentStateInfo, meta=(AllowPrivateAccess=true))
    FStateInfo CurrentStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* OverrideAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CachedInteractCullComponent;
    
public:
    UStateMachineComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetWindow(const FName& Name);
    
    UFUNCTION(BlueprintCallable)
    void SetEvent(const FName& Name);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetTraversalState(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetState(FStateID StateID, float LockDirection, uint8 CurrentClientAck);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetLadder(const FLadderReference& LadderReference);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetInteractiveResult(EInteractiveResult State, float MashValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetClimbingState(FStateID StateID, const FClimbableSurfaceResult& ClimbableSurface, uint8 CurrentClientAck);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerResendInteractive(uint16 StateChangeID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoInteractive(const FName& NameID, AActor* Other, bool bOnlyIfValid);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ResetStateToDefault(bool bOnlySetIfValid);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentStateInfo();
    
    UFUNCTION(BlueprintCallable)
    void OnPostComputeStats();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDoFlinchWithHitLocationIgnoreClient(UHitReactionState* HitReaction, const FName& HitLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDoFlinchWithHitLocation(UHitReactionState* HitReaction, const FName& HitLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDoFlinchIgnoreClient(UHitReactionState* HitReaction);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDoFlinch(UHitReactionState* HitReaction);
    
public:
    UFUNCTION(BlueprintCallable)
    bool K2_SetState(FName NameID, bool bOnlySetIfValid);
    
    UFUNCTION(BlueprintCallable)
    bool IsWindowSet(const FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInterruptible() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsEventSet(const FName& Name);
    
    UFUNCTION(BlueprintCallable)
    void InitAnimInstance();
    
    UFUNCTION(BlueprintCallable)
    bool InInteractive();
    
    UFUNCTION(BlueprintCallable)
    bool HasPendingInterrupt();
    
    UFUNCTION(BlueprintCallable)
    FName GetStateName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPendingInteractiveOther() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteractiveOther() const;
    
    UFUNCTION(BlueprintCallable)
    HitReactionType GetHitReactionType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElapsedStateTime() const;
    
    UFUNCTION(BlueprintCallable)
    FString GetDebugInfo(int32 DebugLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetCurrentState();
    
    UFUNCTION(BlueprintCallable)
    bool DoInteractive(const FName& NameID, AActor* Other, bool bOnlyIfValid);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetState(FStateID State, float LockDirection, uint8 CurrentClientAck);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientFailedLadderOccupancy();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientDoInteractive(FStateInfo Info, uint8 NewClientAck);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAbortInteractive();
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearWindow(const FName& Name, bool bClearAll);
    
    UFUNCTION(BlueprintCallable)
    void BeginLerp(float Time, bool LerpPosition, bool LerpRotation, bool EaseIn, float EaseExponent, bool ForceClearPreviousLerp);
    
    
    // Fix for true pure virtual functions not being implemented
};

