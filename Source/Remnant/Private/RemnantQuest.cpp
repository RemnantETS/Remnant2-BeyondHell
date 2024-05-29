#include "RemnantQuest.h"
#include "VariableComponent.h"
#include "PersistenceComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

bool ARemnantQuest::ShowQuestBreadcrumbs() {
    return false;
}

bool ARemnantQuest::ShouldBreadcrumbForName(FName Objective) {
    return false;
}

bool ARemnantQuest::ShouldBreadcrumb(FZoneLinkInfo ZoneLink) {
    return false;
}

void ARemnantQuest::SetRespawn_Implementation(const FZoneLinkInfo& Respawn) {
}

void ARemnantQuest::SetLastCheckpoint_Implementation(const FZoneLinkInfo& Checkpoint) {
}

void ARemnantQuest::OnRep_Status() {
}

void ARemnantQuest::OnRep_BreadcrumbInfo() {
}

void ARemnantQuest::MulticastUnloadContainerLevel_Implementation() {
}

void ARemnantQuest::MulticastSetCheckpoint_Implementation() {
}

bool ARemnantQuest::IsStaticQuest() const {
    return false;
}

bool ARemnantQuest::IsRootQuest() const {
    return false;
}

bool ARemnantQuest::IsLoadingOrLoaded() const {
    return false;
}

bool ARemnantQuest::IsLoaded() const {
    return false;
}

bool ARemnantQuest::HasRespawn() const {
    return false;
}

bool ARemnantQuest::HasQuestEntitlements() const {
    return false;
}

bool ARemnantQuest::HasLastCheckpoint() const {
    return false;
}

bool ARemnantQuest::HasFailedToLoad() const {
    return false;
}

bool ARemnantQuest::HasActiveBreadcrumbs() {
    return false;
}

void ARemnantQuest::GiveRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, int32 RandomSeed) {
}

void ARemnantQuest::GiveRewardToPlayer(ARemnantCharacter* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType) {
}

void ARemnantQuest::GiveReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType) {
}

void ARemnantQuest::GiveDetailedRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, FRemnantQuestReward& Reward, int32 RandomSeed) {
}

void ARemnantQuest::GiveDetailedReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, FRemnantQuestReward& Reward) {
}

FZoneLinkInfo ARemnantQuest::GetRespawn() const {
    return FZoneLinkInfo{};
}

int32 ARemnantQuest::GetQuestLevel() {
    return 0;
}

UInventoryComponent* ARemnantQuest::GetQuestInventory() {
    return NULL;
}

void ARemnantQuest::GetQuestEntitlements(TArray<TSubclassOf<UEntitlementType>>& OutEntitlements, bool bGetMissingOnly) const {
}

bool ARemnantQuest::GetObjectQuestValue(UClass* ObjectBP, int32& ObjectValue, float& OutSellScalar, int32& OutPickupValue) {
    return false;
}

FZoneLinkInfo ARemnantQuest::GetLastCheckpoint() const {
    return FZoneLinkInfo{};
}

FString ARemnantQuest::GetBiomeName() {
    return TEXT("");
}

TArray<FZoneLinkInfo> ARemnantQuest::GetAutoJoinZoneLinks_Implementation() {
    return TArray<FZoneLinkInfo>();
}

void ARemnantQuest::EventSetRespawn(FZoneLinkInfo ZoneLink) {
}

void ARemnantQuest::EventQuestComplete(AQuest* Quest, EQuestResult Result) {
}

void ARemnantQuest::EventAddItem(TSubclassOf<AItem> ItemBP, int32 Quantity) {
}

void ARemnantQuest::DeactivateQuest() {
}

void ARemnantQuest::CompleteBreadcrumb(FName BreadcrumbNameID) {
}

void ARemnantQuest::ActivateQuestItemEvents() {
}

ERemnantQuestStatus ARemnantQuest::ActivateQuest() {
    return ERemnantQuestStatus::Unloaded;
}

void ARemnantQuest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantQuest, Level);
    DOREPLIFETIME(ARemnantQuest, Difficulty);
    DOREPLIFETIME(ARemnantQuest, SlotID);
    DOREPLIFETIME(ARemnantQuest, ZoneID);
    DOREPLIFETIME(ARemnantQuest, BreadcrumbInfo);
    DOREPLIFETIME(ARemnantQuest, Status);
    DOREPLIFETIME(ARemnantQuest, LastCheckpointZoneID);
    DOREPLIFETIME(ARemnantQuest, LastCheckpointNameID);
}

ARemnantQuest::ARemnantQuest() {
    this->PersistenceComponent = CreateDefaultSubobject<UPersistenceComponent>(TEXT("Persistence"));
    this->VariableComponent = CreateDefaultSubobject<UVariableComponent>(TEXT("Variables"));
    this->Type = ERemnantQuestType::Default;
    this->Rarity = ERemnantQuestRarity::Common;
    this->MaxUsageCount = 1;
    this->DebugState = ERemnantQuestDebugState::None;
    this->IsOneShot = false;
    this->IgnoreTileExclusivity = false;
    this->IgnoresTileIDRequirement = false;
    this->QuestGameMode = EQuestMode::Campaign;
    this->RequiredAward = NULL;
    this->LevelMin = 0;
    this->LevelMax = 100;
    this->Level = 1;
    this->Difficulty = 1;
    this->SlotID = -2;
    this->ZoneID = -1;
    this->RequiredEntitlement = NULL;
    this->bDisableMultiplayer = false;
    this->ItemValueTable = NULL;
    this->Status = ERemnantQuestStatus::Unloaded;
    this->LastCheckpointZoneID = -2;
    this->RespawnZoneID = -2;
    this->ContainerLevel = NULL;
    this->Created = false;
}

