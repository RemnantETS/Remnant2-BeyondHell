#include "PlayerRecordData.h"

FPlayerRecordData::FPlayerRecordData() {
    this->RecordType = ERecordType::Increment;
    this->ScoreIncrement = 0.00f;
    this->ExpIncrement = 0.00f;
    this->bIsMVPEligible = false;
    this->MVPCompareRule = EMVPCompareRule::Higher;
    this->bEnableFallbackTitles = false;
    this->ValueData = NULL;
    this->Icon = NULL;
}

