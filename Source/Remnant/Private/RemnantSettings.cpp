#include "RemnantSettings.h"

URemnantSettings::URemnantSettings() {
    this->ModPowerSplashScalar = 0.25f;
    this->ModPowerSplashFromOtherModScalar = 0.00f;
    this->BonusModPower = 100.00f;
    this->bAnalogCursorOverridesMouseLock = true;
    this->AnalogCursorMouseLockMode = EMouseLockMode::LockAlways;
    this->PingDistance = 10000.00f;
}

