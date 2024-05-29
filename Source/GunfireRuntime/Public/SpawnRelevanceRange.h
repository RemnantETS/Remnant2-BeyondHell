#pragma once
#include "CoreMinimal.h"
#include "SpawnRelevanceRange.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FSpawnRelevanceRange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPlayerRangeToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDeactivationRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnReactivationRange;
    
    FSpawnRelevanceRange();
};

