#include "AIEnvQueryStateDecorator.h"

UAIEnvQueryStateDecorator::UAIEnvQueryStateDecorator() {
    this->Action = EEnvQueryDecoratorAction::PathToTacticalPoint;
    this->AcceptanceRadius = 15.00f;
    this->MinTimeout = 4.00f;
    this->MaxTimeout = 6.00f;
    this->ValidateInterval = 0.50f;
    this->RetryInterval = 0.50f;
    this->EnvCancelBehavior = EEnvQueryCancelBehavior::Pause;
    this->NewPointScoreThreshold = 0.00f;
    this->NewPointScoreThresholdWhilePathing = 0.50f;
    this->PathToTargetOnFail = false;
    this->PathToTargetOnFailCompleteRange = 200.00f;
}

