#include "EventTreeNode_SetState.h"

UEventTreeNode_SetState::UEventTreeNode_SetState() {
    this->TargetDialogObjectID = TEXT("Player");
    this->TargetStateName = TEXT("Default");
    this->OnlySetStateIfValid = true;
    this->RestoreStateOnEventTreeEnd = false;
    this->RestoreStateOnStomp = true;
}


