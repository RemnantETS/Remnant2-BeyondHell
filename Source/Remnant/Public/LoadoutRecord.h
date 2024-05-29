#pragma once
#include "CoreMinimal.h"
#include "LoadoutRecordEntry.h"
#include "LoadoutRecord.generated.h"

class ULoadoutTemplate;

USTRUCT(BlueprintType)
struct FLoadoutRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ULoadoutTemplate* Template;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FLoadoutRecordEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    REMNANT_API FLoadoutRecord();
};

