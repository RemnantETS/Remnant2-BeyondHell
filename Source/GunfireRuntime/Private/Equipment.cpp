#include "Equipment.h"
#include "Net/UnrealNetwork.h"
#include "StatsComponent.h"

bool AEquipment::ValidateEquip_Implementation(ACharacterGunfire* ToCharacter) {
    return false;
}

void AEquipment::Unequip() {
}

void AEquipment::SetInputEnabled(bool Enabled) {
}

void AEquipment::SetInHand(bool InHand) {
}

void AEquipment::SetAttachmentsVisible(bool Visible) {
}

void AEquipment::ServerSetInHand_Implementation(bool InHand) {
}
bool AEquipment::ServerSetInHand_Validate(bool InHand) {
    return true;
}

void AEquipment::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}


void AEquipment::PostComputeStats() {
}

void AEquipment::PostComputeCharacterStats_Implementation() {
}

float AEquipment::PlayAnimation(FName AnimationID, float PlayRate, bool bCharacterOnly, FName AnimLayerOverride, int32 Seed, float StartTimeOverride) {
    return 0.0f;
}



void AEquipment::OnSkeletalMeshAnimInitialized() {
}





void AEquipment::OnFinishLoadingAssets() {
}


void AEquipment::OnEquipmentAssetsLoaded_Implementation() {
}






void AEquipment::ModifyStat(FName Stat, float Value) {
}

bool AEquipment::IsLocallyControlled() const {
    return false;
}

bool AEquipment::IsInHand() const {
    return false;
}

bool AEquipment::IsEquipped() const {
    return false;
}

bool AEquipment::IsActive() const {
    return false;
}

bool AEquipment::IsActionAllowed() const {
    return false;
}

void AEquipment::InstanceDataChanged() {
}

bool AEquipment::HasEquipmentAnimationEntry(FName AnimationID, FName AnimLayerOverride) {
    return false;
}

float AEquipment::GetStat(FName Stat) {
    return 0.0f;
}

uint8 AEquipment::GetModSlotIndexByNameID(FName SlotNameID) {
    return 0;
}

FEquipmentModSlot AEquipment::GetModSlotByNameID(FName SlotNameID) {
    return FEquipmentModSlot{};
}

int32 AEquipment::GetItemID() {
    return 0;
}

UInventoryComponent* AEquipment::GetInventoryComponent() const {
    return NULL;
}

AUIHud* AEquipment::GetHud() const {
    return NULL;
}

int32 AEquipment::GetEquipmentSlotIdx() {
    return 0;
}

AEquipmentMod* AEquipment::GetEquipmentMod(uint8 Slot) {
    return NULL;
}

UClass* AEquipment::GetEquipmentAssetClass(FName AssetName) const {
    return NULL;
}

UObject* AEquipment::GetEquipmentAsset(FName AssetName) const {
    return NULL;
}

FName AEquipment::GetCurrentAnimation() const {
    return NAME_None;
}

ACharacterGunfire* AEquipment::GetCharacter() const {
    return NULL;
}

TArray<AEquipmentMod*> AEquipment::GetAttachedMods() {
    return TArray<AEquipmentMod*>();
}

void AEquipment::Detach() {
}

void AEquipment::Deactivate() {
}

void AEquipment::ComputeStats() {
}

void AEquipment::ComputeCharacterStats() {
}

bool AEquipment::AreAssetsLoaded() const {
    return false;
}

void AEquipment::Activate() {
}

void AEquipment::_NotifyTakeDamage(const FDamageInfo& DamageInfo) {
}

void AEquipment::_NotifyHitTarget(const FDamageInfo& DamageInfo) {
}

void AEquipment::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEquipment, CharacterReplicated);
    DOREPLIFETIME(AEquipment, bIsActiveReplicated);
    DOREPLIFETIME(AEquipment, bIsInHandReplicated);
}

AEquipment::AEquipment() {
    this->AnimationLayer = TEXT("UpperBody");
    this->AutoEnableInput = true;
    this->ShouldUnequip = true;
    this->UseEquipmentAnimTimings = false;
    this->FallbackToCharacterTimings = false;
    this->StopAnimsRegardlessOfTimingTarget = false;
    this->bSupportSlaveAnimations = false;
    this->StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComp"));
    this->Character = NULL;
    this->CharacterReplicated = NULL;
    this->CustomizationComponent = NULL;
    this->bIsActiveReplicated = false;
    this->bIsInHandReplicated = false;
}

