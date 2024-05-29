#include "ProjectileMovementComponentGunfire.h"

FVector UProjectileMovementComponentGunfire::SimulateBounce(FVector CurrentVelocity, const FHitResult& Hit, float& OutGravityScale) {
    return FVector{};
}

bool UProjectileMovementComponentGunfire::ShouldIgnoreNextPenetrate() const {
    return false;
}

void UProjectileMovementComponentGunfire::SetPenetrate(bool bShouldPenetrate) {
}

void UProjectileMovementComponentGunfire::SetMaintainCurrentRelativeRotation() {
}

void UProjectileMovementComponentGunfire::SetIgnoreNextPenetrate(bool bShouldIgnore) {
}

UProjectileMovementComponentGunfire::UProjectileMovementComponentGunfire() {
    this->Penetrate = false;
    this->ZeroPenetrationAdjustment = false;
    this->AntiPenetrateSpeed = 600.00f;
    this->bMaintainInitialRelativeRotation = false;
    this->bApplyPostBounceGravityScale = false;
    this->PostBounceGravityScale = 1.00f;
    this->BounceNormalAlignmentAlpha = 0.00f;
    this->NormalAlignmentUpwardsCosineThresh = 0.00f;
    this->UpwardsBounceNormalAlignmentAlpha = 0.00f;
    this->bApplyPostBounceVelocityClamp = false;
}

