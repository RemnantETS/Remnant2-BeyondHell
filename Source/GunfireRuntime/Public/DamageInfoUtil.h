#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DamageInfo.h"
#include "Templates/SubclassOf.h"
#include "DamageInfoUtil.generated.h"

class UDamageType;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UDamageInfoUtil : public UObject {
    GENERATED_BODY()
public:
    UDamageInfoUtil();
    UFUNCTION(BlueprintCallable)
    static void SetPower(UPARAM(Ref) FDamageInfo& Info, int32 Power);
    
    UFUNCTION(BlueprintCallable)
    static void SetIsSecondaryDamage(UPARAM(Ref) FDamageInfo& Info, bool IsSecondaryDamage);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamageType(UPARAM(Ref) FDamageInfo& Info, TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamage(UPARAM(Ref) FDamageInfo& Info, int32 Damage);
    
    UFUNCTION(BlueprintCallable)
    static void ModifyDamage(UPARAM(Ref) FDamageInfo& Info, float Damage, float DamageMod, float DamageScalar);
    
    UFUNCTION(BlueprintCallable)
    static void ModifyCrit(UPARAM(Ref) FDamageInfo& Info, float CritChance, float CritDamageMod);
    
    UFUNCTION(BlueprintCallable)
    static void MarkRequiresClientAuthorization(UPARAM(Ref) FDamageInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    static void MarkClientAuthorizedDamage(UPARAM(Ref) FDamageInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    static float GetTotalAppliedDamage(const FDamageInfo& Info);
    
};

