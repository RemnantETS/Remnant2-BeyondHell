#include "UIHud.h"
#include "Templates/SubclassOf.h"

void AUIHud::UnloadLargeIcons() {
}

void AUIHud::SoftEndDialog(FName Result, UObject* EndingDialogContext, float ForceKillTime) {
}

void AUIHud::SetVisibility(bool bVisible) {
}

AUIActor* AUIHud::SetDialog(TSubclassOf<AUIActor> DialogBP, EDialogLocation Location, FText Text, FText Caption) {
    return NULL;
}

void AUIHud::PushUIActor(const AUIActor* UIActor) {
}

AUIActor* AUIHud::PopUIActor(AUIActor* DialogToPop) {
    return NULL;
}



void AUIHud::OnHudEvent_Implementation(FName EventID, UObject* Context) {
}

void AUIHud::OnDialogEnd_Implementation(AUIActor* Dialog) {
}

void AUIHud::OnDialogBegin_Implementation(AUIActor* Dialog) {
}

void AUIHud::OnCinematicEvent(APlayerControllerGunfire* Player, bool bIsInCinematic) {
}

void AUIHud::LoadLargeIcons(FOnIconsLoaded OnIconsLoaded, FLatentActionInfo LatentInfo) {
}

bool AUIHud::IsVisible() const {
    return false;
}

bool AUIHud::IsExternalOverlayTakingInput() const {
    return false;
}

bool AUIHud::IsExternalOverlayActive() const {
    return false;
}

void AUIHud::InsertUIActor(const AUIActor* UIActor, int32 StackIndex) {
}

AUIActor* AUIHud::GetUIActorFromContextObject(UObject* DialogContext) {
    return NULL;
}

AUIActor* AUIHud::GetTopInputActor() {
    return NULL;
}

AUIActor* AUIHud::GetDialog(TSubclassOf<AUIActor> DialogBP, bool AllowChildClasses) const {
    return NULL;
}

AUIActor* AUIHud::GetCurrentDialog() {
    return NULL;
}

APawn* AUIHud::GetControllingPawn() {
    return NULL;
}

void AUIHud::EndDialog(FName Result, UObject* EndingDialogContext) {
}

void AUIHud::EndCurrentDialog(FName Result) {
}

void AUIHud::EndAllDialogs() {
}

AUIActor* AUIHud::BeginDialog(TSubclassOf<AUIActor> DialogBP, EDialogLocation Location, FText Text, FText Caption, EDialogBeginMethod Method) {
    return NULL;
}

void AUIHud::AddUIToActorStack(const AUIActor* UIActor) {
}

AUIHud::AUIHud() {
    this->DisablePlayerInput = true;
    this->bAutoHideUMGWidgetsOnHidden = true;
    this->bFixedCameraFoV = false;
    this->PlayerPawn = NULL;
}

