#include "AIPointOfInterest.h"

void AAIPointOfInterest::SetEnabled(bool IsEnabled) {
}

bool AAIPointOfInterest::OnValidate_Implementation(AActor* Actor) {
    return false;
}




void AAIPointOfInterest::EndUse(bool SetCooldown) {
}

void AAIPointOfInterest::BeginUse() {
}

AAIPointOfInterest::AAIPointOfInterest() {
    this->Enabled = true;
    this->Type = NULL;
    this->MinUseTime = -1.00f;
    this->MaxUseTime = -1.00f;
    this->CooldownMin = 5.00f;
    this->CooldownMax = 20.00f;
    this->MaxDistance = 2000.00f;
    this->MaxDistanceToPOI = -1.00f;
    this->UsePathDistance = false;
    this->ScopedToLevel = true;
    this->PatrolPath = NULL;
    this->AllowSnapping = true;
    this->Occupant = NULL;
}

