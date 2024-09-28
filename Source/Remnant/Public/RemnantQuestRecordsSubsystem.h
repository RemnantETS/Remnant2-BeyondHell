#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameInstanceSubsystem -FallbackName=GameInstanceSubsystem
//CROSS-MODULE INCLUDE V2: -ModuleName=GunfireRuntime -ObjectName=TopPlayerRecordData -FallbackName=TopPlayerRecordData
#include "EQuestMode.h"
#include "EQuestRecordsActiveState.h"
#include "RemnantQuestRecordsSubsystem.generated.h"

class APlayerController;
class APlayerState;
class UQuestRecords;

UCLASS(Blueprintable)
class REMNANT_API URemnantQuestRecordsSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    URemnantQuestRecordsSubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScoreForPlayer(APlayerController* ContextPlayer, EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetScoreForAllPlayers(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TMap<APlayerState*, float>& OutScores, float& SumTotal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestRecords* GetRecordsForQuest(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode);
    
    UFUNCTION(BlueprintCallable)
    void GetRandTopRecordsPerPlayer(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TArray<FTopPlayerRecordData>& OutRecords);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExpForPlayer(APlayerController* ContextPlayer, EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetExpForAllPlayers(EQuestRecordsActiveState RecordsToGet, EQuestMode QuestMode, TMap<APlayerState*, float>& OutExp, float& ExpTotal);
    
    UFUNCTION(BlueprintCallable)
    void ApplyValue(APlayerController* ContextPlayer, FName ID, float Value);
    
};

