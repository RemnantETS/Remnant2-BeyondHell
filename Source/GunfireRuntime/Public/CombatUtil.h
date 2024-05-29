#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/LatentActionManager.h"
#include "CustomWeaponSpread.h"
#include "DamageInfo.h"
#include "EAffiliation.h"
#include "EAutoArcType.h"
#include "EEquipmentTarget.h"
#include "EFireOutExec.h"
#include "GunfireAudioPlayParams.h"
#include "ImpactEffectDescriptor.h"
#include "ImpactEffectSelector.h"
#include "ProjectileParams.h"
#include "SurfaceNormalCheckParams.h"
#include "Templates/SubclassOf.h"
#include "WeaponTracePath.h"
#include "CombatUtil.generated.h"

class AActor;
class ACharacter;
class ACharacterGunfire;
class AEquipment;
class APawn;
class ARangedWeapon;
class UCurveFloat;
class UDamageClass;
class UDamageType;
class UDamageTypeGunfire;
class UFaction;
class UHealingClass;
class UHealingTypeGunfire;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCombatUtil : public UObject {
    GENERATED_BODY()
public:
    UCombatUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void WeaponTraceEx(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace, FWeaponTracePath& OutPath);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FHitResult WeaponTrace(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SpawnOverlapImpactEffects(UObject* WorldContextObject, const FImpactEffectSelector& ImpactEffect, UPARAM(Ref) FHitResult& Hit, const FTransform& SpawnTransform);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnImpactEffectsFromTrace(AActor* Cause, const FImpactEffectSelector& ImpactEffect, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, AActor* Ignore);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnImpactEffectProjectile(AActor* Projectile, AActor* HitActor, const FImpactEffectSelector& ImpactEffect);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnImpactEffectAOE(AActor* HitActor, const FImpactEffectSelector& ImpactEffect, const FVector& AOESourceLocation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SpawnImpactEffect(const UObject* WorldContextObject, const FImpactEffectDescriptor& ImpactEffectDescriptor, const FHitResult& Impact, const FGunfireAudioPlayParams& AudioPlayParams);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnBestImpactEffect(AActor* Cause, const FImpactEffectDescriptor& ImpactEffectDescriptor, const FHitResult& Impact, bool UseBodyPhysicsMaterial);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UDamageTypeGunfire> ResolveDamageType(AActor* Cause, AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* ResolveDamageOwner(AActor* Cause);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector PredictLocation(ACharacter* Querier, ACharacter* Target, float Time, float Offset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsViewTargetedPlayerInRangeOf(UObject* WorldContextObject, const FVector& ReferencePoint, float Range, bool UseNavDistance, APawn* OptionalNavAgentOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsViewTargetedPlayerInBoundsOf(UObject* WorldContextObject, const FVector& ReferencePoint, const FVector& BoundsExtent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsValidAimTarget(AActor* TestTarget, const AActor* AimingOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsFriendly(AActor* Actor1, AActor* Actor2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsEnemy(AActor* Actor1, AActor* Actor2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDamageable(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAlive(AActor* Damageable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IgnoresWeakspotStatRequirement(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasHealingClass(TSubclassOf<UHealingTypeGunfire> HealingType, TSubclassOf<UHealingClass> RequiredClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasDamageClass(TSubclassOf<UDamageType> DamageType, TSubclassOf<UDamageClass> RequiredClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetTargetVector(AActor* Cause, FName SourceSocket, AActor* Target, bool SnapToGround, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetReticuleLocation(APawn* Pawn, float Range, float Radius, FRotator& Direction, FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<ARangedWeapon*> GetRangedWeaponsForCharacter(AActor* Target, EEquipmentTarget WeaponTarget, FName TargetSlotNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FName GetRandomHitPhantomThatIsntInvulnerable(const UObject* WorldContextObject, const AActor* Actor, const FVector& ImpactPoint, const FVector& Origin, float Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetPlayerCameraAimTarget(APawn* Cause, float Range);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetPlayerAimVector(APawn* Cause, float Range, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetMinimumTotalDamageReductionScalar();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetMaximumDamageReductionPerStat();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetFalloffDamagePenalty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UFaction> GetFaction(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetEyePos(ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AEquipment* GetEquippedItemForCharacter(AActor* Target, FName EquipmentSlot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDamageReductionFromResistanceByDamageClass(const UDamageClass* DamageClass, float DamageResistance, float AttackerLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDamageReductionByDamageClass(const UDamageClass* DamageClass, float DamageReduction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetChestPos(ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetBasePos(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool GetApproximateSurfaceNormalForLocation(UObject* WorldContextObject, const FSurfaceNormalCheckParams& Params, FVector& OutSurfaceNormal, FVector& OutPlaneOrigin);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetAimVector(AActor* Cause, FName SourceSocket, float Range, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetAimPos(AActor* Actor, AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EAffiliation GetAffiliation(const AActor* Actor1, const AActor* Actor2);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    static void FireProjectileAsync(UObject* WorldContextObject, TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params, EFireOutExec& Exec, FHitResult& HitResult, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable)
    static AActor* FireProjectile(TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDamageInfo CreateDamageInfoFromTarget(AActor* Cause, AActor* Target, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDamageInfo CreateDamageInfoFromHit(AActor* Cause, const FHitResult& Hit, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ComputeDamageFalloffFromDistance(float Distance, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ComputeDamageFalloff(const FVector& Source, AActor* Target, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve);
    
    UFUNCTION(BlueprintCallable)
    static FVector CalculateArcVelocity(const FVector& Start, const FVector& End, float Gravity, float Speed, float ArcHeight, float& TravelTime, EAutoArcType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FVector> ApplyWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, UPARAM(Ref) FRandomStream& RandomStream);
    
    UFUNCTION(BlueprintCallable)
    static void ApplySelfHealing(AActor* Target, float Healing, float HealingMod, float HealingScalar, TSubclassOf<UHealingTypeGunfire> HealingType);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyHealing(AActor* Owner, AActor* CauseActor, AActor* TargetActor, float Healing, float HealingMod, float HealingScalar, TSubclassOf<UHealingTypeGunfire> HealingType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ApplyDamageInfo(UObject* WorldContextObject, FDamageInfo DamageInfo, FDamageInfo& Result);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FVector> ApplyCustomWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, UPARAM(Ref) FRandomStream& RandomStream, const FCustomWeaponSpread& CustomSpread);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowsWeakSpots(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowsPiercing(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowsCriticalHits(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowAction(ACharacterGunfire* Character);
    
};

