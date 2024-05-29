#include "PrismStoneInstanceData.h"
#include "Net/UnrealNetwork.h"

void UPrismStoneInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPrismStoneInstanceData, CurrentSegments);
    DOREPLIFETIME(UPrismStoneInstanceData, CurrentFeedData);
    DOREPLIFETIME(UPrismStoneInstanceData, HasBeenFed);
    DOREPLIFETIME(UPrismStoneInstanceData, PendingExperience);
}

UPrismStoneInstanceData::UPrismStoneInstanceData() {
    this->HasBeenFed = false;
    this->PendingExperience = 0.00f;
}

