#include "ListUserSetting.h"

void UListUserSetting::SetValue(int32 ValueIn) {
}

bool UListUserSetting::SetNextEntry(bool bForwards) {
    return false;
}

int32 UListUserSetting::GetValue() const {
    return 0;
}

UListUserSetting::UListUserSetting() {
    this->bWraps = true;
}

