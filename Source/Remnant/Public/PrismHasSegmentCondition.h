#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "PrismHasSegmentCondition.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UPrismHasSegmentCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SegmentNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    UPrismHasSegmentCondition();
};

