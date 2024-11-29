#include "RemnantQuestLink.h"

void URemnantQuestLink::OnLinkDeactivated(UQuestComponent* Component) {
}

void URemnantQuestLink::OnLinkActivated(UQuestComponent* Component) {
}

URemnantQuestLink::URemnantQuestLink(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer) {
    this->AutoLink = false;
    this->IsMainPath = false;
    this->IsWorldMapLocation = false;
    this->AutoLinkQuestID = -1;
}

