#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "EquipmentLevelCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEquipmentLevelCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    UEquipmentLevelCondition();

};

