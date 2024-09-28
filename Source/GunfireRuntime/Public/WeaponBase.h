#pragma once
#include "CoreMinimal.h"
#include "DamageSourceInterface.h"
#include "Equipment.h"
#include "ImpactEffectDescriptor.h"
#include "OnWeaponPhantomBeginDelegateDelegate.h"
#include "OnWeaponPhantomEndDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "WeaponBase.generated.h"

class AActor;
class UDamageTypeGunfire;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AWeaponBase : public AEquipment, public IDamageSourceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactEffectDescriptor ImpactEffect;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWeaponPhantomBeginDelegate OnWeaponPhantomBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWeaponPhantomEndDelegate OnWeaponPhantomEnd;
    
    AWeaponBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProcChance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FImpactEffectDescriptor GetImpactEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAttackSpeed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void ComputeDamage(AActor* Actor, float& Damage, float& AttackRating);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AttemptProc(float BonusChance) const;
    

    // Fix for true pure virtual functions not being implemented
};

