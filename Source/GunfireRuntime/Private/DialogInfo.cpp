#include "DialogInfo.h"

FDialogInfo::FDialogInfo() {
    this->RemoveEmoteOnFinish = false;
    this->SourceComponent = NULL;
    this->LookAtTarget = NULL;
    this->TextCounter = 0;
    this->IgnoreVocalRange = false;
    this->VocalRange = NULL;
    this->BlockInteractions = false;
    this->PlayOnlyLocally = false;
}

