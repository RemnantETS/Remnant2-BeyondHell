#pragma once
#include "CoreMinimal.h"
#include "Equipment.h"
#include "Armor.generated.h"

UCLASS(Blueprintable)
class REMNANT_API AArmor : public AEquipment {
    GENERATED_BODY()
public:
    AArmor(const FObjectInitializer& ObjectInitializer);

};

