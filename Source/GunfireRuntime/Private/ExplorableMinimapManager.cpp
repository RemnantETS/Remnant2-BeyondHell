#include "ExplorableMinimapManager.h"

void UExplorableMinimapManager::ShutdownMinimap() {
}

void UExplorableMinimapManager::SetCaptureEveryFrame(bool bValue) {
}

bool UExplorableMinimapManager::IsTooltipEnabled() {
    return false;
}

bool UExplorableMinimapManager::IsMinimapEnabled() {
    return false;
}

bool UExplorableMinimapManager::IsFullscreenMinimapActive() {
    return false;
}

bool UExplorableMinimapManager::IsFogOfWarEnabled() {
    return false;
}

TArray<AActor*> UExplorableMinimapManager::GetSpawnedMinimapEntities() const {
    return TArray<AActor*>();
}

AActor* UExplorableMinimapManager::GetRefActorFromMinimapEntity(const AActor* MinimapEntity) {
    return NULL;
}

AExplorableMinimapModel* UExplorableMinimapManager::GetExplorableMinimapModel() {
    return NULL;
}

UExplorableMinimapManager* UExplorableMinimapManager::GetExplorableMinimapManager(const UObject* WorldContextObject) {
    return NULL;
}

void UExplorableMinimapManager::EnableTooltips(bool bEnable) {
}

void UExplorableMinimapManager::EnableMinimap(bool bEnable) {
}

void UExplorableMinimapManager::EnableFogOfWar(bool bEnable) {
}

UExplorableMinimapManager::UExplorableMinimapManager() {
    this->CameraSceneComponent = NULL;
    this->ExplorableMinimapModel = NULL;
}

