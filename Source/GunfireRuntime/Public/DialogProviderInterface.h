#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EDialogType.h"
#include "DialogProviderInterface.generated.h"

class AActor;
class UDialogComponent;
class UEventTree;

UINTERFACE(Blueprintable)
class UDialogProviderInterface : public UInterface {
    GENERATED_BODY()
};

class IDialogProviderInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldUseProviderForDefaultTree();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupContextVariables(UDialogComponent* DialogComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UEventTree* QueryEventTree(UDialogComponent* DialogComponent, EDialogType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UEventTree* GetEventTree(AActor* Actor);
    
};

