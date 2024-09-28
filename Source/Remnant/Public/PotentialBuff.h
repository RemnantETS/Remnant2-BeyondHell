#pragma once
#include "CoreMinimal.h"
#include "PotentialBuff.generated.h"

USTRUCT(BlueprintType)
struct FPotentialBuff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RollWeight;
    
    REMNANT_API FPotentialBuff();
};

