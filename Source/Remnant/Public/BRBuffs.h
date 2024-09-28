#pragma once
#include "CoreMinimal.h"
#include "BRBuffs.generated.h"

USTRUCT(BlueprintType)
struct FBRBuffs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActionID;
    
    REMNANT_API FBRBuffs();
};

