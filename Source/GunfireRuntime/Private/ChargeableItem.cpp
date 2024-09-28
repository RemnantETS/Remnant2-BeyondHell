#include "ChargeableItem.h"
#include "Net/UnrealNetwork.h"

AChargeableItem::AChargeableItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Conditions = NULL;
    this->ActivationType = EChargeableActivateType::Press;
    this->ConsumeInput = true;
    this->HoldTime = 0.50f;
    this->ChargeTimeInSeconds = 5.00f;
    this->State = EChargeState::None;
    this->Charge = 0.00f;
}

bool AChargeableItem::ValidateUse_Implementation() {
    return false;
}

void AChargeableItem::ServerKeyReleased_Implementation() {
}
bool AChargeableItem::ServerKeyReleased_Validate() {
    return true;
}

void AChargeableItem::ServerKeyPressed_Implementation() {
}
bool AChargeableItem::ServerKeyPressed_Validate() {
    return true;
}

void AChargeableItem::RemoveItem() {
}

void AChargeableItem::OnRep_ChargeState() {
}

void AChargeableItem::OnChargeSuccess_Implementation() {
}

void AChargeableItem::OnChargeFail_Implementation() {
}

void AChargeableItem::OnChargeComplete_Implementation() {
}

void AChargeableItem::OnChargeBegin_Implementation() {
}

bool AChargeableItem::IsBusy() const {
    return false;
}

void AChargeableItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AChargeableItem, State);
    DOREPLIFETIME(AChargeableItem, Charge);
}


