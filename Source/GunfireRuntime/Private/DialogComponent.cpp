#include "DialogComponent.h"
#include "Net/UnrealNetwork.h"

void UDialogComponent::TokenValueSet(const FName& NameID, const FText& Value) {
}

void UDialogComponent::SelectOptionByName(FName OptionName) {
}

void UDialogComponent::SelectOption(uint8 OptionID) {
}

void UDialogComponent::ResetStageFromCinematic() {
}

void UDialogComponent::RemoveDialogProvider(UObject* Provider) {
}

void UDialogComponent::OnRep_Stage() {
}

void UDialogComponent::OnRep_Options() {
}

void UDialogComponent::OnRep_Dialog() {
}

void UDialogComponent::OnRep_CameraShot() {
}

void UDialogComponent::OnRep_Active() {
}

void UDialogComponent::OnInitiatorTakeAnyDamage(const FDamageInfo& Damage) {
}

void UDialogComponent::OnDialogFinished(UDialogInstance* Instance) {
}

void UDialogComponent::MulticastShowEmote_Implementation(const FName& Speaker, const FName& EmoteName, bool TargetAllPlayers) {
}

void UDialogComponent::JoinInProgressServer(APlayerController* Controller) {
}

void UDialogComponent::JoinInProgressClient() {
}

bool UDialogComponent::HasOption(FName NameID) {
    return false;
}

bool UDialogComponent::HasAttributeValueForStage(FName Key) {
    return false;
}

bool UDialogComponent::HasAttributeValueForOption(const FDialogOption& Option, FName Key) {
    return false;
}

bool UDialogComponent::HasAttributeValue(FName Key) {
    return false;
}

bool UDialogComponent::HasActiveDialog() {
    return false;
}

void UDialogComponent::HandleEvent(FName EventName) {
}

FText UDialogComponent::GetTokenReplacedText() const {
    return FText::GetEmpty();
}

TArray<AActor*> UDialogComponent::GetRelevantNPCs() {
    return TArray<AActor*>();
}

AActor* UDialogComponent::GetRelevantNPC(const FName& NameID) {
    return NULL;
}

FText UDialogComponent::GetAttributeValueForStage(FName Key) {
    return FText::GetEmpty();
}

FText UDialogComponent::GetAttributeValueForOption(const FDialogOption& Option, FName Key) {
    return FText::GetEmpty();
}

FText UDialogComponent::GetAttributeValue(FName Key) {
    return FText::GetEmpty();
}

UEventTreeAsset* UDialogComponent::GetAttributeAssetForStage(FName Key) {
    return NULL;
}

bool UDialogComponent::ExecuteTrigger(const FName& TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack) {
    return false;
}

bool UDialogComponent::ExecuteItemTrigger(TSoftClassPtr<AItem> ItemBP, AActor* Initiator) {
    return false;
}

void UDialogComponent::EventTreeStageEvent(const FEventTreeStage& EventTreeStage) {
}

void UDialogComponent::EventEnd() {
}

void UDialogComponent::EventBegin() {
}

void UDialogComponent::DialogAdvance() {
}

void UDialogComponent::BeginDialog(AActor* Initiator) {
}

void UDialogComponent::AddRelevantNPC(AActor* NPC) {
}

void UDialogComponent::AddDialogProvider(UObject* Provider) {
}

void UDialogComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDialogComponent, AllowMultipleSpeakers);
    DOREPLIFETIME(UDialogComponent, DialogInitiator);
    DOREPLIFETIME(UDialogComponent, DialogActive);
    DOREPLIFETIME(UDialogComponent, DialogStage);
    DOREPLIFETIME(UDialogComponent, DialogAttributes);
    DOREPLIFETIME(UDialogComponent, Dialog);
    DOREPLIFETIME(UDialogComponent, DialogOptions);
    DOREPLIFETIME(UDialogComponent, CameraShotInfo);
    DOREPLIFETIME(UDialogComponent, TokenValuePairs);
}

UDialogComponent::UDialogComponent() {
    this->EventTree = NULL;
    this->AutoPlayDialog = false;
    this->EnableProximityTriggers = false;
    this->StageBP = NULL;
    this->Stage = NULL;
    this->AllowMultipleSpeakers = false;
    this->DialogInitiator = NULL;
    this->DialogActive = false;
    this->CurrentDialog = NULL;
}

