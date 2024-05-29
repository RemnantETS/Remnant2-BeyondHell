#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemVendorInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UItemVendorInterface : public UInterface {
    GENERATED_BODY()
};

class IItemVendorInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldOverrideVisibility(UClass* InItem);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnItemSold(UClass* InItem, int32 DeltaQuantity, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetVendorValueOverride(UClass* InItem, UPARAM(Ref) int32& OutValue);
    
};

