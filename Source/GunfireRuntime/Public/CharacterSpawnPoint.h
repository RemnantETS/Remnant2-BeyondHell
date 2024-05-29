#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "CharacterDiedEventDelegate.h"
#include "CharacterSpawnedEventDelegate.h"
#include "SpawnPoint.h"
#include "SpawnRelevanceInfo.h"
#include "Templates/SubclassOf.h"
#include "CharacterSpawnPoint.generated.h"

class AAIPathPoint;
class AActor;
class ACharacterGunfire;
class UCapsuleComponent;
class USpawnPointManager;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ACharacterSpawnPoint : public ASpawnPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterSpawnedEvent OnCharacterSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDiedEvent OnCharacterDied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacterGunfire> EnemyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CharacterTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDelayMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* PatrolPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAIPathPoint* SpawnPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyThreat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatToApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnRelevanceInfo SpawnRelevanceInfo;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesDeferredSpawnOptimization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* SpawnedCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle DeferredSpawnHandle;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEditorVisuals;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USpawnPointManager* SpawnPointManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacterGunfire*> SpawnedCharactersList;
    
public:
    ACharacterSpawnPoint();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Spawn(bool bUseDeferredOptimization);
    
    UFUNCTION(BlueprintCallable)
    void ResetSpawn(bool DestroySpawnedActors);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PostInitSpawnPoint();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCharacterDestroyed(AActor* DestroyedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumAliveSpawns();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<ACharacterGunfire> GetEnemyTypeOverride();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanSpawnFromDelay();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSpawn() const;
    
};

