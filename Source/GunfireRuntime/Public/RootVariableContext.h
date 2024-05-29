#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RootVariableContext.generated.h"

class UConditionalVariables;
class UObject;
class URootVariableContext;
class UVariableComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API URootVariableContext : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UConditionalVariables*> SourceConditions;
    
public:
    URootVariableContext();
    UFUNCTION(BlueprintCallable)
    void UnregisterContext(FName Name, UVariableComponent* Variables);
    
    UFUNCTION(BlueprintCallable)
    void RegisterContext(FName Name, UVariableComponent* Variables);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void K2_GetContextVariables(FName Name, TArray<UVariableComponent*>& VariablesOut) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URootVariableContext* GetInstance(const UObject* WorldContextObject, bool bCreateIfMissing);
    
};

