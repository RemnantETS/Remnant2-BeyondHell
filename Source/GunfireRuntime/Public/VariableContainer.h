#pragma once
#include "CoreMinimal.h"
#include "VariableContainer.generated.h"

class UVariables;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FVariableContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UVariables* VariableDefinitions;
    
    FVariableContainer();
};

