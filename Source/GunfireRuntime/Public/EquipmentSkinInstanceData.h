#pragma once
#include "CoreMinimal.h"
#include "ItemInstanceData.h"
#include "EquipmentSkinInstanceData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UEquipmentSkinInstanceData : public UItemInstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    bool Equipped;
    
    UEquipmentSkinInstanceData();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};

