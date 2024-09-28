#include "DragonHeart.h"

ADragonHeart::ADragonHeart(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ValidationTags.AddDefaulted(1);
    this->NumCharges = 3;
    this->UpgradeItemBP = NULL;
    this->DHPoolComponent = NULL;
}

void ADragonHeart::VerifyQuantity() {
}

void ADragonHeart::Regenerate() {
}

void ADragonHeart::OnPoolValueChanged(UVitalityComponent* PoolComponent) {
}

int32 ADragonHeart::GetMaxCurrentQuantity() {
    return 0;
}


