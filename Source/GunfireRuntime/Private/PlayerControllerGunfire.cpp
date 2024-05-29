#include "PlayerControllerGunfire.h"
#include "DamageValidationComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlayStateComponent.h"

void APlayerControllerGunfire::SpectateTarget(AActor* Actor) {
}

void APlayerControllerGunfire::SpectatePrevPlayer() {
}

void APlayerControllerGunfire::SpectateNextPlayer() {
}

void APlayerControllerGunfire::SetGameInputEnabled(bool bEnabled, const bool bFlushInput) {
}

void APlayerControllerGunfire::SetAdditionalNetRelevanceTarget_Implementation(bool bAdd, AActor* Actor, FRotator Rot) {
}
bool APlayerControllerGunfire::SetAdditionalNetRelevanceTarget_Validate(bool bAdd, AActor* Actor, FRotator Rot) {
    return true;
}

void APlayerControllerGunfire::ServerUpdateEntitlement_Implementation(int32 PlayerId, const FSoftObjectPath& Entitlement, bool Grant) {
}
bool APlayerControllerGunfire::ServerUpdateEntitlement_Validate(int32 PlayerId, const FSoftObjectPath& Entitlement, bool Grant) {
    return true;
}

void APlayerControllerGunfire::ServerUnlockAllTraitsOfType_Implementation(const FString& NameOfBP, int32 StartingLevel) {
}
bool APlayerControllerGunfire::ServerUnlockAllTraitsOfType_Validate(const FString& NameOfBP, int32 StartingLevel) {
    return true;
}

void APlayerControllerGunfire::ServerSpectateTarget_Implementation(AActor* Actor) {
}
bool APlayerControllerGunfire::ServerSpectateTarget_Validate(AActor* Actor) {
    return true;
}

void APlayerControllerGunfire::ServerSpawnCharacter_Implementation(UClass* ClassToSpawn, FTransform SpawnTransform, AActor* SpawnOwner) {
}
bool APlayerControllerGunfire::ServerSpawnCharacter_Validate(UClass* ClassToSpawn, FTransform SpawnTransform, AActor* SpawnOwner) {
    return true;
}

void APlayerControllerGunfire::ServerSetPlayerNormalizedHealth_Implementation(float Health) {
}
bool APlayerControllerGunfire::ServerSetPlayerNormalizedHealth_Validate(float Health) {
    return true;
}

void APlayerControllerGunfire::ServerRequestTime_Implementation(uint16 ClientTime) {
}
bool APlayerControllerGunfire::ServerRequestTime_Validate(uint16 ClientTime) {
    return true;
}

void APlayerControllerGunfire::ServerRemoveTrait_Implementation(const FString& NameOfBP) {
}
bool APlayerControllerGunfire::ServerRemoveTrait_Validate(const FString& NameOfBP) {
    return true;
}

void APlayerControllerGunfire::ServerDropItem_Implementation(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
}
bool APlayerControllerGunfire::ServerDropItem_Validate(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
    return true;
}

void APlayerControllerGunfire::ServerDoConsoleCommand_Implementation(const FString& Command) {
}
bool APlayerControllerGunfire::ServerDoConsoleCommand_Validate(const FString& Command) {
    return true;
}

void APlayerControllerGunfire::ServerDoAction_Implementation(const FString& NameOfBP, bool bApplyToTarget) {
}
bool APlayerControllerGunfire::ServerDoAction_Validate(const FString& NameOfBP, bool bApplyToTarget) {
    return true;
}

void APlayerControllerGunfire::ServerBeginSpectate_Implementation() {
}
bool APlayerControllerGunfire::ServerBeginSpectate_Validate() {
    return true;
}

void APlayerControllerGunfire::ServerAddTrait_Implementation(const FString& NameOfBP, int32 Level) {
}
bool APlayerControllerGunfire::ServerAddTrait_Validate(const FString& NameOfBP, int32 Level) {
    return true;
}

void APlayerControllerGunfire::RestoreSpectateViewTarget() {
}

bool APlayerControllerGunfire::RestartPlayer_Implementation() {
    return false;
}

void APlayerControllerGunfire::ResetPauseRefCount() {
}

void APlayerControllerGunfire::RemoveCinematicListener(const FCinematicDelegate& Event) {
}

void APlayerControllerGunfire::QuitGame() {
}

void APlayerControllerGunfire::ProposeToSkipCutscene_Implementation(UObject* InSequence) {
}
bool APlayerControllerGunfire::ProposeToSkipCutscene_Validate(UObject* InSequence) {
    return true;
}

void APlayerControllerGunfire::OnRep_SpectateTarget() {
}


bool APlayerControllerGunfire::IsSynchronizingData() const {
    return false;
}

bool APlayerControllerGunfire::IsSpectating() const {
    return false;
}

bool APlayerControllerGunfire::IsJoiningAsSpectator() const {
    return false;
}

bool APlayerControllerGunfire::IsJoiningAsPlayer() const {
    return false;
}

bool APlayerControllerGunfire::IsJoining() const {
    return false;
}

bool APlayerControllerGunfire::IsInCinematic() const {
    return false;
}

bool APlayerControllerGunfire::IsGameInputEnabled() const {
    return false;
}

bool APlayerControllerGunfire::IsFlaggedAsSpectator() const {
    return false;
}

bool APlayerControllerGunfire::IsDisconnected() const {
    return false;
}

bool APlayerControllerGunfire::HasLicense(const FString& License) {
    return false;
}

bool APlayerControllerGunfire::HasJoined() const {
    return false;
}

AActor* APlayerControllerGunfire::GetSpectateTarget() {
    return NULL;
}

APawn* APlayerControllerGunfire::GetRelevantViewTarget() {
    return NULL;
}

APawn* APlayerControllerGunfire::GetRelevantPawn() {
    return NULL;
}

FString APlayerControllerGunfire::GetPlayerIdentifier() const {
    return TEXT("");
}

int32 APlayerControllerGunfire::GetNumPotentialSpectateTargets() {
    return 0;
}

EPlayerJoinState APlayerControllerGunfire::GetJoinState() const {
    return EPlayerJoinState::Disconnected;
}

APlayerStateGunfire* APlayerControllerGunfire::GetGunfirePlayerState() const {
    return NULL;
}

void APlayerControllerGunfire::ClientTimeReply_Implementation(uint16 ServerTime, uint16 ClientTime) {
}

bool APlayerControllerGunfire::CanSpectate() const {
    return false;
}

void APlayerControllerGunfire::BeginSpectate() {
}

void APlayerControllerGunfire::BeginPlaying() {
}

void APlayerControllerGunfire::AddCinematicListener(const FCinematicDelegate& Event) {
}

void APlayerControllerGunfire::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APlayerControllerGunfire, SpectateActor);
}

APlayerControllerGunfire::APlayerControllerGunfire() {
    this->InputMappingContext = NULL;
    this->RuntimeManagedMappingContext = NULL;
    this->SpectateActor = NULL;
    this->PlayState = CreateDefaultSubobject<UPlayStateComponent>(TEXT("PlayState"));
    this->DamageValidationComponent = CreateDefaultSubobject<UDamageValidationComponent>(TEXT("DamageValidationComponent"));
}

