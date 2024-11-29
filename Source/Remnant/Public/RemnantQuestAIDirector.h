#pragma once
#include "CoreMinimal.h"
#include "EncounterGroup.h"
#include "QuestActorDelegateDelegate.h"
#include "QuestManagerVoidDelegateDelegate.h"
#include "EventRegionCharacter.h"
#include "QuestAIDirectorNamedEventDelegate.h"
#include "RemnantQuestComponent.h"
#include "WorldResetInterface.h"
#include "RemnantQuestAIDirector.generated.h"

class AActor;
class UEncounterGroupInstance;
class USpawnTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestAIDirector : public URemnantQuestComponent, public IWorldResetInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEncounterGroup> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IncludeZoneGroups;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActorDelegate OnSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestActorDelegate OnDestroyed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestManagerVoidDelegate OnAllSpawnsDestroyed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestAIDirectorNamedEvent OnEncounterEvent;
    
public:
    URemnantQuestAIDirector(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void StopAllGroups(bool DestroyActiveSpawns);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnTable(USpawnTable* SpawnTable);
    
    UFUNCTION(BlueprintCallable)
    void OnEncounterGroupRemoved(UEncounterGroupInstance* EncounterGroup);
    
    UFUNCTION(BlueprintCallable)
    void OnEncounterGroupActorSpawned(UEncounterGroupInstance* EncounterGroup, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnEncounterGroupActorDead(UEncounterGroupInstance* EncounterGroup, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveSpawns(bool IncludeQueuedSpawns);
    
    UFUNCTION(BlueprintCallable)
    int32 GetTotalSpawns(bool IncludeQueuedSpawns);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerExit(FEventRegionCharacter Character);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerEnter(FEventRegionCharacter Character);
    
    UFUNCTION(BlueprintCallable)
    void EventEncounterEvent(UEncounterGroupInstance* EncounterGroup, FName EventName);
    
    
    // Fix for true pure virtual functions not being implemented
};

