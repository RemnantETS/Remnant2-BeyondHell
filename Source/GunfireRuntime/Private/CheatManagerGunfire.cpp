#include "CheatManagerGunfire.h"

void UCheatManagerGunfire::UnlockAllTraitsOfType(const FString& NameOfTypeBP, int32 StartingLevel) {
}

void UCheatManagerGunfire::ToggleSecondaryFlyCamera() {
}

void UCheatManagerGunfire::TogglePrimaryFlyCamera() {
}

void UCheatManagerGunfire::ToggleFollowPlayer() {
}

void UCheatManagerGunfire::TeleportToHost() {
}

void UCheatManagerGunfire::TakeScreenShotWithDimensions(int32 ResX, int32 ResY) {
}

void UCheatManagerGunfire::TakeScreenShotCurrentResolutionScaled(int32 ScaleResolution) {
}

void UCheatManagerGunfire::SpawnCharacter(const FString& NameOfCharBP) {
}

void UCheatManagerGunfire::SetPlayerState(FName NewState) {
}

void UCheatManagerGunfire::SetPlayerNormalizedHealth(float NewHealth) {
}

void UCheatManagerGunfire::SetKillRadius(float NewKillRadius) {
}

void UCheatManagerGunfire::SetKillNearbyEnemiesRequiresVisibility(bool RequiresVisibility) {
}

void UCheatManagerGunfire::SendCommandToConsole(const FString& Command) {
}

void UCheatManagerGunfire::ResyncChallenges() {
}

void UCheatManagerGunfire::ResetTimedEvents() const {
}

void UCheatManagerGunfire::ResetChallenges() {
}

void UCheatManagerGunfire::RemoveTrait(const FString& NameOfBP) {
}

void UCheatManagerGunfire::RemoveItem(const FString& NameOfBP, int32 Quantity) {
}

void UCheatManagerGunfire::RemoveAllItems() {
}

void UCheatManagerGunfire::PrintActiveTimedEvents() const {
}

void UCheatManagerGunfire::LogChallengeProgress() {
}

void UCheatManagerGunfire::KillNearbyEnemies() {
}

void UCheatManagerGunfire::IncreasePlayerLevel(int32 NumLevel) {
}

void UCheatManagerGunfire::GiveItemSilent(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip) {
}

void UCheatManagerGunfire::GiveItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip) {
}

void UCheatManagerGunfire::GiveAllItems(const FString& NameOfClassBP, int32 Quantity, int32 LevelOverride, bool bOnlyUnique) {
}

TArray<FString> UCheatManagerGunfire::GetInputDescriptorForCheat(FName ActionName) {
    return TArray<FString>();
}

TArray<FString> UCheatManagerGunfire::GetConsoleCommands(const FString& Category) {
    return TArray<FString>();
}

FText UCheatManagerGunfire::GetConsoleCommandDescription(const FString& Command) {
    return FText::GetEmpty();
}

TArray<FString> UCheatManagerGunfire::GetConsoleCommandCategories() {
    return TArray<FString>();
}

void UCheatManagerGunfire::ForceHitch(float Seconds) {
}

void UCheatManagerGunfire::ForceCrash() {
}

void UCheatManagerGunfire::FlushNetDriverReferences() {
}

void UCheatManagerGunfire::EnablePrimaryFlyCamera() {
}

void UCheatManagerGunfire::DropItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
}

void UCheatManagerGunfire::DoAction(const FString& NameOfBP, bool bApplyToTarget) {
}

void UCheatManagerGunfire::ClearAllDialogs() {
}

void UCheatManagerGunfire::AddTrait(const FString& NameOfBP, int32 Level) {
}

void UCheatManagerGunfire::AddTimedEvent(FName EventName, const FString& Tags) const {
}

UCheatManagerGunfire::UCheatManagerGunfire() {
}

