#include "RecordInstanceData.h"
#include "Net/UnrealNetwork.h"

URecordInstanceData::URecordInstanceData() {
    this->Value = 0.00f;
    this->Score = 0.00f;
    this->Exp = 0.00f;
}

void URecordInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URecordInstanceData, Value);
    DOREPLIFETIME(URecordInstanceData, Score);
    DOREPLIFETIME(URecordInstanceData, Exp);
}


