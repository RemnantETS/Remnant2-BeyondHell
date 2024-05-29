#include "PrismStone.h"

void APrismStone::RemoveSegmentByName(FName NameID) {
}

void APrismStone::RemoveAllSegments() {
}

void APrismStone::PostComputePrismStats() {
}

bool APrismStone::HasSegmentWithNameID(FName NameID) {
    return false;
}

bool APrismStone::HasEmptySlots() {
    return false;
}

bool APrismStone::HasBeenFed() {
    return false;
}

bool APrismStone::GetSegmentLevelByNameID(FName NameID, int32& OutLevel) {
    return false;
}

float APrismStone::GetProgressToNextLevel() {
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

FInspectInfo APrismStone::GetInspectInfoFromNameID(FName NameID, int32 InspectLevel) {
    return FInspectInfo{};
}

float APrismStone::GetExperienceRequiredForLevel(int32 TargetLevel) {
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

void APrismStone::FeedGemData(FName FeedNameID, int32 GemLevelFed) {
}

TArray<FName> APrismStone::DetermineLevelUpRolls(AActor* TargetActor) {
    return TArray<FName>();
}

void APrismStone::ComputePrismStats() {
}

bool APrismStone::CanRemoveSegments() {
    return false;
}

bool APrismStone::AddSegmentToPrismByNameID(FName NameID) {
    return false;
}

void APrismStone::AddExperience(float Experience) {
}

APrismStone::APrismStone() {
    this->PrismStoneTable = NULL;
    this->LevelUpRollsToChooseFrom = 3;
    this->MaxSegments = 5;
    this->BonusSegmentsForNoFeed = 1;
    this->DefaultExpRequiredPerLevel = 1000.00f;
    this->ExperienceCurve = NULL;
    this->MaxSegmentLevel = 10;
}

