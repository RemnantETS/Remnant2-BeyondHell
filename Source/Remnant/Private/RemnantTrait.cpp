#include "RemnantTrait.h"
#include "Templates/SubclassOf.h"

URemnantTrait::URemnantTrait() {
}

void URemnantTrait::SetTraitProgress_Implementation(int32 Progress) {
}

int32 URemnantTrait::GetTraitProgress_Implementation() {
    return 0;
}

TSubclassOf<AItem> URemnantTrait::GetRelevantItemAsset_Implementation() {
    return NULL;
}


