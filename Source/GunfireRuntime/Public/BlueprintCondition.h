#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "BlueprintCondition.generated.h"

class AActor;
class UStateMachineComponent;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UBlueprintCondition : public UCondition {
    GENERATED_BODY()
public:
    UBlueprintCondition();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TestCondition(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetConditionState(UStateMachineComponent* StateMachine, bool State) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetConditionState(UStateMachineComponent* StateMachine, bool& State) const;
    
};

