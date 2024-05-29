#include "CheatInputSettings.h"

UCheatInputSettings::UCheatInputSettings() {
    this->bCheatsEnabled = true;
    this->bCheatMenuWaitsFullDuration = false;
    this->GlobalCheatToggleKeys.AddDefaulted(2);
    this->CheatCategories.AddDefaulted(8);
    this->ActionMappings.AddDefaulted(78);
}

