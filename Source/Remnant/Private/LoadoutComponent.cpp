#include "LoadoutComponent.h"

void ULoadoutComponent::UpdatePendingLoadout() {
}

bool ULoadoutComponent::SetDisplayNameForLoadout(ULoadoutTemplate* Loadout, int32 Index, const FText& NewDisplayName) {
    return false;
}

void ULoadoutComponent::ServerLoadLoadout_Implementation(const FLoadoutRecord& ClientRecord) {
}

void ULoadoutComponent::RemoveObjectClassFromLoadouts(TSoftClassPtr<UObject> DeprecatedClass) {
}

bool ULoadoutComponent::LoadLoadout(ULoadoutTemplate* Loadout, int32 Index) {
    return false;
}

bool ULoadoutComponent::IsLoadoutEquipped(ULoadoutTemplate* Loadout, int32 Index) {
    return false;
}

bool ULoadoutComponent::IsLoadingLoadout() const {
    return false;
}

bool ULoadoutComponent::HasRecord(ULoadoutTemplate* Loadout, int32 Index, bool bHasAnyEntries) const {
    return false;
}

int32 ULoadoutComponent::GetMaxRecordsForTemplate(ULoadoutTemplate* Loadout) const {
    return 0;
}

bool ULoadoutComponent::GetEntryForLoadoutSlot(ULoadoutTemplate* Loadout, int32 Index, ULoadoutSlot* Slot, FLoadoutRecordEntry& Entry) const {
    return false;
}

FText ULoadoutComponent::GetDisplayNameForLoadout(ULoadoutTemplate* Loadout, int32 Index) const {
    return FText::GetEmpty();
}

bool ULoadoutComponent::CommitLoadout(ULoadoutTemplate* Loadout, int32 Index) {
    return false;
}

void ULoadoutComponent::ClientPostLoadLoadout_Implementation(ULoadoutTemplate* Loadout) {
}

bool ULoadoutComponent::ClearLoadout(ULoadoutTemplate* Loadout, int32 Index) {
    return false;
}

bool ULoadoutComponent::CanLoadLoadout() const {
    return false;
}

ULoadoutComponent::ULoadoutComponent() {
    this->LoadoutUpdateDelay = 0.05f;
    this->LoadoutCooldown = TEXT("LoadLoadout");
    this->LoadoutCooldownDuration = 0.50f;
}

