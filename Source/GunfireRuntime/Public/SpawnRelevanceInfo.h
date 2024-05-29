#pragma once
#include "CoreMinimal.h"
#include "SpawnRelevanceRange.h"
#include "SpawnRelevanceInfo.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FSpawnRelevanceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnRelevanceRange DefaultSpawnRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnRelevanceRange VerticalSpawnRangeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseVerticalSpawnRangeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseNavigationDataForDistance;
    
    FSpawnRelevanceInfo();
};

