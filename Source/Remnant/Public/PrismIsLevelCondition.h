#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "PrismIsLevelCondition.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UPrismIsLevelCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IncludeStackedLevels;
    
    UPrismIsLevelCondition();

};

