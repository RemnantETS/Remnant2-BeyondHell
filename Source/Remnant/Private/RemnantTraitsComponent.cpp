#include "RemnantTraitsComponent.h"
#include "Templates/SubclassOf.h"

URemnantTraitsComponent::URemnantTraitsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ArchetypeNameTable = NULL;
    this->bUseTypeForSortPriority = true;
    this->bSortPropertyGreatestToLeast = true;
    this->TraitPropertySort = ETraitSortProperty::Level;
    this->ArchetypeTraitType = NULL;
}

bool URemnantTraitsComponent::IsInitializing() const {
    return false;
}

bool URemnantTraitsComponent::IsEquipmentTrait(FTraitInfo TraitInfo) {
    return false;
}

bool URemnantTraitsComponent::IsArchetypeAppliedTrait(FTraitInfo TraitInfo) {
    return false;
}

int32 URemnantTraitsComponent::GetTraitProgress(TSubclassOf<UTrait> TraitBP) {
    return 0;
}

TArray<FTraitInfo> URemnantTraitsComponent::GetSortedTraitList() {
    return TArray<FTraitInfo>();
}

TArray<FTraitInfo> URemnantTraitsComponent::GetCustomSortedTraitList(UDataTable* TraitSortTable) {
    return TArray<FTraitInfo>();
}

FText URemnantTraitsComponent::GetArchetypeNameForCombo(TSoftClassPtr<UTrait> ArchetypeA, TSoftClassPtr<UTrait> ArchetypeB) {
    return FText::GetEmpty();
}

void URemnantTraitsComponent::CheckOnTraitUpdated(TSubclassOf<UTrait> TraitBP) {
}

void URemnantTraitsComponent::CheckOnTraitRemoved(TSubclassOf<UTrait> TraitBP) {
}

void URemnantTraitsComponent::CheckOnTraitLevelChanged(TSubclassOf<UTrait> TraitBP, int32 Level) {
}

void URemnantTraitsComponent::CheckOnTraitAdded(TSubclassOf<UTrait> TraitBP) {
}


