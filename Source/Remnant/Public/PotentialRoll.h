#pragma once
#include "CoreMinimal.h"
#include "PotentialRoll.generated.h"

USTRUCT(BlueprintType)
struct FPotentialRoll {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RollWeight;
    
    REMNANT_API FPotentialRoll();
};

