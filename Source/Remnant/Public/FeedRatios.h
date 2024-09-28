#pragma once
#include "CoreMinimal.h"
#include "FeedRatios.generated.h"

USTRUCT(BlueprintType)
struct FFeedRatios {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> StatNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float FeedRatio;
    
    REMNANT_API FFeedRatios();
};

