#pragma once
#include "CoreMinimal.h"
#include "ChallengeEvent.h"
#include "SpawnTableEntry.h"
#include "SpawnTableChallenge.generated.h"

UCLASS(EditInlineNew)
class REMNANT_API USpawnTableChallenge : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChallengeEvent Challenge;
    
    USpawnTableChallenge();
};

