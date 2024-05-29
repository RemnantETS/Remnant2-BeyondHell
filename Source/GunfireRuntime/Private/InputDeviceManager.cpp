#include "InputDeviceManager.h"

void UInputDeviceManager::ResetKeyboardIconCache() {
}

void UInputDeviceManager::OnImageSetLoaded() {
}

bool UInputDeviceManager::IsUsingTouchController() {
    return false;
}

bool UInputDeviceManager::IsUsingKeyboardAndMouse() {
    return false;
}

bool UInputDeviceManager::IsUsingGamepadAnalogCursor(const UObject* WorldContextObject) {
    return false;
}

bool UInputDeviceManager::IsUsingGamepad() {
    return false;
}

UInputDeviceManager* UInputDeviceManager::GetInstance() {
    return NULL;
}

EInputDevice UInputDeviceManager::GetInputDeviceFromKey(const FKey Key) {
    return EInputDevice::None;
}

UObject* UInputDeviceManager::GetImage(FName NameID) {
    return NULL;
}

EInputDevice UInputDeviceManager::GetCurrentDeviceInUse(int32 ControllerId) {
    return EInputDevice::None;
}

bool UInputDeviceManager::CheckInputAction(const APlayerController* PlayerController, const FName& ActionName) {
    return false;
}

UInputDeviceManager::UInputDeviceManager() {
}

