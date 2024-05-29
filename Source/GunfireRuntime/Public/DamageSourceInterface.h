#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInfo.h"
#include "HealingInfo.h"
#include "ImpactEffectDescriptor.h"
#include "Templates/SubclassOf.h"
#include "DamageSourceInterface.generated.h"

class UDamageTypeGunfire;

UINTERFACE(Blueprintable, MinimalAPI)
class UDamageSourceInterface : public UInterface {
    GENERATED_BODY()
};

class IDamageSourceInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResolveOwner(const FDamageInfo& In, FDamageInfo& Out);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyTargetResistedHit(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyHitTarget(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyHealFailed(const FHealingInfo& HealingInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void NotifyHealedTarget(const FHealingInfo& HealingInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyDamage(UPARAM(Ref) FDamageInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FImpactEffectDescriptor GetImpactEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<UDamageTypeGunfire> GetDamageType();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GatherDamageCooldownTags(UPARAM(Ref) TArray<FName>& Tags);
    
};

