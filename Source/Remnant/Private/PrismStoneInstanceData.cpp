#include "PrismStoneInstanceData.h"
#include "Net/UnrealNetwork.h"

UPrismStoneInstanceData::UPrismStoneInstanceData() {
    this->CurrentSeed = -1;
    this->PendingRoll = false;
    this->HasBeenFed = false;
    this->PendingExperience = 0.00f;
    this->PendingMaxExperience = 0.00f;
    this->CalculatedPendingMaxExp = false;
}

void UPrismStoneInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPrismStoneInstanceData, CurrentSegments);
    DOREPLIFETIME(UPrismStoneInstanceData, CurrentSeed);
    DOREPLIFETIME(UPrismStoneInstanceData, PendingRoll);
    DOREPLIFETIME(UPrismStoneInstanceData, CurrentFeedData);
    DOREPLIFETIME(UPrismStoneInstanceData, HasBeenFed);
    DOREPLIFETIME(UPrismStoneInstanceData, PendingExperience);
}


