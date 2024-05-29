#include "RootVariableContext.h"

void URootVariableContext::UnregisterContext(FName Name, UVariableComponent* Variables) {
}

void URootVariableContext::RegisterContext(FName Name, UVariableComponent* Variables) {
}

void URootVariableContext::K2_GetContextVariables(FName Name, TArray<UVariableComponent*>& VariablesOut) const {
}

URootVariableContext* URootVariableContext::GetInstance(const UObject* WorldContextObject, bool bCreateIfMissing) {
    return NULL;
}

URootVariableContext::URootVariableContext() {
}

