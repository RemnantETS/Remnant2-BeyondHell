#include "RemnantQuestEntityDialog.h"

void URemnantQuestEntityDialog::OnActorSpawned(AActor* Actor) {
}

URemnantQuestEntityDialog::URemnantQuestEntityDialog() {
    this->Dialog = NULL;
    this->ShouldBeContextProviderForDefaultTree = false;
}

