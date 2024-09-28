#include "RemnantQuestRecordsSubsystem.h"

URemnantQuestRecordsSubsystem::URemnantQuestRecordsSubsystem() {
}

float URemnantQuestRecordsSubsystem::GetScoreForPlayer(APlayerController* ContextPlayer, EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode) {
    return 0.0f;
}

void URemnantQuestRecordsSubsystem::GetScoreForAllPlayers(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TMap<APlayerState*, float>& OutScores, float& SumTotal) {
}

UQuestRecords* URemnantQuestRecordsSubsystem::GetRecordsForQuest(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode) {
    return NULL;
}

void URemnantQuestRecordsSubsystem::GetRandTopRecordsPerPlayer(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TArray<FTopPlayerRecordData>& OutRecords) {
}

float URemnantQuestRecordsSubsystem::GetExpForPlayer(APlayerController* ContextPlayer, EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode) {
    return 0.0f;
}

void URemnantQuestRecordsSubsystem::GetExpForAllPlayers(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TMap<APlayerState*, float>& OutExp, float& ExpTotal) {
}

void URemnantQuestRecordsSubsystem::ApplyValue(APlayerController* ContextPlayer, FName ID, float Value) {
}


