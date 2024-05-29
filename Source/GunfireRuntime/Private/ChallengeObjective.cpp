#include "ChallengeObjective.h"

UChallengeObjective::UChallengeObjective() {
    this->Type = EChallengeObjectType::Increment;
    this->Count = 1;
    this->Authority = EChallengeAuthorityType::Local;
    this->RequiredEntitlement = NULL;
}

