#include "CombatUtil.h"
#include "Templates/SubclassOf.h"

void UCombatUtil::WeaponTraceEx(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace, FWeaponTracePath& OutPath) {
}

FHitResult UCombatUtil::WeaponTrace(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace) {
    return FHitResult{};
}

void UCombatUtil::SpawnOverlapImpactEffects(UObject* WorldContextObject, const FImpactEffectSelector& ImpactEffect, FHitResult& Hit, const FTransform& SpawnTransform) {
}

void UCombatUtil::SpawnImpactEffectsFromTrace(AActor* Cause, const FImpactEffectSelector& ImpactEffect, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, AActor* Ignore) {
}

bool UCombatUtil::SpawnImpactEffectProjectile(AActor* Projectile, AActor* HitActor, const FImpactEffectSelector& ImpactEffect) {
    return false;
}

void UCombatUtil::SpawnImpactEffectAOE(AActor* HitActor, const FImpactEffectSelector& ImpactEffect, const FVector& AOESourceLocation) {
}

void UCombatUtil::SpawnImpactEffect(const UObject* WorldContextObject, const FImpactEffectDescriptor& ImpactEffectDescriptor, const FHitResult& Impact, const FGunfireAudioPlayParams& AudioPlayParams) {
}

void UCombatUtil::SpawnBestImpactEffect(AActor* Cause, const FImpactEffectDescriptor& ImpactEffectDescriptor, const FHitResult& Impact, bool UseBodyPhysicsMaterial) {
}

TSubclassOf<UDamageTypeGunfire> UCombatUtil::ResolveDamageType(AActor* Cause, AActor* Owner) {
    return NULL;
}

AActor* UCombatUtil::ResolveDamageOwner(AActor* Cause) {
    return NULL;
}

FVector UCombatUtil::PredictLocation(ACharacter* Querier, ACharacter* Target, float Time, float Offset) {
    return FVector{};
}

bool UCombatUtil::IsViewTargetedPlayerInRangeOf(UObject* WorldContextObject, const FVector& ReferencePoint, float Range, bool UseNavDistance, APawn* OptionalNavAgentOverride) {
    return false;
}

bool UCombatUtil::IsViewTargetedPlayerInBoundsOf(UObject* WorldContextObject, const FVector& ReferencePoint, const FVector& BoundsExtent) {
    return false;
}

bool UCombatUtil::IsValidAimTarget(AActor* TestTarget, const AActor* AimingOwner) {
    return false;
}

bool UCombatUtil::IsFriendly(AActor* Actor1, AActor* Actor2) {
    return false;
}

bool UCombatUtil::IsEnemy(AActor* Actor1, AActor* Actor2) {
    return false;
}

bool UCombatUtil::IsDamageable(AActor* Actor) {
    return false;
}

bool UCombatUtil::IsAlive(AActor* Damageable) {
    return false;
}

bool UCombatUtil::IgnoresWeakspotStatRequirement(TSubclassOf<UDamageType> DamageType) {
    return false;
}

bool UCombatUtil::HasHealingClass(TSubclassOf<UHealingTypeGunfire> HealingType, TSubclassOf<UHealingClass> RequiredClass) {
    return false;
}

bool UCombatUtil::HasDamageClass(TSubclassOf<UDamageType> DamageType, TSubclassOf<UDamageClass> RequiredClass) {
    return false;
}

bool UCombatUtil::GetTargetVector(AActor* Cause, FName SourceSocket, AActor* Target, bool SnapToGround, FVector& Origin, FVector& End) {
    return false;
}

bool UCombatUtil::GetReticuleLocation(APawn* Pawn, float Range, float Radius, FRotator& Direction, FVector& Location) {
    return false;
}

TArray<ARangedWeapon*> UCombatUtil::GetRangedWeaponsForCharacter(AActor* Target, EEquipmentTarget WeaponTarget, FName TargetSlotNameID) {
    return TArray<ARangedWeapon*>();
}

FName UCombatUtil::GetRandomHitPhantomThatIsntInvulnerable(const UObject* WorldContextObject, const AActor* Actor, const FVector& ImpactPoint, const FVector& Origin, float Radius) {
    return NAME_None;
}

AActor* UCombatUtil::GetPlayerCameraAimTarget(APawn* Cause, float Range) {
    return NULL;
}

bool UCombatUtil::GetPlayerAimVector(APawn* Cause, float Range, FVector& Origin, FVector& End) {
    return false;
}

float UCombatUtil::GetMinimumTotalDamageReductionScalar() {
    return 0.0f;
}

float UCombatUtil::GetMaximumDamageReductionPerStat() {
    return 0.0f;
}

float UCombatUtil::GetFalloffDamagePenalty() {
    return 0.0f;
}

TSubclassOf<UFaction> UCombatUtil::GetFaction(const AActor* Actor) {
    return NULL;
}

FVector UCombatUtil::GetEyePos(ACharacter* Character) {
    return FVector{};
}

AEquipment* UCombatUtil::GetEquippedItemForCharacter(AActor* Target, FName EquipmentSlot) {
    return NULL;
}

float UCombatUtil::GetDamageReductionFromResistanceByDamageClass(const UDamageClass* DamageClass, float DamageResistance, float AttackerLevel) {
    return 0.0f;
}

float UCombatUtil::GetDamageReductionByDamageClass(const UDamageClass* DamageClass, float DamageReduction) {
    return 0.0f;
}

FVector UCombatUtil::GetChestPos(ACharacter* Character) {
    return FVector{};
}

FVector UCombatUtil::GetBasePos(AActor* Actor) {
    return FVector{};
}

bool UCombatUtil::GetApproximateSurfaceNormalForLocation(UObject* WorldContextObject, const FSurfaceNormalCheckParams& Params, FVector& OutSurfaceNormal, FVector& OutPlaneOrigin) {
    return false;
}

bool UCombatUtil::GetAimVector(AActor* Cause, FName SourceSocket, float Range, FVector& Origin, FVector& End) {
    return false;
}

FVector UCombatUtil::GetAimPos(AActor* Actor, AActor* Target) {
    return FVector{};
}

EAffiliation UCombatUtil::GetAffiliation(const AActor* Actor1, const AActor* Actor2) {
    return EAffiliation::SuperFriendly;
}

void UCombatUtil::FireProjectileAsync(UObject* WorldContextObject, TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params, EFireOutExec& Exec, FHitResult& HitResult, FLatentActionInfo LatentInfo) {
}

AActor* UCombatUtil::FireProjectile(TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params) {
    return NULL;
}

FDamageInfo UCombatUtil::CreateDamageInfoFromTarget(AActor* Cause, AActor* Target, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
    return FDamageInfo{};
}

FDamageInfo UCombatUtil::CreateDamageInfoFromHit(AActor* Cause, const FHitResult& Hit, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
    return FDamageInfo{};
}

float UCombatUtil::ComputeDamageFalloffFromDistance(float Distance, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve) {
    return 0.0f;
}

float UCombatUtil::ComputeDamageFalloff(const FVector& Source, AActor* Target, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve) {
    return 0.0f;
}

FVector UCombatUtil::CalculateArcVelocity(const FVector& Start, const FVector& End, float Gravity, float Speed, float ArcHeight, float& TravelTime, EAutoArcType Type) {
    return FVector{};
}

TArray<FVector> UCombatUtil::ApplyWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, FRandomStream& RandomStream) {
    return TArray<FVector>();
}

void UCombatUtil::ApplySelfHealing(AActor* Target, float Healing, float HealingMod, float HealingScalar, TSubclassOf<UHealingTypeGunfire> HealingType) {
}

void UCombatUtil::ApplyHealing(AActor* Owner, AActor* CauseActor, AActor* TargetActor, float Healing, float HealingMod, float HealingScalar, TSubclassOf<UHealingTypeGunfire> HealingType) {
}

void UCombatUtil::ApplyDamageInfo(UObject* WorldContextObject, FDamageInfo DamageInfo, FDamageInfo& Result) {
}

void UCombatUtil::ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
}

TArray<FVector> UCombatUtil::ApplyCustomWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, FRandomStream& RandomStream, const FCustomWeaponSpread& CustomSpread) {
    return TArray<FVector>();
}

bool UCombatUtil::AllowsWeakSpots(TSubclassOf<UDamageType> DamageType) {
    return false;
}

bool UCombatUtil::AllowsPiercing(TSubclassOf<UDamageType> DamageType) {
    return false;
}

bool UCombatUtil::AllowsCriticalHits(TSubclassOf<UDamageType> DamageType) {
    return false;
}

bool UCombatUtil::AllowAction(ACharacterGunfire* Character) {
    return false;
}

UCombatUtil::UCombatUtil() {
}

