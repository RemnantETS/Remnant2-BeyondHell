#pragma once
#include "CoreMinimal.h"
#include "QuestManager.h"
#include "QuestManagerQuestDelegateDelegate.h"
#include "QuestVoidDelegateDelegate.h"
#include "EQuestMode.h"
#include "RemnantQuestEntry.h"
#include "RemnantQuestManager.generated.h"

class AActor;
class ARemnantQuest;
class UQuestObjective;
class UVariables;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestManager : public UQuestManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVariables* RootQuestVariables;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerQuestDelegate OnQuestLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnQuestCheckpointSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerQuestDelegate OnRootQuestActivated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestEntry> RegisteredQuests;
    
public:
    URemnantQuestManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FRemnantQuestEntry> SortQuestList(const TArray<FRemnantQuestEntry>& QuestList);
    
    UFUNCTION(BlueprintCallable)
    void ResetTransientRootQuests();
    
    UFUNCTION(BlueprintCallable)
    void MarkOneShotRolled(const FRemnantQuestEntry& Quest);
    
    UFUNCTION(BlueprintCallable)
    bool IsQuestValid(ARemnantQuest* Quest, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    bool IsOneShotRolled(const FRemnantQuestEntry& Quest);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARemnantQuest*> GetRootQuests() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRootQuestForSlot(int32 SlotID) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredRootQuestsForMode(EQuestMode Mode);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredRootQuests();
    
    UFUNCTION(BlueprintCallable)
    TArray<FRemnantQuestEntry> GetRegisteredQuests();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRemnantQuestEntry GetRegisteredQuestByID(const FString& QuestID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRemnantQuestEntry GetRegisteredQuestByClass(TSoftClassPtr<ARemnantQuest> QuestBP);
    
    UFUNCTION(BlueprintCallable)
    void GetQuestsForActor(AActor* Actor, bool IncludeInjectedQuests, TArray<ARemnantQuest*>& Rtn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestObjective* GetCurrentQuestObjective(ARemnantQuest* Quest);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetActiveRootQuest() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DestroyRootQuest(ARemnantQuest* Quest) const;
    
    UFUNCTION(BlueprintCallable)
    ARemnantQuest* CreateRootQuest(int32 SlotID, const FString& QuestID, int32 Difficulty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool ActivateRootQuest(ARemnantQuest* Quest) const;
    
};

