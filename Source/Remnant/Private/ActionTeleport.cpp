#include "ActionTeleport.h"
#include "Net/UnrealNetwork.h"

void UActionTeleport::TryInitializeTeleport_Implementation() {
}

void UActionTeleport::TryFinalizeTeleport_Implementation() {
}

void UActionTeleport::ServerFinishTeleport_Implementation(FVector FinalLocation) {
}

void UActionTeleport::ServerBeginTeleport_Implementation(AActor* Target, FVector FinalLocation) {
}




void UActionTeleport::MulticastFinishTeleport_Implementation(FVector NewLocation) {
}

void UActionTeleport::MulticastBeginTeleport_Implementation(AActor* Target, FVector NewLocation) {
}

void UActionTeleport::ClearTeleportCamera() {
}

bool UActionTeleport::CanTeleport_Implementation() {
    return false;
}

void UActionTeleport::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActionTeleport, TargetLocation);
}

UActionTeleport::UActionTeleport() {
    this->TeleportDelay = 0.00f;
    this->TeleportDuration = 0.00f;
    this->ReappearDelay = 0.00f;
    this->bAutoHideActor = true;
    this->TeleportCamera = NULL;
    this->CameraBlendIn = -1.00f;
    this->CameraBlendOut = -1.00f;
    this->bFaceTarget = true;
    this->bMoveCameraOverTime = true;
    this->CameraSnapMaxPitch = 20.00f;
    this->ResetStateOnEnterTeleport = false;
    this->ElapsedTime = 0.00f;
    this->bTeleportInitialized = false;
    this->bTeleportFinalized = false;
}

