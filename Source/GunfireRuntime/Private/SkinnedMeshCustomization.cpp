#include "SkinnedMeshCustomization.h"

USkinnedMeshCustomization::USkinnedMeshCustomization() {
    this->ClothingSimulationFactory = NULL;
    this->bShouldOverrideAnimInstance = false;
    this->bReInitPoseOnApply = false;
    this->bClearMeshOnRemove = true;
    this->bResetMaterialsOnApply = true;
    this->bAlwaysFirst = false;
}

