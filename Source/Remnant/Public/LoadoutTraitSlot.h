#pragma once
#include "CoreMinimal.h"
#include "LoadoutSlot.h"
#include "Templates/SubclassOf.h"
#include "LoadoutTraitSlot.generated.h"

class ACharacterGunfire;
class UTraitType;
class UTraitsComponent;

UCLASS(Blueprintable)
class REMNANT_API ULoadoutTraitSlot : public ULoadoutSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTraitType> Type;
    
    ULoadoutTraitSlot();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTraitsComponent* GetTraitsComponent(ACharacterGunfire* Character) const;
    
};

