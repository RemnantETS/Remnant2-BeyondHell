#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChallengeEvent.h"
#include "ChallengeObjectiveSelection.h"
#include "ChallengeBlueprintFunctions.generated.h"

class APlayerController;
class UChallenge;
class UChallengeObjective;
class UObject;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UChallengeBlueprintFunctions : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UChallengeBlueprintFunctions();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UnlockChallenges(UObject* WorldContextObject, FChallengeEvent ObjectiveID);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IncrementObjectivesFromObject(UObject* WorldContextObject, FChallengeEvent ObjectiveID, UObject* Object, const TArray<FName>& AdditionalTags, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementObjectivesFor(APlayerController* Controller, FChallengeEvent ObjectiveID, const TArray<FName>& Tags, int32 Amount);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IncrementObjectives(UObject* WorldContextObject, FChallengeEvent ObjectiveID, const TArray<FName>& Tags, int32 Amount);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void IncrementObjective(UObject* WorldContextObject, FChallengeObjectiveSelection ObjectiveSelection, int32 Amount);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UChallengeObjective* GetChallengeObjective(UObject* WorldContextObject, FChallengeObjectiveSelection ObjectiveSelection);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<UChallenge*> GetAllChallenges(UObject* WorldContextObject);
    
};

