#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EQuestMode.h"
#include "SpawnTableOverrideParams.generated.h"

class USpawnTable;

USTRUCT(BlueprintType)
struct REMNANT_API FSpawnTableOverrideParams : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USpawnTable> InitialTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USpawnTable> OverrideTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQuestMode OverrideMode;
    
    FSpawnTableOverrideParams();
};

