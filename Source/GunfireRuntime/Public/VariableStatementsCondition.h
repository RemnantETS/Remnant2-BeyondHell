#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "VariableStatements.h"
#include "VariableStatementsCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UVariableStatementsCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVariableStatements Statements;
    
    UVariableStatementsCondition();
};

