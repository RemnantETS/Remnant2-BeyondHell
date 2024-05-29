#pragma once
#include "CoreMinimal.h"
#include "CompareOp.h"
#include "Conditions.h"
#include "InheritableObject.h"
#include "Condition.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UCondition : public UInheritableObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertCondition;
    
    UCondition();
    UFUNCTION(BlueprintCallable)
    static bool EvaluateConditions(AActor* Actor, const FConditions& Conditions);
    
    UFUNCTION(BlueprintCallable)
    static bool CompareValue(float Value1, float Value2, CompareOp Compare);
    
};

