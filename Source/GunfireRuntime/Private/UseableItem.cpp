#include "UseableItem.h"

AUseableItem::AUseableItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Conditions = NULL;
    this->ActivationType = EUsableActivationType::Press;
    this->bConsumeInput = true;
    this->bIgnoreInputWhileInUse = true;
    this->HoldTime = 0.00f;
    this->bDeferHoldUseUntilRelease = false;
    this->bValidateUseBeforeStartingHoldTimer = false;
    this->DoublePressTime = 0.10f;
    this->DisableTickAfterUse = true;
    this->ValidationTags.AddDefaulted(1);
}

bool AUseableItem::ValidateUse_Implementation(AActor* Actor, EItemUseType UseType) {
    return false;
}

void AUseableItem::UseItem(EItemUseType UseType) {
}

void AUseableItem::Use_Implementation(EItemUseType UseType) {
}

void AUseableItem::UpdateTickState_Implementation() {
}

void AUseableItem::ServerKeyPressed_Implementation(EItemUseType UseType) {
}
bool AUseableItem::ServerKeyPressed_Validate(EItemUseType UseType) {
    return true;
}

void AUseableItem::ResetInput() {
}

void AUseableItem::RemoveItem() {
}






void AUseableItem::OnInput(FName ButtonName, ButtonEvent Event) {
}

void AUseableItem::MultiCreateUseInstance_Implementation(EItemUseType UseType) {
}

void AUseableItem::ModifyUseDetails_Implementation(EItemUseType UseType, FUseDetails& OutUseDetails) const {
}

bool AUseableItem::HasHoldTimerElapsed() const {
    return false;
}

float AUseableItem::GetCooldownPct_Implementation(AActor* Actor) {
    return 0.0f;
}

void AUseableItem::ClientOnItemUsed_Implementation(EItemUseType UseType) {
}


