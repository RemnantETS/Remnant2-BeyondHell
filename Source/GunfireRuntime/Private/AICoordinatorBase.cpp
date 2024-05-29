#include "AICoordinatorBase.h"

bool UAICoordinatorBase::IsTargeted(AActor* Actor) const {
    return false;
}

bool UAICoordinatorBase::IsCloselyTargeted(AActor* Actor) const {
    return false;
}

UAICoordinatorBase* UAICoordinatorBase::GetAICoordinator(UObject* WorldContextObject) {
    return NULL;
}

UAICoordinatorBase::UAICoordinatorBase() {
    this->DefaultCombatClass = NULL;
    this->PlayerCombatClass = NULL;
}

