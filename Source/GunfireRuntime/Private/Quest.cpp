#include "Quest.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"

AQuest::AQuest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("QuestRoot"));
    this->ID = 0;
    this->ParentQuestID = -1;
    this->Seed = 0;
    this->QuestState = EQuestState::Active;
    this->QuestResult = EQuestResult::Success;
    this->ParentQuestComponent = NULL;
}

void AQuest::SetObjectiveCounterMax(FName NameID, int32 MaxCount) {
}

void AQuest::ResetObjective(FName NameID) {
}

void AQuest::ResetAllObjectives(bool ResetQuestState) {
}

void AQuest::OnResetQuest_Implementation() {
}

void AQuest::OnQuestManagerReady() {
}

void AQuest::OnQuestComplete_Implementation(EQuestResult Result) {
}

void AQuest::OnPostInitializeQuest_Implementation() {
}

void AQuest::OnPostCreateQuest_Implementation() {
}

void AQuest::OnObjectiveUpdated_Implementation(UQuestObjective* Objective) {
}

void AQuest::OnObjectiveComplete_Implementation(FName NameID) {
}

void AQuest::OnObjectiveActivate_Implementation(FName NameID) {
}

void AQuest::OnInitializeQuest_Implementation() {
}

void AQuest::OnDestroyQuest_Implementation() {
}

void AQuest::OnDeinitializeQuest_Implementation() {
}

void AQuest::OnCreateQuest_Implementation(const FRandomStream& RandomStream) {
}

void AQuest::OnBeginQuest_Implementation() {
}

void AQuest::NotifyQuestComplete_Implementation(EQuestResult Result) {
}

bool AQuest::IsQuestComplete() const {
    return false;
}

bool AQuest::IsQuestActive() const {
    return false;
}

bool AQuest::IsObjectiveComplete(FName NameID) {
    return false;
}

bool AQuest::IsObjectiveActive(FName NameID) {
    return false;
}

void AQuest::IncrementObjectiveCounter(FName NameID, bool AutoComplete) {
}

bool AQuest::HasActiveObjectives(bool IncludeHidden) {
    return false;
}

FName AQuest::GetUniqueName() {
    return NAME_None;
}

AQuest* AQuest::GetRootQuestForScope() {
    return NULL;
}

AQuest* AQuest::GetRootQuest() {
    return NULL;
}

void AQuest::GetQuestObjectives(TArray<UQuestObjective*>& Objectives) {
}

UQuestObjective* AQuest::GetQuestObjective(FName NameID) {
    return NULL;
}

AQuest* AQuest::GetParentQuest() {
    return NULL;
}

int32 AQuest::GetObjectiveCountRemaining(FName NameID) {
    return 0;
}

int32 AQuest::GetObjectiveCounterMax(FName NameID) {
    return 0;
}

int32 AQuest::GetObjectiveCounter(FName NameID) {
    return 0;
}

void AQuest::CompleteQuest(EQuestResult Result) {
}

void AQuest::CompleteObjective(FName NameID, EQuestResult ObjectiveResult) {
}

bool AQuest::AreAnyObjectivesActiveOrComplete() {
    return false;
}

void AQuest::ActivateObjective(FName NameID, bool AutoCompleteActiveObjectives) {
}

void AQuest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AQuest, ID);
    DOREPLIFETIME(AQuest, ParentQuestID);
    DOREPLIFETIME(AQuest, Seed);
    DOREPLIFETIME(AQuest, QuestState);
    DOREPLIFETIME(AQuest, QuestResult);
}


