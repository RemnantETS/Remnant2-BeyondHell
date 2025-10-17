#pragma once
#include "CoreMinimal.h"
#include "SpawnTableEntry.h"
#include "SpawnTableExperience.generated.h"

UCLASS(EditInlineNew)
class REMNANT_API USpawnTableExperience : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExperienceMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExperienceMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExperienceIncPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExperienceExpPerLevel;
    
    USpawnTableExperience();
};

