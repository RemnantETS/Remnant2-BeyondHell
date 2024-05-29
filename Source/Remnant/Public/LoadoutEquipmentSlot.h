#pragma once
#include "CoreMinimal.h"
#include "LoadoutSlot.h"
#include "Templates/SubclassOf.h"
#include "LoadoutEquipmentSlot.generated.h"

class ACharacterGunfire;
class AEquipment;
class UItemType;

UCLASS(Blueprintable)
class REMNANT_API ULoadoutEquipmentSlot : public ULoadoutSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> SlotType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordEquipmentMods;
    
    ULoadoutEquipmentSlot();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquipment(ACharacterGunfire* Character) const;
    
};

