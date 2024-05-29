#include "DamageValidationComponent.h"

void UDamageValidationComponent::ServerReceiveDamageResults_Implementation(uint8 DamageID, bool bWasEvaded, bool bWasCounterEvade, const UObject* Source) {
}

void UDamageValidationComponent::ClientValidateDamage_Implementation(uint8 DamageID, uint16 DamageTimestamp, const FClientDamageInfo& DamageInfo) {
}

UDamageValidationComponent::UDamageValidationComponent() {
}

