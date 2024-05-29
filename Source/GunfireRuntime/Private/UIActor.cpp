#include "UIActor.h"

void AUIActor::SetWidgetText(FName Widget, FText WidgetText) {
}

void AUIActor::RefreshDialogState_Implementation() {
}

void AUIActor::OnSoftEndDialog_Implementation(float Duration) {
}


void AUIActor::OnPushDialog_Implementation(AUIActor* Next) {
}

void AUIActor::OnPopDialog_Implementation(AUIActor* Prev) {
}

void AUIActor::OnEndDialog_Implementation() {
}


void AUIActor::OnBeginDialog_Implementation() {
}

void AUIActor::Focus() {
}

void AUIActor::CreateInstance_Implementation() {
}

AUIActor::AUIActor() {
    this->HUD = NULL;
    this->WidgetClass = NULL;
    this->WidgetInstance = NULL;
    this->bHideParent = true;
    this->ViewPortZ = 0;
    this->DistanceFromCamera = 350.00f;
    this->ZOffsetFromCamera = 0.00f;
    this->DialogLinger = 5.00f;
    this->bCaptureInput = true;
    this->bPassInputToPlayer = false;
    this->bAlwaysOnTop = false;
    this->bInvulnerable = false;
    this->bRemoveOnHidden = false;
    this->bRemoveWhenNotOnTop = false;
    this->bRemoveOnCinematic = false;
    this->bFixedCameraFoV = false;
}

