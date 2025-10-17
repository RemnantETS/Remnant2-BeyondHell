#pragma once
#include "CoreMinimal.h"
#include "SpawnTableEntry.h"
#include "Templates/SubclassOf.h"
#include "SpawnTableTrait.generated.h"

class UTrait;

UCLASS(EditInlineNew)
class REMNANT_API USpawnTableTrait : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrait> TraitBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UTrait> TraitClass;

    USpawnTableTrait();
};

