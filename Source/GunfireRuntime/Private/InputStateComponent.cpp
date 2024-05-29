#include "InputStateComponent.h"
#include "Net/UnrealNetwork.h"

void UInputStateComponent::SetWalking(bool InIsWalking) {
}

void UInputStateComponent::SetMoveInputEnabled(bool bEnabled) {
}

void UInputStateComponent::SetInputEnabled(bool Enable) {
}

void UInputStateComponent::SetButtonStateByName(const FName& Name, ButtonEvent Event) {
}

void UInputStateComponent::ServerUpdateCameraRelativeInputDirections_Implementation(float Direction, float VerticalDirection) {
}
bool UInputStateComponent::ServerUpdateCameraRelativeInputDirections_Validate(float Direction, float VerticalDirection) {
    return true;
}

void UInputStateComponent::ResetButton(FName ButtonName) {
}

void UInputStateComponent::RemoveButtonListener(const FName& Name, const FInputButtonDelegate& Event) {
}

void UInputStateComponent::OnSwitchCamera() {
}

bool UInputStateComponent::IsMoveInputEnabled() const {
    return false;
}

bool UInputStateComponent::IsInputEnabled() const {
    return false;
}

bool UInputStateComponent::IsActionPressed(APlayerController* PlayerController, const UInputAction* InputAction) {
    return false;
}

bool UInputStateComponent::HasVerticalMoveInput() const {
    return false;
}

bool UInputStateComponent::HasMoveInput() const {
    return false;
}

bool UInputStateComponent::HasHorizontalMoveInput() const {
    return false;
}

FVector UInputStateComponent::GetScreenRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput) {
    return FVector{};
}

FVector UInputStateComponent::GetRelativeMoveInput(FRotator Rotation, bool bAllowVerticalInput) {
    return FVector{};
}

void UInputStateComponent::GetMoveInput(FVector& OutMoveInput) {
}

bool UInputStateComponent::GetIsWalking() const {
    return false;
}

bool UInputStateComponent::GetCameraRotation(FRotator& OutCameraRotation, bool bAllowSticky) {
    return false;
}

FVector UInputStateComponent::GetCameraRelativeMoveInput_UseCameraUp(bool bAllowSticky, bool bAllowVerticalInput) {
    return FVector{};
}

FVector UInputStateComponent::GetCameraRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput) {
    return FVector{};
}

ButtonEvent UInputStateComponent::GetButtonStateByName(const FName& Name) const {
    return ButtonEvent::None;
}

bool UInputStateComponent::CheckForEventByName(const FName& Name, ButtonEvent Event, float Window) const {
    return false;
}

void UInputStateComponent::AddButtonListener(const FName& Name, const FInputButtonDelegate& Event) {
}

void UInputStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UInputStateComponent, LastCameraRelativeInputDirection);
    DOREPLIFETIME(UInputStateComponent, LastCameraRelativeVerticalInputDirection);
}

UInputStateComponent::UInputStateComponent() {
    this->bRefreshButtonStatesOnSetup = false;
    this->MoveInputMethod = EMoveInputMethod::CameraRelativeYaw;
    this->StickyMovement = false;
    this->StickyMovementThreshold = 1.00f;
    this->MaxWalkingInput = 0.30f;
    this->LastCameraRelativeInputDirection = 0.00f;
    this->LastCameraRelativeVerticalInputDirection = 0.00f;
}

