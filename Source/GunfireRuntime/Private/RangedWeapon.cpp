#include "RangedWeapon.h"
#include "AimingComponent.h"
#include "Templates/SubclassOf.h"

ARangedWeapon::ARangedWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FireWhileAimingOnly = true;
    this->AllowActionOnFlinch = false;
    this->AmmoType = NULL;
    this->bUnlimitedAmmoForAICharacters = true;
    this->FireInputAction = NULL;
    this->ReloadInputAction = NULL;
    this->ReloadOnRelease = false;
    this->AllowAutoReload = true;
    this->AimInputAction = NULL;
    this->bRequireTagForAiming = false;
    this->ScopeInputAction = NULL;
    this->DoubleClickScopeInputAction = NULL;
    this->MinimumAimTime = 0.00f;
    this->FireInputBufferDuration = 0.20f;
    this->bUseCameraWhenAimingWithScope = false;
    this->AimScopeInputAction = NULL;
    this->WeaponDoesHitScanOnFire = true;
    this->AimTag = TEXT("Aim");
    this->bRequiresInHandToUse = true;
    this->ReloadStartTime = 0.00f;
    this->ReloadLoopTime = 0.00f;
    this->ReloadEndTime = 0.00f;
    this->ReloadTime = 0.50f;
    this->ReloadSpeed = 1.00f;
    this->AttachMuzzleFX = true;
    this->UseLowAmmoSounds = false;
    this->LowAmmoCount = 0;
    this->BulletWhizByRadius = 150.00f;
    this->RightOrientationAttachment = TEXT("Gun_Attach");
    this->LeftOrientationAttachment = TEXT("Gun_Attach_Left");
    this->UseAltOrientAttachOnReload = false;
    this->AmmoPoolComponent = NULL;
    this->Muzzle = NULL;
    this->AimingComponent = CreateDefaultSubobject<UAimingComponent>(TEXT("AimingComponent"));
}

void ARangedWeapon::TriggerSoundAwareness(float Radius) {
}

void ARangedWeapon::ToggleScopeInput(bool bRequiresAimInput) {
}

void ARangedWeapon::SetProjectileToVisualize(TSubclassOf<AActor> NewProjectileClass) {
}

void ARangedWeapon::SetOverrideWeaponMode(const FRangedWeaponMode& Mode) {
}

void ARangedWeapon::SetCustomUserState(bool InCustomUserState) {
}

void ARangedWeapon::SetCustomUserSecondaryState(bool InCustomUserSecondaryState) {
}

void ARangedWeapon::SetClipAmount(int32 Amount) {
}

void ARangedWeapon::ServerSetState_Implementation(uint8 InState) {
}
bool ARangedWeapon::ServerSetState_Validate(uint8 InState) {
    return true;
}

void ARangedWeapon::ServerFireWithWindup_Implementation(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, float ClientWindupTime) {
}
bool ARangedWeapon::ServerFireWithWindup_Validate(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, float ClientWindupTime) {
    return true;
}

void ARangedWeapon::ServerFireWithCameraTransform_Implementation(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation) {
}
bool ARangedWeapon::ServerFireWithCameraTransform_Validate(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation) {
    return true;
}

void ARangedWeapon::ServerFireWithAllData_Implementation(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation, float ClientWindupTime) {
}
bool ARangedWeapon::ServerFireWithAllData_Validate(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation, float ClientWindupTime) {
    return true;
}

void ARangedWeapon::ServerFireCustomReloadNotifications_Implementation() {
}
bool ARangedWeapon::ServerFireCustomReloadNotifications_Validate() {
    return true;
}

void ARangedWeapon::ServerFire_Implementation(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed) {
}
bool ARangedWeapon::ServerFire_Validate(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed) {
    return true;
}

void ARangedWeapon::RemoveAmmoFromClip(int32 Ammo) {
}

void ARangedWeapon::Reload() {
}

void ARangedWeapon::PlayMuzzleFX(UNiagaraSystem* WeaponMuzzleFX, bool Attach) {
}

void ARangedWeapon::PlayFireAnimation(FName AnimationID) {
}

void ARangedWeapon::OnWindupOverdrawBegin_Implementation() {
}

void ARangedWeapon::OnWindupFull_Implementation() {
}

void ARangedWeapon::OnWindupEnd_Implementation() {
}

void ARangedWeapon::OnWindupBegin_Implementation() {
}


void ARangedWeapon::OnScopeInputPressed() {
}


void ARangedWeapon::OnPreFireEnd_Implementation() {
}

void ARangedWeapon::OnPreFireBegin_Implementation() {
}

void ARangedWeapon::OnIdle_Implementation() {
}

void ARangedWeapon::OnFireEnd_Implementation() {
}

void ARangedWeapon::OnFireBegin_Implementation() {
}

void ARangedWeapon::OnFire_Implementation(const FVector& From, const FVector& To, float WeaponSpread) {
}




void ARangedWeapon::OnEquipEnd_Implementation() {
}

void ARangedWeapon::OnEquipBegin_Implementation() {
}



void ARangedWeapon::OnDoubleClickScopeInputReleased() {
}

void ARangedWeapon::OnDoubleClickScopeInputPressed() {
}


void ARangedWeapon::MulticastSetStateNS_Implementation(uint8 InState) {
}

void ARangedWeapon::MulticastSetState_Implementation(uint8 InState) {
}

void ARangedWeapon::MulticastFire_Implementation(FVector_NetQuantize From, const FReplicatedLocation& To, float WeaponSpread, uint32 RandomSeed) {
}



bool ARangedWeapon::IsWindupOverdrawn() const {
    return false;
}

bool ARangedWeapon::IsWindingUp() const {
    return false;
}

bool ARangedWeapon::IsUsingToggleAimInput() const {
    return false;
}

bool ARangedWeapon::IsScopeInputEnabled() const {
    return false;
}

bool ARangedWeapon::IsReloading() const {
    return false;
}

bool ARangedWeapon::IsInCustomUserState() const {
    return false;
}

bool ARangedWeapon::IsInCustomUserSecondaryState() const {
    return false;
}

bool ARangedWeapon::IsFiring() const {
    return false;
}

bool ARangedWeapon::IsBusy() const {
    return false;
}

bool ARangedWeapon::IsAimInputDown() const {
    return false;
}

bool ARangedWeapon::IsAimingWithScope() const {
    return false;
}

bool ARangedWeapon::IsAiming() const {
    return false;
}

void ARangedWeapon::InitializeWeaponMode(FRangedWeaponMode& InWeaponMode, AActor* InterfaceObject) {
}

bool ARangedWeapon::HasScope() const {
    return false;
}

bool ARangedWeapon::HasInfiniteReserve() const {
    return false;
}

bool ARangedWeapon::HasInfiniteClip() const {
    return false;
}

float ARangedWeapon::GetWindupTime_Implementation() const {
    return 0.0f;
}

float ARangedWeapon::GetWindupRate() const {
    return 0.0f;
}

float ARangedWeapon::GetWindupProgress_Implementation() const {
    return 0.0f;
}

float ARangedWeapon::GetWindupOverdrawProgress_Implementation() const {
    return 0.0f;
}

FRangedWeaponMode ARangedWeapon::GetWeaponMode() const {
    return FRangedWeaponMode{};
}

float ARangedWeapon::GetTotalWindup() const {
    return 0.0f;
}

float ARangedWeapon::GetTotalFireLength(FName AnimationID, int32& SeedOut) {
    return 0.0f;
}

FString ARangedWeapon::GetStateName() const {
    return TEXT("");
}

uint8 ARangedWeapon::GetState() const {
    return 0;
}

int32 ARangedWeapon::GetSprayCount() const {
    return 0;
}

float ARangedWeapon::GetScopeFOV() const {
    return 0.0f;
}

float ARangedWeapon::GetRateOfFire() const {
    return 0.0f;
}

float ARangedWeapon::GetRange(bool bIncludeFalloff) const {
    return 0.0f;
}

FRandomStream ARangedWeapon::GetRandomStream() {
    return FRandomStream{};
}

FProjectileVisualizationContext ARangedWeapon::GetProjectileVisualization() const {
    return FProjectileVisualizationContext{};
}

float ARangedWeapon::GetOverdrawTime() const {
    return 0.0f;
}

float ARangedWeapon::GetNormalizedSpread() {
    return 0.0f;
}

FHitResult ARangedWeapon::GetMuzzleObstruction() const {
    return FHitResult{};
}

void ARangedWeapon::GetMuzzleFXPointAndDirection(FVector& MuzzlePoint, FVector& MuzzleDirection, int32 SprayIndex) {
}

int32 ARangedWeapon::GetMaxAmmo() const {
    return 0;
}

FHitResult ARangedWeapon::GetFirstNonPiercedAimTarget(bool bInitialSegmentOnly) const {
    return FHitResult{};
}

float ARangedWeapon::GetFalloff(bool bPrimaryFalloffOnly) const {
    return 0.0f;
}

float ARangedWeapon::GetDamageScalar(float Distance) const {
    return 0.0f;
}

float ARangedWeapon::GetCurrentSpread() {
    return 0.0f;
}

float ARangedWeapon::GetBurstRateOfFire() const {
    return 0.0f;
}

int32 ARangedWeapon::GetBurstCount() const {
    return 0;
}

FSoundGunfire ARangedWeapon::GetBulletWhizBySound_Implementation() const {
    return FSoundGunfire{};
}

int32 ARangedWeapon::GetAmmoPerReload() const {
    return 0;
}

int32 ARangedWeapon::GetAmmoPerClip() const {
    return 0;
}

int32 ARangedWeapon::GetAmmoInClip() const {
    return 0;
}

int32 ARangedWeapon::GetAmmo() const {
    return 0;
}

void ARangedWeapon::GetAimVector(FVector& From, FVector& To, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride) {
}

FVector ARangedWeapon::GetAimTargetLocation() {
    return FVector{};
}

FHitResult ARangedWeapon::GetAimTarget(bool bInitialSegmentOnly) const {
    return FHitResult{};
}

FWeaponTracePath ARangedWeapon::GetAimPath() const {
    return FWeaponTracePath{};
}

UAimingComponent* ARangedWeapon::GetAimingComponent() const {
    return NULL;
}

void ARangedWeapon::ForceReload(bool FireReloadNotifications) {
}

void ARangedWeapon::ForceIdle() {
}

void ARangedWeapon::ForceFullReload_Implementation() {
}

AActor* ARangedWeapon::FireProjectile(AActor* Cause, const FVector& Origin, const FVector& End, float WeaponSpread, TSubclassOf<AActor> ProjectileBP, float Velocity) {
    return NULL;
}

void ARangedWeapon::FinishEquip() {
}

void ARangedWeapon::FillClip(int32 Amount) {
}

void ARangedWeapon::EndUse() {
}

void ARangedWeapon::DoInstantHit(const FVector& Origin, const FVector& End, float WeaponSpread) {
}

void ARangedWeapon::DoImpact(const FHitResult& Hit) {
}

bool ARangedWeapon::DoCustomReload_Implementation(bool& FireReloadNotifications) {
    return false;
}

void ARangedWeapon::ConsumeAmmo(int32 Amount) {
}

void ARangedWeapon::ClearOverrideWeaponMode() {
}

void ARangedWeapon::ClearDoubleClickTimer() {
}

bool ARangedWeapon::CanWindup(float& PercentComplete) const {
    return false;
}

bool ARangedWeapon::CanUse() const {
    return false;
}

bool ARangedWeapon::CanReload() const {
    return false;
}

bool ARangedWeapon::CanFireEndAnimation_Implementation() const {
    return false;
}

bool ARangedWeapon::CanFire() const {
    return false;
}

void ARangedWeapon::CancelWindup() {
}

void ARangedWeapon::CancelReload() {
}

bool ARangedWeapon::CanAutoReload() const {
    return false;
}

void ARangedWeapon::BeginUse() {
}

void ARangedWeapon::BeginReload() {
}

void ARangedWeapon::ApplySpread(float Scalar) {
}

void ARangedWeapon::ApplyRecoil_Implementation(float Scalar) {
}

void ARangedWeapon::AddAmmoToClip(int32 Ammo, bool bIsReload) {
}

void ARangedWeapon::AddAmmo(int32 Amount, bool NewFillClip) {
}


