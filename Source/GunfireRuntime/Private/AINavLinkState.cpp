#include "AINavLinkState.h"

UAINavLinkState::UAINavLinkState() {
    this->SnapStartPositionToGround = false;
    this->VaultSettings = NULL;
    this->OverrideAgentRadius = -1.00f;
    this->LerpTime = 0.20f;
    this->LerpEasesIn = true;
    this->LerpEaseExponent = 2.00f;
    this->StopMovementOnExit = true;
    this->bSnapToVaultGeometry = false;
    this->VaultType = EVaultType::VaultOver;
}

