#include "ChallengeReward.h"

bool UChallengeReward::HasBeenAwarded_Implementation(AActor* Recepient) {
    return false;
}

bool UChallengeReward::GiveReward_Implementation(AActor* Recepient) {
    return false;
}

FText UChallengeReward::GetDisplayLabel_Implementation() const {
    return FText::GetEmpty();
}

FText UChallengeReward::GetDescription_Implementation() const {
    return FText::GetEmpty();
}

UChallengeReward::UChallengeReward() {
    this->Label = FText::FromString(TEXT("Challenge Reward"));
    this->Icon = NULL;
}

