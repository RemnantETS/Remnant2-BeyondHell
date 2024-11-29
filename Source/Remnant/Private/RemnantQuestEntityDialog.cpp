#include "RemnantQuestEntityDialog.h"

void URemnantQuestEntityDialog::OnActorSpawned(AActor* Actor) {
}

URemnantQuestEntityDialog::URemnantQuestEntityDialog(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->Dialog = NULL;
    this->ShouldBeContextProviderForDefaultTree = false;
}

