#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChallengeObjectiveProgress.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FChallengeObjectiveProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid ObjectiveID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Progress;
    
    FChallengeObjectiveProgress();
};

