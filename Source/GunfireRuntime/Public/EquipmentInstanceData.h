#pragma once
#include "CoreMinimal.h"
#include "EquipmentMods.h"
#include "ItemInstanceData.h"
#include "EquipmentInstanceData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UEquipmentInstanceData : public UItemInstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    FEquipmentMods Mods;
    
    UEquipmentInstanceData();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};

