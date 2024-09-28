#pragma once
#include "CoreMinimal.h"
#include "UseableItem.h"
#include "Templates/SubclassOf.h"
#include "DragonHeart.generated.h"

class AItem;
class UVitalityComponent;

UCLASS(Blueprintable)
class REMNANT_API ADragonHeart : public AUseableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> UpgradeItemBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DHPool;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVitalityComponent* DHPoolComponent;
    
public:
    ADragonHeart(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void VerifyQuantity();
    
    UFUNCTION(BlueprintCallable)
    void Regenerate();
    
    UFUNCTION(BlueprintCallable)
    void OnPoolValueChanged(UVitalityComponent* PoolComponent);
    
    UFUNCTION(BlueprintCallable)
    int32 GetMaxCurrentQuantity();
    
};

