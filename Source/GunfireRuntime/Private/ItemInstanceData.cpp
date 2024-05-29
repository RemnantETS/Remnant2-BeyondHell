#include "ItemInstanceData.h"
#include "Net/UnrealNetwork.h"

void UItemInstanceData::OnRep_MinorChange() {
}

void UItemInstanceData::OnRep_InstanceData() {
}

void UItemInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UItemInstanceData, Level);
    DOREPLIFETIME(UItemInstanceData, Quantity);
}

UItemInstanceData::UItemInstanceData() {
    this->Level = 0;
    this->Quantity = 1;
}

