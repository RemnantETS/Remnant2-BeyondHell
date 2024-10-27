#include "LegacyTraitsComponent.h"

ULegacyTraitsComponent::ULegacyTraitsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProgressionType = ETraitProgressionType::LegacyProgression;
}


