#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/NetSerialization.h"
#include "EPortalRenderState.h"
#include "KinematicInterface.h"
#include "OnActorEnterPortalEventDelegate.h"
#include "OnTargetPortalChangedEventDelegate.h"
#include "PortalActorTransition.h"
#include "SoundGunfire.h"
#include "Portal.generated.h"

class APlayerController;
class APortal;
class UBoxComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class USceneCaptureComponent2D;
class USceneComponent;
class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APortal : public AActor, public IKinematicInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* SceneCapture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PortalRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* PortalTriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UprightCosineThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultEnterTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultExitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoplanarAlignmentAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DefaultPortalScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterScaleStartAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterScaleStopAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitScaleStartAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitScaleStopAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange EjectionForceRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowAICharacterTraversal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumEntryDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterCosineThresh;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSquareRenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumRenderDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrawRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterSnapToGroundDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterMinimumEnterHeightScale;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValidateExitCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* DefaultEnterVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire DefaultEnterSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* DefaultExitVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire DefaultExitSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreHitscanImpactEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* DefaultHitscanEnterVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire DefaultHitscanEnterSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* DefaultHitscanExitVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire DefaultHitscanExitSFX;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPoolRenderTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetPortalChangedEvent OnTargetPortalChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActorEnterPortalEvent OnActorEnterPortal;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPortalActorTransition> Transitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TargetPortal, meta=(AllowPrivateAccess=true))
    APortal* TargetPortal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Replicated, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* AttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FTransform RelativeAttachTransform;
    
public:
    APortal();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateVisuals(EPortalRenderState State, APortal* RenderingPortal);
    
public:
    UFUNCTION(BlueprintCallable)
    static FRotator TransformRotationBetweenPortals(FRotator Rotation, APortal* EntryPortal, APortal* ExitPortal);
    
    UFUNCTION(BlueprintCallable)
    static FQuat TransformQuatBetweenPortals(FQuat Rotation, APortal* EntryPortal, APortal* ExitPortal);
    
    UFUNCTION(BlueprintCallable)
    static FVector TransformLocationBetweenPortals(FVector Location, APortal* EntryPortal, APortal* ExitPortal);
    
    UFUNCTION(BlueprintCallable)
    static FVector TransformDirectionBetweenPortals(FVector Direction, APortal* EntryPortal, APortal* ExitPortal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ShouldRenderPortal() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupRenderTarget(UTextureRenderTarget2D* NewRenderTarget);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupFixedView(USceneCaptureComponent2D* OtherSceneCapture);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetTargetPortal(APortal* NewPortal);
    
    UFUNCTION(BlueprintCallable)
    static bool ProjectWorldLocationThroughPortal(APlayerController* Controller, FVector WorldLocation, APortal* EntryPortal, APortal* ExitPortal, FVector& ProjectedLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTargetChanged();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_TargetPortal();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartTransition(AActor* Actor, FVector_NetQuantize RelativeTargetLocation, FVector_NetQuantize RelativeTransitionAxis, APortal* TransitionTargetPortal, const TArray<AActor*>& ActorsToAttach, float EnterTime, float ExitTime);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPortalUpright() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActorEnteringPortal(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActorDoingAnyPortalTransition(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyActorTransitions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APortal* GetTargetPortal() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTextureRenderTarget2D* GetRenderTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPortalRenderState GetPortalRenderState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetEventHorizonTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPlane GetEventHorizonPlane() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UPrimitiveComponent* GetEventHorizonComponent() const;
    
    UFUNCTION(BlueprintCallable)
    bool EnterPortal(AActor* Actor, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    static FVector CalculateRelativeTransitionAxis(AActor* Actor, APortal* Portal);
    
    UFUNCTION(BlueprintCallable)
    static FVector CalculatePortalEntryLocationForPrediction(AActor* Projectile, const FVector& Velocity, APortal* Portal, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    static FVector CalculatePortalEntryLocationForActor(AActor* Actor, APortal* Portal, const FVector& WorldLocation);
    
    UFUNCTION(BlueprintCallable)
    static FBox CalculateBoundsForActor(AActor* Actor, const FTransform Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ArePortalTransitionsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ApplyEjectionForce(AActor* Actor, APortal* EntryPortal, UPARAM(Ref) FVector& EjectionForce);
    
    
    // Fix for true pure virtual functions not being implemented
};

