#pragma once
#include "CoreMinimal.h"
#include "EquipmentInstanceData.h"
#include "RangedWeaponInstanceData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API URangedWeaponInstanceData : public UEquipmentInstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Ammo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MinorChange, meta=(AllowPrivateAccess=true))
    int32 AmmoInClip;
    
    URangedWeaponInstanceData();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
};

