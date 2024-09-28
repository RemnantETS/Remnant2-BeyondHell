#pragma once
#include "CoreMinimal.h"
#include "ItemQuantity.generated.h"

class AItem;

USTRUCT(BlueprintType)
struct FItemQuantity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> ItemBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    GUNFIRERUNTIME_API FItemQuantity();
};

