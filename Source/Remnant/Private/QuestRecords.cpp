#include "QuestRecords.h"
#include "Net/UnrealNetwork.h"

UQuestRecords::UQuestRecords() {
    this->QuestMode = EQuestMode::None;
    this->Seed = 0;
    this->ID = 0;
    this->LastActiveIdx = 0;
}

void UQuestRecords::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UQuestRecords, QuestMode);
    DOREPLIFETIME(UQuestRecords, Seed);
    DOREPLIFETIME(UQuestRecords, ID);
    DOREPLIFETIME(UQuestRecords, LastActiveIdx);
    DOREPLIFETIME(UQuestRecords, PlayerRecords);
}


