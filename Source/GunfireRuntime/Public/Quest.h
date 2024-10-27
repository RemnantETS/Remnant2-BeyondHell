#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EQuestResult.h"
#include "EQuestState.h"
#include "QuestCompleteDelegateDelegate.h"
#include "VariableDef.h"
#include "Quest.generated.h"

class AQuest;
class UQuestComponent;
class UQuestObjective;
class UTexture2D;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AQuest : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName QuestNameID;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName QuestScope;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> QuestTags;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ParentQuestTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVariableDef> Variables;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ParentQuestID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    EQuestState QuestState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    EQuestResult QuestResult;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestCompleteDelegate OnQuestCompleteEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UQuestObjective*> QuestObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AQuest*> ChildQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UQuestComponent* ParentQuestComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UQuestComponent*> NewUnprocessedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UQuestComponent*> NewProcessingComponents;
    
public:
    AQuest(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetObjectiveCounterMax(FName NameID, int32 MaxCount);
    
    UFUNCTION(BlueprintCallable)
    void ResetObjective(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllObjectives(bool ResetQuestState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnResetQuest();
    
    UFUNCTION(BlueprintCallable)
    void OnQuestManagerReady();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnQuestComplete(EQuestResult Result);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostInitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostCreateQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnObjectiveUpdated(UQuestObjective* Objective);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnObjectiveComplete(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnObjectiveActivate(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDestroyQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeinitializeQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCreateQuest(const FRandomStream& RandomStream);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeginQuest();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NotifyQuestComplete(EQuestResult Result);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsQuestComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsQuestActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectiveComplete(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectiveActive(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    void IncrementObjectiveCounter(FName NameID, bool AutoComplete);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveObjectives(bool IncludeHidden);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetUniqueName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuest* GetRootQuestForScope();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuest* GetRootQuest();
    
    UFUNCTION(BlueprintCallable)
    void GetQuestObjectives(TArray<UQuestObjective*>& Objectives);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UQuestObjective* GetQuestObjective(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AQuest* GetParentQuest();
    
    UFUNCTION(BlueprintCallable)
    int32 GetObjectiveCountRemaining(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetObjectiveCounterMax(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    int32 GetObjectiveCounter(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    void CompleteQuest(EQuestResult Result);
    
    UFUNCTION(BlueprintCallable)
    void CompleteObjective(FName NameID, EQuestResult ObjectiveResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAnyObjectivesActiveOrComplete();
    
    UFUNCTION(BlueprintCallable)
    void ActivateObjective(FName NameID, bool AutoCompleteActiveObjectives);
    
};

