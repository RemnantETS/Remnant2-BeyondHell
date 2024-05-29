#pragma once
#include "CoreMinimal.h"
#include "PrismSegment.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FPrismSegment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* ResolvedCDODataObject;
    
    REMNANT_API FPrismSegment();
};

