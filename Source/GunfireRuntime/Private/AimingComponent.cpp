#include "AimingComponent.h"

bool UAimingComponent::UsesProjectileVisualization() const {
    return false;
}

void UAimingComponent::SetAimingParametersOverride(const FAimingParameters& NewParameters) {
}

void UAimingComponent::Reset() {
}

FProjectileVisualizationContext UAimingComponent::GetProjectileVisualization() const {
    return FProjectileVisualizationContext{};
}

FHitResult UAimingComponent::GetMuzzleObstruction() {
    return FHitResult{};
}

FHitResult UAimingComponent::GetFirstNonPiercedAimTarget(bool bInitialSegmentOnly) const {
    return FHitResult{};
}

void UAimingComponent::GetAimVector(FVector& From, FVector& To, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride) {
}

FVector UAimingComponent::GetAimTargetLocation() {
    return FVector{};
}

FHitResult UAimingComponent::GetAimTarget(bool bInitialSegmentOnly) const {
    return FHitResult{};
}

FWeaponTracePath UAimingComponent::GetAimPath() const {
    return FWeaponTracePath{};
}

FAimingParameters UAimingComponent::GetAimingParameters() const {
    return FAimingParameters{};
}

void UAimingComponent::ClearAimingParametersOverride() {
}

UAimingComponent::UAimingComponent() {
    this->bAutoActivateWhileAiming = true;
}

