#include "PlayerRecords.h"
#include "Net/UnrealNetwork.h"

UPlayerRecords::UPlayerRecords() {
    this->Player = NULL;
}

void UPlayerRecords::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPlayerRecords, Player);
    DOREPLIFETIME(UPlayerRecords, Records);
}


