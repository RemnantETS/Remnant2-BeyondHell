#include "RemnantCharacter.h"
#include "ActorCustomizationComponent.h"
#include "EmotesComponent.h"
#include "Net/UnrealNetwork.h"
#include "RemnantPlayerInventoryComponent.h"

void ARemnantCharacter::UpdatePlayerInfoTags() {
}

void ARemnantCharacter::UpdatePersistentBuffs() {
}

void ARemnantCharacter::TeleportToSpawnPoint(AActor* SpawnPoint) {
}

void ARemnantCharacter::SetSpawnPoint(ASpawnPoint* SpawnPoint) {
}

void ARemnantCharacter::SetHelmetShown(bool bShow) {
}

void ARemnantCharacter::SetGrabbedCheckpoint(ACheckpoint* NewCheckpoint) {
}

void ARemnantCharacter::SetDeactivated() {
}

void ARemnantCharacter::ServerSetHelmetShown_Implementation(bool bShow) {
}
bool ARemnantCharacter::ServerSetHelmetShown_Validate(bool bShow) {
    return true;
}

void ARemnantCharacter::ResetAmmoInClip() {
}

int32 ARemnantCharacter::RequestPowerLevel() const {
    return 0;
}

int32 ARemnantCharacter::RequestArchetypeLevel() const {
    return 0;
}

void ARemnantCharacter::RemovePersistentBuff(const UActionBuff* Buff) {
}

void ARemnantCharacter::RemoveAggroProxyCharacter(ACharacterGunfire* Character) {
}

void ARemnantCharacter::OnShowHelmetOptionChanged(UUserSetting* AppliedSetting, UGameUserSettingsGunfire* UserSettings) {
}


void ARemnantCharacter::OnRep_ShowHelmet() {
}

void ARemnantCharacter::OnRep_GrabbedCheckpoint(ACheckpoint* Previous) {
}

void ARemnantCharacter::OnRep_Deactivated() {
}

void ARemnantCharacter::OnCharacterDied(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}


bool ARemnantCharacter::IsReviving() const {
    return false;
}

bool ARemnantCharacter::IsDead() const {
    return false;
}

void ARemnantCharacter::InitializePersistentBuffs() {
}


float ARemnantCharacter::GetHealthClampMod() const {
    return 0.0f;
}

ARangedWeapon* ARemnantCharacter::GetCurrentRangedWeapon() const {
    return NULL;
}

USavedCharacter* ARemnantCharacter::GetCharacterInfo() {
    return NULL;
}

int32 ARemnantCharacter::GetAge() const {
    return 0;
}

int32 ARemnantCharacter::ComputePowerLevel_Implementation() const {
    return 0;
}

int32 ARemnantCharacter::ComputeOffenseLevel() const {
    return 0;
}

int32 ARemnantCharacter::ComputeItemLevel_Implementation() const {
    return 0;
}

int32 ARemnantCharacter::ComputeEquipmentLevel(FName Tag, int32 HighestItemLevelWeight) const {
    return 0;
}

int32 ARemnantCharacter::ComputeDefenseLevel() const {
    return 0;
}

int32 ARemnantCharacter::ComputeArchetypeLevel() const {
    return 0;
}

void ARemnantCharacter::ClientTeleportToSpawnPoint_Implementation(ASpawnPoint* SpawnPoint) {
}

void ARemnantCharacter::ClientTeleport_Implementation(FTransform Transform) {
}

void ARemnantCharacter::ClientSetSpawnPoint_Implementation(const FPersistenceKey& SpawnPointID) {
}

void ARemnantCharacter::ClientRemoveAllPings_Implementation() {
}

void ARemnantCharacter::BroadcastAimEvent(bool Aiming) {
}

void ARemnantCharacter::AddOrUpdatePersistentBuff(const UActionBuff* Buff) {
}

void ARemnantCharacter::AddAggroProxyCharacter(ACharacterGunfire* Character) {
}

void ARemnantCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantCharacter, Gender);
    DOREPLIFETIME(ARemnantCharacter, bHasAggro);
    DOREPLIFETIME(ARemnantCharacter, bHasCloseAggro);
    DOREPLIFETIME(ARemnantCharacter, ControllerIndex);
    DOREPLIFETIME(ARemnantCharacter, ShowHelmet);
    DOREPLIFETIME(ARemnantCharacter, GrabbedCheckpoint);
    DOREPLIFETIME(ARemnantCharacter, bDeactivated);
}

ARemnantCharacter::ARemnantCharacter() {
    this->Customization = CreateDefaultSubobject<UActorCustomizationComponent>(TEXT("VisualComp"));
    this->Inventory = CreateDefaultSubobject<URemnantPlayerInventoryComponent>(TEXT("Inventory"));
    this->Emotes = CreateDefaultSubobject<UEmotesComponent>(TEXT("Emotes"));
    this->FemaleAnimInstanceClass = NULL;
    this->FemaleSkeletalMesh = NULL;
    this->FemaleCustomizationSet = NULL;
    this->Gender = EGender::Female;
    this->bHasAggro = false;
    this->bHasCloseAggro = false;
    this->ControllerIndex = -1;
    this->LastUsedItemId = -1;
    this->ShowHelmet = true;
    this->HelmetSlot = TEXT("Helmet");
    this->ShowHelmetOption = TEXT("ShowHelmet");
    this->GrabbedCheckpoint = NULL;
    this->PrimaryWeaponType = NULL;
    this->ObstructedAdditionalDistance = 10.00f;
    this->ObstructedAdditionalRadius = 0.50f;
    this->bDeactivated = false;
    this->bOnlyExitDialogFromHostileDamage = true;
    this->bManualIgnoreDamageExitingDialog = false;
}

