#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DamageInfo.h"
#include "HitLocationInfo.h"
#include "HitLogComponent.generated.h"

class UAnimInstanceGunfire;
class UPhysicalMaterial;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UHitLogComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeakSpotDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResistSpotDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FHitLocationInfo> HitLocations;
    
protected:
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_DestroyedFlags, meta=(AllowPrivateAccess=true))
    uint32 RepDestroyedFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LastHitLocation, meta=(AllowPrivateAccess=true))
    uint8 LastHitLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo LastHitInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDamageInfo LastDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* AnimInstance;
    
public:
    UHitLogComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void ResetAllHitLocationHealth();
    
    UFUNCTION(BlueprintCallable)
    void RepairHitLocation(FName HitLocationName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_LastHitLocation();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_DestroyedFlags();
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsMaterialWeakspot(UPhysicalMaterial* PhysicsMaterial);
    
    UFUNCTION(BlueprintCallable)
    bool IsMaterialResisted(UPhysicalMaterial* PhysicsMaterial);
    
    UFUNCTION(BlueprintCallable)
    UPhysicalMaterial* GetMaterialForHitLocation(FName HitLocation);
    
    UFUNCTION(BlueprintCallable)
    FDamageInfo GetLastHitInfo();
    
    UFUNCTION(BlueprintCallable)
    FDamageInfo GetLastDamageInfo();
    
    UFUNCTION(BlueprintCallable)
    float GetImpactDamageForHitLocation(const FDateTime& Time, const FName& HitLocation, bool bIgnoreImpactScalar);
    
    UFUNCTION(BlueprintCallable)
    float GetDamageScalarForMaterial(UPhysicalMaterial* PhysicsMaterial);
    
    UFUNCTION(BlueprintCallable)
    float GetDamageForHitLocation(const FDateTime& Time, const FName& HitLocation);
    
    UFUNCTION(BlueprintCallable)
    float GetDamage(const FDateTime& Time);
    
    UFUNCTION(BlueprintCallable)
    void DeactivateHitLocation(FName HitLocationName);
    
    UFUNCTION(BlueprintCallable)
    void ClearHitLog();
    
};

