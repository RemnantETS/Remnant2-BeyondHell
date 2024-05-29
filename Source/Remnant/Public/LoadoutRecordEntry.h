#pragma once
#include "CoreMinimal.h"
#include "LoadoutRecordEntry.generated.h"

class ULoadoutSlot;

USTRUCT(BlueprintType)
struct FLoadoutRecordEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UObject> ItemClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ULoadoutSlot* Slot;
    
    REMNANT_API FLoadoutRecordEntry();
};

