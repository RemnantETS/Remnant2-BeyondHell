#pragma once
#include "CoreMinimal.h"
#include "UseableItem.h"
#include "Flashlight.generated.h"

class AActor;
class UFlashlightLOSTaggingComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class REMNANT_API AFlashlight : public AUseableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool On;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlashThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeTimeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFlashlightLOSTaggingComponent* FlashLOSComp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* OverlapComponent;
    
public:
    AFlashlight(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerToggleFlashlight();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTurnedOn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTurnedOff();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndFlash();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginFlash();
    
    UFUNCTION(BlueprintCallable)
    bool LightEndOverlap(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void LightBeginOverlap(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ApplyChargeDelta(float Delta);
    
};

