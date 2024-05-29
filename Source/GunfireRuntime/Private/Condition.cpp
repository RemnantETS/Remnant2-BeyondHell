#include "Condition.h"

bool UCondition::EvaluateConditions(AActor* Actor, const FConditions& Conditions) {
    return false;
}

bool UCondition::CompareValue(float Value1, float Value2, CompareOp Compare) {
    return false;
}

UCondition::UCondition() {
    this->InvertCondition = false;
}

