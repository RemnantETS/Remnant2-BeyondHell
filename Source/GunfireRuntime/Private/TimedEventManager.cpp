#include "TimedEventManager.h"

void UTimedEventManager::OnRootVariableContextCreated(URootVariableContext* Context) {
}
/*
void UTimedEventManager::OnFileManifestDownloaded(bool bSuccess, const TArray<UTitleStorageFile*>& FileManifest) {
}

void UTimedEventManager::OnFileDownloaded(bool bSuccess, UTitleStorageFile* File) {
}
*/
bool UTimedEventManager::HasTags(const TArray<FName>& RequiredTags)  {
    return false;
}

bool UTimedEventManager::HasEvent(FName EventName)  {
    return false;
}

TArray<FName> UTimedEventManager::GetTags()  {
    return TArray<FName>();
}

TArray<FTimedEvent> UTimedEventManager::GetEvents()  {
    return TArray<FTimedEvent>();
}

bool UTimedEventManager::GetEvent(FName EventName, FTimedEvent& OutEvent)  {
    return false;
}

UTimedEventManager::UTimedEventManager() {
    this->VariableComponent = NULL;
}

