#pragma once
#include "CoreMinimal.h"
#include "RemnantRangedWeapon.h"
#include "RemnantBeamWeapon.generated.h"

UCLASS(Blueprintable)
class REMNANT_API ARemnantBeamWeapon : public ARemnantRangedWeapon {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BeamFiring, meta=(AllowPrivateAccess=true))
    bool BeamWeaponFiring;
    
public:
    ARemnantBeamWeapon(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void SetBeamFiring_Server(bool Firing);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_BeamFiring();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndBeamFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeginBeamFX();
    
    UFUNCTION(BlueprintCallable)
    bool IsBeamFiring();
    
};

