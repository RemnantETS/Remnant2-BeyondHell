#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "TargetQueryResult.h"
#include "TargetManager.generated.h"

class AActor;
class APawn;
class UTargetableComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTargetManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTargetableComponent*> RegisteredComponents;
    
public:
    UTargetManager();
    UFUNCTION(BlueprintCallable)
    static void QueryPotentialTargetsAlongAimVector(APawn* Source, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable, bool CullNotSoftTargetable, TArray<FTargetQueryResult>& Results, bool bSortResults);
    
    UFUNCTION(BlueprintCallable)
    static void QueryPotentialTargets(AActor* Source, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable, bool CullNotSoftTargetable, TArray<FTargetQueryResult>& Results, bool bSortResults);
    
    UFUNCTION(BlueprintCallable)
    static UTargetableComponent* QueryBestPotentialTargetAlongAimVector(APawn* Source, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable);
    
    UFUNCTION(BlueprintCallable)
    static UTargetableComponent* QueryBestPotentialTarget(AActor* Source, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable);
    
    UFUNCTION(BlueprintCallable)
    static float K2_GetScoreForTargetLocation(AActor* Source, const FVector& Target, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, const TArray<AActor*>& LOSIgnoreActors);
    
    UFUNCTION(BlueprintCallable)
    static float K2_GetScoreForTargetActor(AActor* Source, AActor* Target, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetSoftTargetLocation(AActor* Target, const FVector& OriginLocation);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetBestTargetingLocationOnActorForTarget(AActor* Source, const FVector& TargetLocation);
    
};

