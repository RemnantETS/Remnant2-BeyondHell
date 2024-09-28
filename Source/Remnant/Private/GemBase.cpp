#include "GemBase.h"

AGemBase::AGemBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AGemBase::OnPostComputePrismStats_Implementation(AActor* OwningCharacter, int32 ComputeLevel) const {
}

void AGemBase::OnComputePrismStats_Implementation(AActor* OwningCharacter, int32 ComputeLevel, int32 PrismMaxLevelReference) const {
}

void AGemBase::ModifyPrismInspectInfo_Implementation(int32 InspectLevel, FInspectInfo& Info, int32 PrismMaxLevelReference) {
}

TArray<FName> AGemBase::GetSimpleStatNamesForGem_Implementation() const {
    return TArray<FName>();
}


