#include "RandomSkinnedMeshCustomization.h"

URandomSkinnedMeshCustomization::URandomSkinnedMeshCustomization() {
    this->ClothingSimulationFactory = NULL;
    this->bShouldOverrideAnimInstance = false;
    this->bResetMaterialsOnApply = true;
}

