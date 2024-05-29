#include "AddModPowerParams.h"

FAddModPowerParams::FAddModPowerParams() {
    this->EquipmentTarget = EEquipmentTarget::BothWeapons;
    this->TargetActor = NULL;
    this->Damage = 0.00f;
    this->BonusModPowerMod = 0.00f;
    this->FillActiveMods = false;
}

