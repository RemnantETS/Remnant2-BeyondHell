#include "TraitsComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

void UTraitsComponent::Unequip_Implementation(int32 SlotIndex) {
}
bool UTraitsComponent::Unequip_Validate(int32 SlotIndex) {
    return true;
}

void UTraitsComponent::SetTraitInstanceData(TSubclassOf<UTrait> TraitBP, int32 NewInstanceDataValue) {
}

void UTraitsComponent::SetMaxLevelMod(TSubclassOf<UTrait> TraitBP, uint8 MaxLevelMod, ETraitPointModType ModType, bool bOverrideExistingLevel) {
}

void UTraitsComponent::SetLevelMod(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, ETraitPointModType ModType, bool bOverrideExistingLevel) {
}

void UTraitsComponent::Server_CorrectTraitPoints_Implementation(int32 InTraitPoints) {
}
bool UTraitsComponent::Server_CorrectTraitPoints_Validate(int32 InTraitPoints) {
    return true;
}

void UTraitsComponent::RemoveTraitModifier(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, uint8 MaxLevelMod, ETraitPointModType ModType) {
}

bool UTraitsComponent::RemoveTrait(TSoftClassPtr<UTrait> TraitBP) {
    return false;
}

void UTraitsComponent::RefundToLevel_Implementation(TSubclassOf<UTrait> TraitBP, int32 DesiredLevel) {
}
bool UTraitsComponent::RefundToLevel_Validate(TSubclassOf<UTrait> TraitBP, int32 DesiredLevel) {
    return true;
}

void UTraitsComponent::Refund_Implementation(TSubclassOf<UTrait> TraitBP, int32 Amount) {
}
bool UTraitsComponent::Refund_Validate(TSubclassOf<UTrait> TraitBP, int32 Amount) {
    return true;
}

void UTraitsComponent::Purchase_Implementation(TSubclassOf<UTrait> TraitBP) {
}
bool UTraitsComponent::Purchase_Validate(TSubclassOf<UTrait> TraitBP) {
    return true;
}

void UTraitsComponent::OnRep_Traits() {
}

void UTraitsComponent::OnRep_TraitPoints() {
}

void UTraitsComponent::OnLevelUp() {
}

void UTraitsComponent::OnComputeStats() {
}

void UTraitsComponent::MarkTraitNoLongerNew(TSubclassOf<UTrait> TraitBP) {
}

void UTraitsComponent::MarkPreviewingChangesComplete(bool bCanceled) {
}

void UTraitsComponent::MarkPreviewingChanges() {
}

void UTraitsComponent::K2_UnlockTraitSoft(TSoftClassPtr<UTrait> TraitBP, const FTraitDeferredDelegate& OnUnlockedTrait, int32 StartingLevel, bool bAllowAutoEquip) {
}

FTraitInfo UTraitsComponent::K2_GetTraitInfoForSlot(int32 SlotIndex) const {
    return FTraitInfo{};
}

FTraitInfo UTraitsComponent::K2_GetTraitInfo(TSoftClassPtr<UTrait> TraitBP) const {
    return FTraitInfo{};
}

bool UTraitsComponent::IsTraitTransient(TSubclassOf<UTrait> TraitBP) const {
    return false;
}

bool UTraitsComponent::IsTraitSlotUnlocked(int32 SlotIndex, bool ValidateHasTraits) const {
    return false;
}

bool UTraitsComponent::IsTraitOfType(TSubclassOf<UTrait> TraitBP, TSubclassOf<UTraitType> Type) const {
    return false;
}

bool UTraitsComponent::IsPreviewingTraitChanges() const {
    return false;
}

bool UTraitsComponent::HasTraitByType(TSubclassOf<UTraitType> Type) const {
    return false;
}

bool UTraitsComponent::HasTraitByName(const FName& NameID, int32 RequiredLevel) const {
    return false;
}

bool UTraitsComponent::HasTrait(TSoftClassPtr<UTrait> TraitBP, int32 RequiredLevel) const {
    return false;
}

int32 UTraitsComponent::GetTraitPoints() const {
    return 0;
}

int32 UTraitsComponent::GetTraitMaxLevel(TSubclassOf<UTrait> TraitBP, bool ApplyModifiers) const {
    return 0;
}

int32 UTraitsComponent::GetTraitLevel(TSoftClassPtr<UTrait> TraitBP, bool ApplyModifiers) const {
    return 0;
}

int32 UTraitsComponent::GetTraitInstanceData(TSubclassOf<UTrait> TraitBP) {
    return 0;
}

int32 UTraitsComponent::GetTotalArchetypeLevel() {
    return 0;
}

UProgressionComponent* UTraitsComponent::GetProgression() const {
    return NULL;
}

int32 UTraitsComponent::GetOverallocatedPoints(TSubclassOf<UTrait> TraitBP) const {
    return 0;
}

uint8 UTraitsComponent::GetMaxLevelMods(TSubclassOf<UTrait> TraitBP, bool bGetAllMods, ETraitPointModType ModType) const {
    return 0;
}

uint8 UTraitsComponent::GetLevelMods(TSubclassOf<UTrait> TraitBP, bool bGetAllMods, ETraitPointModType ModType) const {
    return 0;
}

int32 UTraitsComponent::GetEquippedArchetypeLevel() {
    return 0;
}

TArray<FTraitInfo> UTraitsComponent::GetAvailableTraits() const {
    return TArray<FTraitInfo>();
}

int32 UTraitsComponent::GetAvailableTraitPoints() const {
    return 0;
}

TArray<FTraitInfo> UTraitsComponent::GetAllTraits() const {
    return TArray<FTraitInfo>();
}

int32 UTraitsComponent::GetAllocatedTraitPoints() const {
    return 0;
}

void UTraitsComponent::Equip_Implementation(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
}
bool UTraitsComponent::Equip_Validate(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
    return true;
}

void UTraitsComponent::ClientNotifyTraitPointsAdded_Implementation(int32 Points) {
}

bool UTraitsComponent::CanPurchase(TSubclassOf<UTrait> TraitBP) {
    return false;
}

bool UTraitsComponent::CanEquip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
    return false;
}

int32 UTraitsComponent::AddTraitPoints(int32 Points, bool BroadcastNotify) {
    return 0;
}

void UTraitsComponent::AddTraitModifier(TSubclassOf<UTrait> TraitBP, uint8 LevelMod, uint8 MaxLevelMod, ETraitPointModType ModType, bool OverrideExistingLevel) {
}

void UTraitsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTraitsComponent, TraitPoints);
    DOREPLIFETIME(UTraitsComponent, Traits);
}

UTraitsComponent::UTraitsComponent() {
    this->TraitPointsPerLevelTable = NULL;
    this->TraitPointsPerLevel = 1;
    this->MaxTraitPoints = 60;
    this->UnlockedTraitLevel = 1;
    this->TraitPoints = 0;
}

