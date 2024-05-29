#include "TwitchIntegrationManager.h"

void UTwitchIntegrationManager::StopTwitchIntegrationForReason(FText Reason) {
}

void UTwitchIntegrationManager::RefreshConnectionDetails() {
}

void UTwitchIntegrationManager::PopulateImagesOnServer() {
}

void UTwitchIntegrationManager::OnStopTwitchIntegration(bool KeepAuthToken) {
}

void UTwitchIntegrationManager::OnStartTwitchIntegration() {
}

void UTwitchIntegrationManager::OnPawnChangedEvent() {
}

void UTwitchIntegrationManager::OnLocalPlayerEquipmentChanged() {
}

bool UTwitchIntegrationManager::IsLive() {
    return false;
}

bool UTwitchIntegrationManager::HasValidSession() {
    return false;
}

bool UTwitchIntegrationManager::HasValidJWT() {
    return false;
}

UTwitchIntegrationManager* UTwitchIntegrationManager::GetTwitchIntegrationManager(UObject* WorldContextObject) {
    return NULL;
}

FTwitchActiveSessionDetails UTwitchIntegrationManager::GetSessionDetails() {
    return FTwitchActiveSessionDetails{};
}

void UTwitchIntegrationManager::EncodeTexture(UTexture2D* Texture, FString& OutEncodedString, int32& OutSizeX, int32& OutSizeY) {
}

void UTwitchIntegrationManager::DecodeTexture(const FString& InEncodedString, const int32& InSizeX, const int32& InSizeY, UTexture2D*& OutTexture) {
}

void UTwitchIntegrationManager::BindToLocalControllerEvents(APlayerState* Player) {
}

UTwitchIntegrationManager::UTwitchIntegrationManager() {
}

