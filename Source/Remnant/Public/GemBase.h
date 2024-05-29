#pragma once
#include "CoreMinimal.h"
#include "EquipmentMod.h"
#include "InspectInfo.h"
#include "GemBase.generated.h"

class AActor;

UCLASS(Blueprintable)
class REMNANT_API AGemBase : public AEquipmentMod {
    GENERATED_BODY()
public:
    AGemBase();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostComputePrismStats(AActor* OwningCharacter, int32 ComputeLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnComputePrismStats(AActor* OwningCharacter, int32 ComputeLevel, int32 PrismMaxLevelReference) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyPrismInspectInfo(int32 InspectLevel, UPARAM(Ref) FInspectInfo& Info, int32 PrismMaxLevelReference);
    
};

