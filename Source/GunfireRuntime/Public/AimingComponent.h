#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "AimingParameters.h"
#include "ERangedWeaponTrajectoryMode.h"
#include "ProjectileVisualizationContext.h"
#include "WeaponTracePath.h"
#include "AimingComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAimingComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAimingParameters DefaultAimingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultMuzzleAttachPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoActivateWhileAiming;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FProjectileVisualizationContext VisualizationContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAimingParameters AimingParametersOverride;
    
public:
    UAimingComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool UsesProjectileVisualization() const;
    
    UFUNCTION(BlueprintCallable)
    void SetAimingParametersOverride(const FAimingParameters& NewParameters);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProjectileVisualizationContext GetProjectileVisualization() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetMuzzleObstruction();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetFirstNonPiercedAimTarget(bool bInitialSegmentOnly) const;
    
    UFUNCTION(BlueprintCallable)
    void GetAimVector(FVector& From, FVector& To, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAimTargetLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetAimTarget(bool bInitialSegmentOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FWeaponTracePath GetAimPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAimingParameters GetAimingParameters() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearAimingParametersOverride();
    
};

