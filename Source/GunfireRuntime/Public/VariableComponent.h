#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VariableContainer.h"
#include "VariableDef.h"
#include "VariableStatements.h"
#include "VariableValue.h"
#include "VariableComponent.generated.h"

class AActor;
class UVariables;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UVariableComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVariables* VariableDefinitions;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RegisterOwnerVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVariableDef> OwnerVariables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool DummyVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVariableContainer Variables;
    
public:
    UVariableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetVariableName(const FName& NameID, FName Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableInt(const FName& NameID, int32 Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableFloat(const FName& NameID, float Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableBool(const FName& NameID, bool Value, float Expiration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetVariableName(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetVariableInt(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVariableFloat(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVariableBool(const FName& NameID);
    
    UFUNCTION(BlueprintCallable)
    static void ExecuteStatements(AActor* ContextActor, const FVariableStatements& Statements);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EvaluateStatements(AActor* ContextActor, const FVariableStatements& Statements);
    
protected:
    UFUNCTION(Client, Reliable)
    void ClientSetVariable(int16 Index, const FVariableValue& NewValue);
    
};

