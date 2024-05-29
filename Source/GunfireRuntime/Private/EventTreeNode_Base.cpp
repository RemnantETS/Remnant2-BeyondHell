#include "EventTreeNode_Base.h"

FString UEventTreeNode_Base::GetEditorLabel_Implementation() const {
    return TEXT("");
}

UEventTreeNode_Base::UEventTreeNode_Base() {
    this->Enabled = true;
    this->DoOnce = false;
    this->DoOnceExpiration = -1.00f;
    this->Seed = 31055;
    this->UniqueId = 0;
}

