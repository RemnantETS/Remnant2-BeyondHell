#include "CharacterMovementComponentGunfire.h"
#include "Templates/SubclassOf.h"

void UCharacterMovementComponentGunfire::SetUseAccelerationForPaths(bool Enabled) {
}

void UCharacterMovementComponentGunfire::SetSwingConstraint(bool Enabled, const FVector& SwingPoint, float RopeLength) {
}

void UCharacterMovementComponentGunfire::SetNavigationType(ENavigationType NavigationType) {
}

void UCharacterMovementComponentGunfire::SetCanSwim(bool bInCanSwim) {
}

void UCharacterMovementComponentGunfire::MarkCharacterTeleported() {
}

bool UCharacterMovementComponentGunfire::Is3DNavigating() const {
    return false;
}

AActor* UCharacterMovementComponentGunfire::GetWaterBoundsActor(bool bConstrainToFluidFilled) const {
    return NULL;
}

APhysicsBounds* UCharacterMovementComponentGunfire::GetWaterBounds(bool bConstrainToFluidFilled) const {
    return NULL;
}

AActor* UCharacterMovementComponentGunfire::GetPhysicsBoundsActor() const {
    return NULL;
}

APhysicsBounds* UCharacterMovementComponentGunfire::GetPhysicsBounds() const {
    return NULL;
}

ENavigationType UCharacterMovementComponentGunfire::GetNavigationType() const {
    return ENavigationType::Unknown;
}

FString UCharacterMovementComponentGunfire::GetDebugInfo(int32 DebugLevel) const {
    return TEXT("");
}

TSubclassOf<UPhysicsBoundsType> UCharacterMovementComponentGunfire::GetCurrentWaterBoundsType(bool bConstrainToFluidFilled) const {
    return NULL;
}

TSubclassOf<UPhysicsBoundsType> UCharacterMovementComponentGunfire::GetCurrentPhysicsBoundsType() const {
    return NULL;
}

bool UCharacterMovementComponentGunfire::CanRecieveSoftCharacterCollision() const {
    return false;
}

bool UCharacterMovementComponentGunfire::CanDoSoftCharacterCollision() const {
    return false;
}

void UCharacterMovementComponentGunfire::AddExternalVelocity(FVector ExternalVelocityIn) {
}

UCharacterMovementComponentGunfire::UCharacterMovementComponentGunfire() {
    this->MaxSpeedBackwards = -1.00f;
    this->BackwardStartAngle = 0.00f;
    this->bAllowVerticalInputAcceleration = true;
    this->EnableMovement = true;
    this->bIgnoreZFrictionAndBrakingWhenFlying = false;
    this->bUpdateRotationPostCameraUpdate = false;
    this->bUsingProjectedLocation = false;
    this->DoSoftCharacterCollision = false;
    this->SoftCollisionMode = ESoftCollisionMode::Disabled;
    this->SoftCharacterCollisionWeight = 10.00f;
    this->SoftCharacterCollisionRadius = -1.00f;
    this->SoftCharacterIgnore = NULL;
    this->DoSpecialCharacterCollision = false;
    this->SpecialCharacterCollisionIterations = 10;
    this->SpecialCharacterCollisionAlpha = 0.25f;
    this->TurnSmoothTime = 0.00f;
    this->CrouchedRadius = 40.00f;
    this->ConstrainToNavMesh = false;
    this->PerchSimpleRadius = 5.00f;
    this->bPerchFallingRadiusChange = false;
    this->PerchFallingRadius = 5.00f;
    this->PerchFallingThreshold = -300.00f;
    this->bDeferPerchUntilOnPlatform = false;
    this->PerchShowDebug = false;
    this->KnockBackImpulseScale = 1.00f;
    this->KnockUpImpulseScale = 1.00f;
    this->WallSlideDampenThresholdDeg = 0.00f;
    this->WallSlideDampenMulti = 0.60f;
    this->LedgeConstraintParams = NULL;
    this->bUseLeastSquaresForLedgeConstraint = true;
    this->DesiredCapsuleScaleFromLedge = 1.10f;
    this->LedgeSamples = 4;
    this->LedgeSamplesDistance = 25.00f;
    this->LedgeSampleIterations = 3;
    this->MaxLedgeForwardTestDistance = 100.00f;
    this->CliffCheckMaxAngle = 60.00f;
    this->ClickCheckAngleIterations = 1;
    this->RequiredSamplesForEdge = 5;
    this->LedgePushForce = 20.00f;
    this->bAllowFallingIfAlreadyOffLedge = true;
    this->StopCosineThreshold = 0.60f;
    this->ForceConstrainToGroundConditions = NULL;
    this->NavMeshProjectionHeightOffset = 0.00f;
    this->bProjectUsingClosestHitToNav = false;
    this->IdealDistanceToNav = 100.00f;
    this->NavProjectionCapsuleRadiusScale = 0.50f;
    this->AcceptanceRadiusScale = 1.10f;
    this->AcceptanceHeightScale = 1.05f;
    this->DefaultNavigationType = ENavigationType::Ground;
    this->FullTurnSpeedVelocity = 1500.00f;
    this->VelocityTurnSpeedThreshold = 0.10f;
    this->bAutoSetSwimmingMode = true;
    this->bStartWithSwimmingDisabled = false;
}

