#include "PrismStone.h"

APrismStone::APrismStone(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ReplicateMod = true;
    this->PrismStoneTable = NULL;
    this->MythicPrismStoneTable = NULL;
    this->LevelUpRollsToChooseFrom = 3;
    this->MaxSegments = 5;
    this->MaxSegmentLevel = 10;
    this->MythicMaxSegmentLevel = 1;
    this->BonusSegmentsWhenConditionsMet = 1;
    this->BonusSegmentsRequirementsToRoll = NULL;
    this->MythicSegmentsRequirementsToRoll = NULL;
    this->DefaultExpRequiredPerLevel = 1000.00f;
    this->RequiredExperienceInc = 500.00f;
    this->RequiredExperienceExp = 1.00f;
    this->RequiredExperienceRound = 100;
    this->MythicExpRequired = 10000.00f;
    this->ExperienceCurve = NULL;
    this->MaxLevelForNormalizedCurve = 50;
    this->ExperienceCurveIsNormalized = true;
    this->FinalExpCurveRequired = 50000.00f;
    this->FeedDefaultExpGiven = 500.00f;
    this->FeedExperienceInc = 500.00f;
    this->FeedExperienceExp = 1.00f;
    this->FeedExperienceRound = 0;
    this->FeedWeightCurve = NULL;
    this->FeedMaxLevel = 32;
    this->FeedExperienceCurve = NULL;
    this->FeedExperienceCurveIsNormalized = true;
    this->FeedFinalCurveExpGiven = 5000.00f;
    this->StoneFeedConditions = NULL;
    this->PlayerFeedConditions = NULL;
    this->StoneFlushConditions = NULL;
    this->PlayerFlushConditions = NULL;
    this->StoneRemoveSegmentsConditions = NULL;
    this->PlayerRemoveSegmentsConditions = NULL;
    this->StoneComboBypassConditions = NULL;
    this->PlayerComboBypassConditions = NULL;
    this->InspectStats = NULL;
}

void APrismStone::UIAddSegmentToPrismByNameID(FName NameID) {
}

void APrismStone::ServerSetHasRolled_Implementation(bool Rolled) {
}

void APrismStone::ServerGenerateStartSeed_Implementation() {
}

void APrismStone::ServerFlushPrismStone_Implementation(bool RemoveSegments, bool RemovePendingExp, bool RemoveFeedData, bool RemoveStoredLevels) {
}

void APrismStone::ServerFeedGemData_Implementation(FName FeedNameID, int32 GemLevelFed) {
}

void APrismStone::ServerAddSegmentToPrismByNameID_Implementation(FName NameID, int32 ModifiedSeed) {
}

void APrismStone::PostComputePrismStats() {
}

void APrismStone::OnSegmentActionLoaded(FName SegmentNameID) {
}

void APrismStone::OnExperience(int32 Experience) {
}

void APrismStone::ModifyIncomingExperience_Implementation(int32& Experience) {
}

bool APrismStone::IsMythicSegmentByNameID(FName NameID) const {
    return false;
}

bool APrismStone::IsComboSegmentByNameID(FName NameID) const {
    return false;
}

bool APrismStone::HasSegmentWithNameID(FName NameID) {
    return false;
}

bool APrismStone::HasMythicSegment() {
    return false;
}

bool APrismStone::HasEmptySlots() {
    return false;
}

bool APrismStone::HasBeenFed() {
    return false;
}

int32 APrismStone::GetSegmentRarityByNameID(FName NameID) const {
    return 0;
}

int32 APrismStone::GetSegmentMaxLevelByNameID(FName NameID) const {
    return 0;
}

bool APrismStone::GetSegmentLevelByNameID(FName NameID, int32& OutLevel) {
    return false;
}

EPrismSegmentCategory APrismStone::GetSegmentCategoryByNameID(FName NameID) const {
    return EPrismSegmentCategory::Red;
}

float APrismStone::GetProgressToNextLevel() {
    return 0.0f;
}

float APrismStone::GetProgressToNextExperienceLevel() {
    return 0.0f;
}

int32 APrismStone::GetPrismStoneLevel() {
    return 0;
}

int32 APrismStone::GetPrismStoneExperienceLevel() {
    return 0;
}

TArray<FPotentialRoll> APrismStone::GetPossibleRollsFor(AActor* TargetActor) {
    return TArray<FPotentialRoll>();
}

int32 APrismStone::GetNumSegments() {
    return 0;
}

int32 APrismStone::GetNumEmptySlots() {
    return 0;
}

FName APrismStone::GetNameIDForSegment(int32 SegmentIndex) {
    return NAME_None;
}

FName APrismStone::GetNameIDForObject(TSoftObjectPtr<UObject> SoftObject) {
    return NAME_None;
}

int32 APrismStone::GetMaxPossibleSegments() {
    return 0;
}

float APrismStone::GetMaxFeedBonus() {
    return 0.0f;
}

float APrismStone::GetLeftOverExperience() {
    return 0.0f;
}

FInspectInfo APrismStone::GetInspectInfoFromNameID(FName NameID, int32 InspectLevel) {
    return FInspectInfo{};
}

float APrismStone::GetFeedBonusForNameID(FName NameID) {
    return 0.0f;
}

float APrismStone::GetFeedBonusForFeedLevel(int32 FeedLevel) {
    return 0.0f;
}

float APrismStone::GetFeedBonusAsRatioOfMaxForNameID(FName NameID) {
    return 0.0f;
}

float APrismStone::GetFeedBonusAsPercentForNameID(FName NameID, AActor* TargetActor) {
    return 0.0f;
}

float APrismStone::GetExperienceRequiredForLevel(int32 TargetLevel) {
    return 0.0f;
}

float APrismStone::GetExperienceGainFromFeedLevel(int32 GemLevelFed) {
    return 0.0f;
}

UObject* APrismStone::GetDataObjectForNameID(FName NameID) {
    return NULL;
}

int32 APrismStone::GetCurrentMaxSegments() {
    return 0;
}

TArray<UObject*> APrismStone::GetAllSegmentDataObjects() const {
    return TArray<UObject*>();
}

TArray<FFeedRatios> APrismStone::GetAllFeedBonusAsRatioOfMax(AActor* TargetActor) {
    return TArray<FFeedRatios>();
}

TArray<FName> APrismStone::DetermineLevelUpRolls(AActor* TargetActor) {
    return TArray<FName>();
}

bool APrismStone::ConsumeExperienceForLevel(int32 TargetLevel) {
    return false;
}

void APrismStone::ComputePrismStats() {
}

bool APrismStone::CanRoll() {
    return false;
}

bool APrismStone::CanRemoveSegments() {
    return false;
}

bool APrismStone::CanFlushStone() {
    return false;
}

bool APrismStone::CanBeFed(bool CheckForPendingRoll) {
    return false;
}

void APrismStone::AddExperience(float Experience) {
}


