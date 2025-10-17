#pragma once
#include "CoreMinimal.h"
#include "SpawnTableEntry.h"
#include "SpawnTableAccountAward.generated.h"

class UAccountAward;

UCLASS(EditInlineNew)
class REMNANT_API USpawnTableAccountAward : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAccountAward> Award;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHardcoreOnly;
    
    USpawnTableAccountAward();
};

