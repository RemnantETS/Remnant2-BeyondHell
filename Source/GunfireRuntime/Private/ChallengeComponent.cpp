#include "ChallengeComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

void UChallengeComponent::ServerResetAllChallenges_Implementation() {
}

void UChallengeComponent::ServerRepairMissedReward_Implementation(UChallengeReward* Reward) {
}

void UChallengeComponent::ServerIncrementObjectiveProgressOnly_Implementation(int32 ObjectiveID, int32 Amount) {
}

void UChallengeComponent::ServerGiveRewardsForChallengeRank_Implementation(UChallengeRank* ChallengeRank) {
}

void UChallengeComponent::RequestUpdateActiveServerObjectives_Implementation(const TArray<int32>& ObjectivesToAdd, const TArray<int32>& ObjectivesToRemove) {
}

void UChallengeComponent::RepairObjectiveValue(FName NameID, int32 Value) {
}

void UChallengeComponent::OnControllerChanged(APawn* Pawn, AController* OldController, AController* NewController) {
}

bool UChallengeComponent::IsObjectiveComplete(FName NameID) {
    return false;
}

bool UChallengeComponent::HasChallengeInstance(const UChallenge* Challenge) const {
    return false;
}

TArray<UChallenge*> UChallengeComponent::GetChallengesByCategory(const FChallengeCategory& Category, bool bVisibleOnly) const {
    return TArray<UChallenge*>();
}

UChallengeInstance* UChallengeComponent::GetChallengeInstance(const UChallenge* Challenge) const {
    return NULL;
}

float UChallengeComponent::GetCategoryProgress(const FChallengeCategory& Category, FPointSet& ChallengeProgress, FPointSet& PointProgress, bool bVisibleOnly) const {
    return 0.0f;
}







void UChallengeComponent::ClientUnlockChallenge_Implementation(FGuid ChallengeId) {
}

void UChallengeComponent::ClientReceiveReward_Implementation(TSubclassOf<UChallengeReward> RewardClass) {
}

void UChallengeComponent::ClientIncrementObjective_Implementation(int32 ObjectiveID, int32 Amount) {
}

void UChallengeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UChallengeComponent, ObjectiveProgressList);
    DOREPLIFETIME(UChallengeComponent, RecollectableAchievements);
}

UChallengeComponent::UChallengeComponent() {
    this->ChallengeManager = NULL;
    this->AchievementController = NULL;
}

