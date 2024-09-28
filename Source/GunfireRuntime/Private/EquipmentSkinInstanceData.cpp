#include "EquipmentSkinInstanceData.h"
#include "Net/UnrealNetwork.h"

UEquipmentSkinInstanceData::UEquipmentSkinInstanceData() {
    this->Equipped = false;
}

void UEquipmentSkinInstanceData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UEquipmentSkinInstanceData, Equipped);
}


