#include "EquipmentInstanceData.h"
#include "Net/UnrealNetwork.h"

UEquipmentInstanceData::UEquipmentInstanceData() {
}

void UEquipmentInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UEquipmentInstanceData, Mods);
}


