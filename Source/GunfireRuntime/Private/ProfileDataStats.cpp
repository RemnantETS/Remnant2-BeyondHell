#include "ProfileDataStats.h"

FProfileDataStats::FProfileDataStats() {
    this->Type = EPerfTimeType::Frame;
    this->Min = 0.00f;
    this->Max = 0.00f;
    this->Avg = 0.00f;
    this->Bound = 0.00f;
}

