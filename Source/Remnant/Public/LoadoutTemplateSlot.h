#pragma once
#include "CoreMinimal.h"
#include "LoadoutTemplateSlot.generated.h"

class ULoadoutTemplate;

USTRUCT(BlueprintType)
struct FLoadoutTemplateSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULoadoutTemplate* Template;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumRecords;
    
    REMNANT_API FLoadoutTemplateSlot();
};

