#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileMovementComponentGunfire.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UProjectileMovementComponentGunfire : public UProjectileMovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Penetrate;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ZeroPenetrationAdjustment;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AntiPenetrateSpeed;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainInitialRelativeRotation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent::FOnProjectileStopDelegate OnProjectileHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyPostBounceGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostBounceGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BounceNormalAlignmentAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalAlignmentUpwardsCosineThresh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpwardsBounceNormalAlignmentAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyPostBounceVelocityClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PostBounceMinMaxVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ECollisionChannel>> QueryOnlyBlockingChannels;
    
    UProjectileMovementComponentGunfire();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector SimulateBounce(FVector CurrentVelocity, const FHitResult& Hit, float& OutGravityScale);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldIgnoreNextPenetrate() const;
    
    UFUNCTION(BlueprintCallable)
    void SetPenetrate(bool bShouldPenetrate);
    
    UFUNCTION(BlueprintCallable)
    void SetMaintainCurrentRelativeRotation();
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreNextPenetrate(bool bShouldIgnore);
    
};

