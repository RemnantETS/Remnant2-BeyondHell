#include "ActorCustomizationComponent.h"
#include "Net/UnrealNetwork.h"

void UActorCustomizationComponent::UpdateSlots() {
}

void UActorCustomizationComponent::StopAllStreamingRequests() {
}

void UActorCustomizationComponent::SetupSlaveMeshes() {
}

void UActorCustomizationComponent::SetSlotEnabled(FName SlotID, bool bIsEnabled) {
}

void UActorCustomizationComponent::SetCustomizationAt(FName SlotID, int32 Idx) {
}

void UActorCustomizationComponent::SetCustomization(FName SlotID, FName CustomizationID) {
}

void UActorCustomizationComponent::RemoveBPCustomizationTags(const TArray<FName>& InTags) {
}

void UActorCustomizationComponent::PlayCustomizationEffect(FName NameID, bool bCache) {
}

void UActorCustomizationComponent::OnRep_Seed() {
}

void UActorCustomizationComponent::OnCustomizationLoaded(FName SlotID, FName CustomizationID, bool bCleared) {
}

bool UActorCustomizationComponent::HasOutstandingStreamingRequests() {
    return false;
}

FName UActorCustomizationComponent::GetSlotCustomizationID(FName SlotID) {
    return NAME_None;
}

TSoftObjectPtr<UObject> UActorCustomizationComponent::GetPreviewMeshForCustomization(FName SlotID, FName CustomizationID, bool bAllowStaticMeshes, bool bAllowSkeletalMeshes) const {
    return NULL;
}

int32 UActorCustomizationComponent::GetNumCustomizationsForSlotID(FName SlotID) const {
    return 0;
}

bool UActorCustomizationComponent::GetIconForCustomization(FName SlotID, FName CustomizationID, TSoftObjectPtr<UTexture2D>& OutIcon) const {
    return false;
}

bool UActorCustomizationComponent::GetDisplayColorForCustomization(FName SlotID, FName CustomizationID, FLinearColor& OutColor) const {
    return false;
}

int32 UActorCustomizationComponent::GetCustomizationPositionInSlot(FName SlotID) {
    return 0;
}

FName UActorCustomizationComponent::GetCustomizationAt(FName SlotID, int32 Idx) {
    return NAME_None;
}

bool UActorCustomizationComponent::GetAllCustomizationsForSlot(FName SlotID, TArray<FName>& OutCustomizations) {
    return false;
}

void UActorCustomizationComponent::ClearCustomization(FName SlotID) {
}

void UActorCustomizationComponent::AddBPCustomizationTags(const TArray<FName>& InTags) {
}

void UActorCustomizationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorCustomizationComponent, Seed);
    DOREPLIFETIME(UActorCustomizationComponent, Slots);
}

UActorCustomizationComponent::UActorCustomizationComponent() {
    this->Seed = 0;
    this->CustomizationSet = NULL;
    this->bUsesValidChildMeshes = false;
}

