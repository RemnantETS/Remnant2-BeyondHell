#include "StateCameraComponent.h"
#include "Templates/SubclassOf.h"

void UStateCameraComponent::UnlockCameraState(float BlendTime) {
}

void UStateCameraComponent::ToggleSecondaryFlyCamera() {
}

void UStateCameraComponent::ToggleFlyCamera(bool bUseSecondGamepad) {
}

void UStateCameraComponent::SetInputEnabled(bool Enabled) {
}

void UStateCameraComponent::SetCameraStateByClass(TSubclassOf<UCameraState> CameraState, float BlendTime) {
}

void UStateCameraComponent::SetCameraState(UCameraState* State, float BlendTime) {
}

void UStateCameraComponent::SetAnimatedCameraFOV(float CameraFOV) {
}

void UStateCameraComponent::ResetView(bool bHardReset) {
}

void UStateCameraComponent::ResetFromCurrentView(float BlendTime) {
}

void UStateCameraComponent::OnCinematicExitMoveEvent() {
}

void UStateCameraComponent::OnCinematicExitInputEvent(const FName& ButtonName, ButtonEvent Event) {
}

void UStateCameraComponent::LockCameraState() {
}

void UStateCameraComponent::HardResetFromCamera(UStateCameraComponent* OtherCameraComponent, float BlendTime) {
}

void UStateCameraComponent::HardReset(FMinimalViewInfo NewCameraParams, TSubclassOf<UCameraState> NewState, float BlendTime) {
}

APlayerControllerGunfire* UStateCameraComponent::GetPlayerController() const {
    return NULL;
}

UCameraState* UStateCameraComponent::GetCurrentCamera() const {
    return NULL;
}

ACharacter* UStateCameraComponent::GetCharacter() const {
    return NULL;
}

FTransform UStateCameraComponent::GetCameraTransform() const {
    return FTransform{};
}

FRotator UStateCameraComponent::GetCameraRotation() const {
    return FRotator{};
}

FVector UStateCameraComponent::GetCameraLocation() const {
    return FVector{};
}

float UStateCameraComponent::GetCameraInputScalar(bool& OutHasLimitedControl) const {
    return 0.0f;
}

AActor* UStateCameraComponent::GetCameraActor() const {
    return NULL;
}

void UStateCameraComponent::ExitFlyCamera() {
}

void UStateCameraComponent::ExitAnimatedCamera() {
}

void UStateCameraComponent::EnterFlyCamera(bool bUseSecondGamepad) {
}

void UStateCameraComponent::EnterAnimatedCamera(AActor* RefActor, const FName& CameraBone, bool AllowInput, float BlendTime, float BlendOutTime, float CameraFOV, bool bLockCameraState) {
}

void UStateCameraComponent::BlendFromCurrentParams(float BlendTime) {
}

void UStateCameraComponent::AnimatedCameraCut(AActor* RefActor, const FName& CameraBone, float CameraFOV) {
}

UStateCameraComponent::UStateCameraComponent() {
    this->DefaultCameraState = NULL;
    this->FlyCameraState = NULL;
    this->FixedCameraState = NULL;
    this->CinematicTransitionCameraState = NULL;
    this->AimBoneScale = 1.00f;
    this->MinControllerSensitivityScalar = 0.12f;
    this->MaxControllerSensitivityScalar = 8.00f;
    this->MinMouseSensitivityScalar = 0.12f;
    this->MaxMouseSensitivityScalar = 8.00f;
    this->DefaultCollisionInterpSpeed = 0.00f;
    this->bOverrideSwimmingCameraChannel = false;
    this->SwimmingCameraChannel = ECC_Camera;
    this->MaxRecoveryAngle = -1.00f;
    this->MaxPlatformCamPivotSmoothTime = 0.00f;
    this->bIsBlendingFov = false;
    this->Character = NULL;
    this->CurrentCamera = NULL;
    this->LockedCamera = NULL;
    this->UnlockedCamera = NULL;
    this->ActiveCameraActor = NULL;
    this->HMDComponent = NULL;
    this->AnimatedCameraActor = NULL;
}

