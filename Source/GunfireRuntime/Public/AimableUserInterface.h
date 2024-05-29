#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AimableUserInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UAimableUserInterface : public UInterface {
    GENERATED_BODY()
};

class IAimableUserInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyReticule(AActor* Aimable, UPARAM(Ref) bool& IsAimableDisabled, UPARAM(Ref) bool& ShowDefaultReticule, UPARAM(Ref) bool& ShowDisabledColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyAimInputDown(const AActor* Aimable, UPARAM(Ref) bool& IsAimInputDown, UPARAM(Ref) bool& IsToggleAim) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* ModifyAimable(AActor* Aimable) const;
    
};

