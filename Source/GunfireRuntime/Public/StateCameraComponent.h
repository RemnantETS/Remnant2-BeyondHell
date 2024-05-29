#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Camera/CameraComponent.h"
#include "Engine/EngineTypes.h"
#include "Camera/CameraTypes.h"
#include "ButtonEvent.h"
#include "OnCameraStateChangedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "StateCameraComponent.generated.h"

class AActor;
class ACharacter;
class APlayerControllerGunfire;
class UCameraState;
class USceneComponent;
class UStateCameraComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UStateCameraComponent : public UCameraComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> DefaultCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> FlyCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> FixedCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> CinematicTransitionCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HMDComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AimBonePitchAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimBoneScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinControllerSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxControllerSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMouseSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMouseSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultCollisionInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSwimmingCameraChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> SwimmingCameraChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRecoveryAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxPlatformCamPivotSmoothTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCameraStateChangedDelegate OnCameraStateChangedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBlendingFov;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> FadedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraState* CurrentCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraState* LockedCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraState* UnlockedCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ActiveCameraActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* HMDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* AnimatedCameraActor;
    
public:
    UStateCameraComponent();
    UFUNCTION(BlueprintCallable)
    void UnlockCameraState(float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void ToggleSecondaryFlyCamera();
    
    UFUNCTION(BlueprintCallable)
    void ToggleFlyCamera(bool bUseSecondGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool Enabled);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetCameraStateByClass(TSubclassOf<UCameraState> CameraState, float BlendTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCameraState(UCameraState* State, float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimatedCameraFOV(float CameraFOV);
    
    UFUNCTION(BlueprintCallable)
    void ResetView(bool bHardReset);
    
    UFUNCTION(BlueprintCallable)
    void ResetFromCurrentView(float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void OnCinematicExitMoveEvent();
    
    UFUNCTION(BlueprintCallable)
    void OnCinematicExitInputEvent(const FName& ButtonName, ButtonEvent Event);
    
    UFUNCTION(BlueprintCallable)
    void LockCameraState();
    
    UFUNCTION(BlueprintCallable)
    void HardResetFromCamera(UStateCameraComponent* OtherCameraComponent, float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void HardReset(FMinimalViewInfo NewCameraParams, TSubclassOf<UCameraState> NewState, float BlendTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerControllerGunfire* GetPlayerController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraState* GetCurrentCamera() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetCameraTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetCameraRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCameraInputScalar(bool& OutHasLimitedControl) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCameraActor() const;
    
    UFUNCTION(BlueprintCallable)
    void ExitFlyCamera();
    
    UFUNCTION(BlueprintCallable)
    void ExitAnimatedCamera();
    
    UFUNCTION(BlueprintCallable)
    void EnterFlyCamera(bool bUseSecondGamepad);
    
    UFUNCTION(BlueprintCallable)
    void EnterAnimatedCamera(AActor* RefActor, const FName& CameraBone, bool AllowInput, float BlendTime, float BlendOutTime, float CameraFOV, bool bLockCameraState);
    
    UFUNCTION(BlueprintCallable)
    void BlendFromCurrentParams(float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void AnimatedCameraCut(AActor* RefActor, const FName& CameraBone, float CameraFOV);
    
};

