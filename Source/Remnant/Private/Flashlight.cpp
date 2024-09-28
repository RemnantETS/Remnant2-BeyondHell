#include "Flashlight.h"
#include "FlashlightLOSTaggingComponent.h"

AFlashlight::AFlashlight(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisableTickAfterUse = false;
    this->ValidationTags.AddDefaulted(1);
    this->On = false;
    this->FlashThreshold = 0.10f;
    this->ChargeTimeMin = 2.00f;
    this->FlashLOSComp = CreateDefaultSubobject<UFlashlightLOSTaggingComponent>(TEXT("FlashlightLOSTaggingComp"));
    this->OverlapComponent = NULL;
}

void AFlashlight::ServerToggleFlashlight_Implementation() {
}
bool AFlashlight::ServerToggleFlashlight_Validate() {
    return true;
}





bool AFlashlight::LightEndOverlap(AActor* Actor) {
    return false;
}

void AFlashlight::LightBeginOverlap(AActor* Actor) {
}

void AFlashlight::ApplyChargeDelta(float Delta) {
}


