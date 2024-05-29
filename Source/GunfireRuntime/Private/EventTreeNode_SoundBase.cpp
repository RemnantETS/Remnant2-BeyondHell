#include "EventTreeNode_SoundBase.h"

void UEventTreeNode_SoundBase::OnFinishedWaiting(UEventTreeComponent* Component) {
}

UEventTreeNode_SoundBase::UEventTreeNode_SoundBase() {
    this->AutoComplete = false;
    this->CompleteAfterDialog = false;
    this->WaitTimeAfterComplete = 0.10f;
}

