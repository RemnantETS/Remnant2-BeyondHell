#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InspectInfo.h"
#include "PrismSegmentDataObject.generated.h"

class AActor;

UCLASS(Blueprintable)
class REMNANT_API UPrismSegmentDataObject : public UObject {
    GENERATED_BODY()
public:
    UPrismSegmentDataObject();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostComputeStats(AActor* OwningCharacter, int32 ComputeLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnComputeStats(AActor* OwningCharacter, int32 ComputeLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyPrismInspectInfo(int32 InspectLevel, UPARAM(Ref) FInspectInfo& Info);
    
};

