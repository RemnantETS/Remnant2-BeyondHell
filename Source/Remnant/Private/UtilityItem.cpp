#include "UtilityItem.h"

AUtilityItem::AUtilityItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ValidationTags.AddDefaulted(1);
    this->MaxCharges = 1;
    this->CooldownTime = 1.00f;
}

void AUtilityItem::UseCharge() {
}

void AUtilityItem::Recharge() {
}

uint8 AUtilityItem::GetCharges() {
    return 0;
}


