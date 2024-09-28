#include "LoreItem.h"

ALoreItem::ALoreItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AutoOpenUI = false;
    this->OverrideHideReadUI = false;
}

void ALoreItem::LoreNotify(UObject* WorldContextObject, const FLorePage& Page) {
}


