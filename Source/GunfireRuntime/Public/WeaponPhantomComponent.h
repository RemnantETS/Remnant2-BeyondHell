#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "ActiveWeaponPhantom.h"
#include "EWeaponPhantomReplicationMode.h"
#include "ImpactEffectDescriptor.h"
#include "ManagedTickInterface.h"
#include "ReplicatedHit.h"
#include "Templates/SubclassOf.h"
#include "WeaponPhantomInfo.h"
#include "WeaponPhantomComponent.generated.h"

class AActor;
class UDamageTypeGunfire;
class UObject;
class UPrimitiveComponent;
class UWeaponPhantomComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UWeaponPhantomComponent : public UActorComponent, public IManagedTickInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DefaultDamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactEffectDescriptor DefaultImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultHitCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultWeaponDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponPhantomReplicationMode ReplicationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipLagSupersampling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipEnvironmentHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowEnvironmentHitsAfterEvades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipWallChecks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoHitPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPausePhantomsDuringHitPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxHitPauses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitPausePenalty;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActiveWeaponPhantom> ActiveWeaponPhantoms;
    
public:
    UWeaponPhantomComponent();
    UFUNCTION(BlueprintCallable)
    void StopWeaponPhantom(UPrimitiveComponent* Shape);
    
    UFUNCTION(BlueprintCallable)
    void StopAllWeaponPhantoms();
    
    UFUNCTION(BlueprintCallable)
    void StartWeaponPhantom(const FWeaponPhantomInfo& PhantomInfo);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerApplyDamage(const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerApplyClientValidatedDamage(UWeaponPhantomComponent* Component, const FReplicatedHit& Hit, const FActiveWeaponPhantom& Phantom, bool bIsEnvironmentHit, bool bEvaded, bool bWasEvadeCounter, const UObject* EvadeSource);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void MarkActorHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void Ignore(UPrimitiveComponent* Shape, AActor* ActorToIgnore);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool HasRecentlyHitActor(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool HasGroupRecentlyHitActor(UObject* WorldContextObject, FName GroupName, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    bool DoHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    void ApplyPersistentGroupCooldown(AActor* Actor, float HitCooldown, FName GroupName);
    
    
    // Fix for true pure virtual functions not being implemented
};

