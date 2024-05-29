#include "RemnantGameInstance.h"

void URemnantGameInstance::SetInFullscreenDialog(bool InDialog) {
}

void URemnantGameInstance::OnOnlinePrivilegeChecked() {
}

void URemnantGameInstance::OnMainMenuLoaded() {
}

void URemnantGameInstance::OnDeviceChanged(int32 ControllerId, EInputDevice NewDevice) {
}

void URemnantGameInstance::OnActiveProfileSet() {
}

void URemnantGameInstance::OnActiveProfileCleared() {
}


bool URemnantGameInstance::IsDemo() {
    return false;
}

void URemnantGameInstance::Host() {
}

ERemnantDemoMode URemnantGameInstance::GetDemoMode() {
    return ERemnantDemoMode::None;
}

void URemnantGameInstance::DoAuth() {
}


URemnantGameInstance::URemnantGameInstance() {
    this->CharacterManager = NULL;
}

