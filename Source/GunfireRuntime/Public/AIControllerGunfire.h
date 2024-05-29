#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "UObject/NoExportTypes.h"
#include "AITacticalPoint.h"
#include "EAwarenessSignal.h"
#include "ENodePathStatus.h"
#include "EPlayerRelevancyMode.h"
#include "EventOnPawnUnpossessedDelegate.h"
#include "Templates/SubclassOf.h"
#include "AIControllerGunfire.generated.h"

class AAIControllerGunfire;
class AAIGoalActor;
class AAIPathPoint;
class AActor;
class ACharacterGunfire;
class UAITargetSelector;
class UNavigationQueryFilter;
class UObject;

UCLASS(Blueprintable, Config=Game)
class GUNFIRERUNTIME_API AAIControllerGunfire : public AAIController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSeeksTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Persistent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SightAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LostSightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BonusLostSightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearSightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNearSightRequiresLoS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereLOSRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereLOFRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HearingScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HearingOcclusionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertGiveUpDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertGiveUpTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AwareDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AwarePulseRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EvaluateFriendlyTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerRelevancyMode PlayerRelevancy;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceEvaluatePlayers;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PathToLastKnownPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EyeSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoverAimAdjustDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAITargetSelector> DefaultTargetSelector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAITargetSelector> CurrentTargetSelector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENodePathStatus NodePathStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverridenByCinematic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventOnPawnUnpossessed OnPawnUnpossessed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> RelevantActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> CurrentTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ThreatLeader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAITacticalPoint TacticalPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool TacticalPointIsValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAIGoalActor* PathToActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAIPathPoint* PathPoint;
    
public:
    AAIControllerGunfire();
    UFUNCTION(BlueprintCallable)
    void UpdateAwareness(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    void UnlockCurrentTarget();
    
    UFUNCTION(BlueprintCallable)
    bool TestPathTo(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetSelector(TSubclassOf<UAITargetSelector> NewTargetSelector, bool bUpdateTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnLocation(FVector SpawnLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetRelevantActorFilterClass(TSubclassOf<AActor> FilterClass);
    
    UFUNCTION(BlueprintCallable)
    void SetNavigationFilter(TSubclassOf<UNavigationQueryFilter> NavFilter);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentTarget(AActor* Actor, bool bLockOn);
    
    UFUNCTION(BlueprintCallable)
    void SendAwarenessSignal(EAwarenessSignal Type, AActor* Source, const FVector& Position, float Radius, bool UseSourceForLastKnownPosition, bool bApplySightRangeBonus);
    
    UFUNCTION(BlueprintCallable)
    void ResetThreat();
    
    UFUNCTION(BlueprintCallable)
    void ResetAwareness();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSetTacticalPoint(const FAITacticalPoint& NewTacticalPoint);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFactionChanged(ACharacterGunfire* InCharacter);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnClearTacticalPoint();
    
    UFUNCTION(BlueprintCallable)
    void LockCurrentTarget();
    
    UFUNCTION(BlueprintCallable)
    AActor* K2_GetBestTarget(TSubclassOf<UAITargetSelector> Selector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActorCurrentlyRelevant(AActor* TestActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLineOfSightToAnyPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLineOfSight(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetThreatLeader() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTargetChangedThisFrame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTacticalPointValid();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAITacticalPoint GetTacticalPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPathTarget(FVector& TargetPos, FName PathTargetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAIPathPoint* GetPathPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<AAIControllerGunfire*> GetNearbyAI(const UObject* WorldContextObject, FVector Origin, float Radius, TArray<AAIControllerGunfire*> IgnoreList);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UNavigationQueryFilter> GetNavigationFilter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EPathFollowingResult::Type> GetLastPathFollowingCode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UAITargetSelector> GetCurrentTargetSelector() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCurrentTarget() const;
    
    UFUNCTION(BlueprintCallable)
    void AddThreat(AActor* ThreatCharacter, float Amount, bool bApplySightRangeBonus);
    
    UFUNCTION(BlueprintCallable)
    void AddPersistentTarget(AActor* Target);
    
};

