#pragma once
#include "CoreMinimal.h"
#include "ClientEvadeRecord.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FClientEvadeRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* Source;
    
    GUNFIRERUNTIME_API FClientEvadeRecord();
};

