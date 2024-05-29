#include "QuestEntity.h"

void UQuestEntity::StartEventTree(UEventTree* NewEventTree) {
}

bool UQuestEntity::IsSpawned() const {
    return false;
}

bool UQuestEntity::HasEventTree(FName NameID) const {
    return false;
}

UEventTree* UQuestEntity::GetEventTreeByID(FName NameID) const {
    return NULL;
}

AActor* UQuestEntity::GetActor() const {
    return NULL;
}

void UQuestEntity::EndDialog() {
}

void UQuestEntity::DialogTrigger(FName TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack) {
}

void UQuestEntity::BeginDialog(AActor* Initiator) {
}

UQuestEntity::UQuestEntity() {
    this->ShouldBeContextProviderForDefaultTree = false;
    this->OwnerContext = EQuestEntityOwnerContext::Quest;
}

