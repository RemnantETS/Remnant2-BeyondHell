#pragma once
#include "CoreMinimal.h"
#include "TimedEvent.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FTimedEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    FTimedEvent();
};

