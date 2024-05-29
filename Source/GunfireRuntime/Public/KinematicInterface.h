#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Engine/HitResult.h"
#include "DamageInfo.h"
#include "ImpactEffectDescriptor.h"
#include "ImpactEffectSelector.h"
#include "KinematicInfo.h"
#include "Templates/SubclassOf.h"
#include "WeaponTracePath.h"
#include "WeaponTraceSegment.h"
#include "KinematicInterface.generated.h"

class AActor;
class UDamageTypeGunfire;
class UWeaponPhantomComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UKinematicInterface : public UInterface {
    GENERATED_BODY()
};

class IKinematicInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldTargetImpactPoint(const FHitResult& Hit) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnKinematicProjectileHit(AActor* Projectile, const FHitResult& Hit, UPARAM(Ref) FKinematicInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnKinematicPhantomHit(UWeaponPhantomComponent* WeaponPhantom, UPARAM(Ref) FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnHitscanHit(AActor* HitscanOwner, AActor* Cause, const FHitResult& Hit, const FDamageInfo& DamageInfo, bool bIsFinalHit, UPARAM(Ref) FImpactEffectSelector& InOutImpactEffectOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ModifyWeaponTrace(AActor* Cause, const FWeaponTraceSegment& CurrentSegment, const FVector& Size, UPARAM(Ref) FWeaponTracePath& InOutPath);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ModifyPhantomCooldownActor(AActor*& OutActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyImpactEffects(const FHitResult& Hit, const FDamageInfo& DamageInfo, bool bIsFinalHit, UPARAM(Ref) FImpactEffectDescriptor& InOutImpactEffectOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyHitscanDamageType(const FHitResult& Hit, UPARAM(Ref) TSubclassOf<UDamageTypeGunfire>& InOutDamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyHitscanDamage(const FHitResult& Hit, UPARAM(Ref) FDamageInfo& InOutDamageInfo);
    
};

