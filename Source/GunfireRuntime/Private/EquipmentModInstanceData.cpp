#include "EquipmentModInstanceData.h"
#include "Net/UnrealNetwork.h"

UEquipmentModInstanceData::UEquipmentModInstanceData() {
    this->EquippedModItemID = -1;
    this->EquippedModSlotID = 0;
}

void UEquipmentModInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UEquipmentModInstanceData, EquippedModItemID);
    DOREPLIFETIME(UEquipmentModInstanceData, EquippedModSlotID);
}


