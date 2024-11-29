#pragma once
#include "CoreMinimal.h"
#include "QuestNameDelegateDelegate.h"
#include "QuestVoidDelegateDelegate.h"
#include "EncounterWave.h"
#include "EventRegionCharacter.h"
#include "RemnantQuestComponent.h"
#include "RemnantQuestWaveEncounter.generated.h"

class AActor;
class AEventRegion;
class UEncounterInstance;
class USpawnTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestWaveEncounter : public URemnantQuestComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnTable* SpawnTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEncounterWave> Waves;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestNameDelegate OnWaveComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnAllWavesComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* EncounterTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEventRegion* EventRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEncounterInstance* EncounterInstance;
    
public:
    URemnantQuestWaveEncounter(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void WaveComplete(UEncounterInstance* Instance);
    
private:
    UFUNCTION(BlueprintCallable)
    void Stop(bool DestroyActiveSpawns);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SpawnWave();
    
private:
    UFUNCTION(BlueprintCallable)
    void Resume();
    
    UFUNCTION(BlueprintCallable)
    void Pause();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsQuestWaveActive() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventPlayerExit(FEventRegionCharacter Character);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerEnter(FEventRegionCharacter Character);
    
    UFUNCTION(BlueprintCallable)
    void EventOnEnd();
    
private:
    UFUNCTION(BlueprintCallable)
    void Begin(AActor* Target);
    
};

