#include "ProfileData.h"

FProfileData::FProfileData() {
    this->IsAveraged = false;
    this->Frame = 0.00f;
    this->Game = 0.00f;
    this->Render = 0.00f;
    this->RHI = 0.00f;
    this->GPU = 0.00f;
    this->Draws = 0.00f;
    this->Prims = 0.00f;
}

