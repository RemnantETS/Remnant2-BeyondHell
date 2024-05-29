#include "RemnantAssetManagerSettings.h"

URemnantAssetManagerSettings::URemnantAssetManagerSettings() {
    this->DLCPathPrefix = TEXT("/Game/World_DLC");
    this->DLCPakOffset = 1;
    this->AssetPakRedirection.AddDefaulted(2);
    this->AssetsToIgnoreFile = TEXT("AssetsToIgnore.json");
}

