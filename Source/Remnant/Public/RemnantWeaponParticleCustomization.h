#pragma once
#include "CoreMinimal.h"
#include "ParticleCustomization.h"
#include "RemnantWeaponParticleCustomization.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URemnantWeaponParticleCustomization : public UParticleCustomization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdatePowerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateChargesChaged;
    
    URemnantWeaponParticleCustomization();
};

