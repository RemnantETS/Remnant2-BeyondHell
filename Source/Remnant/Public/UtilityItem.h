#pragma once
#include "CoreMinimal.h"
#include "UseableItem.h"
#include "UtilityItem.generated.h"

UCLASS(Blueprintable)
class REMNANT_API AUtilityItem : public AUseableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownTime;
    
    AUtilityItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UseCharge();
    
    UFUNCTION(BlueprintCallable)
    void Recharge();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetCharges();
    
};

