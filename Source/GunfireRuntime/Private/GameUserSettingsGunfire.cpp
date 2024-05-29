#include "GameUserSettingsGunfire.h"



bool UGameUserSettingsGunfire::NeedsHardwareBenchmark() const {
    return false;
}

TArray<UUserSetting*> UGameUserSettingsGunfire::GetSettingsForCategory(const FName& Category) const {
    return TArray<UUserSetting*>();
}

void UGameUserSettingsGunfire::GetInputConflicts(URebindableInputSetting* Setting, FGenericInput Key, const TArray<FName>& Categories, TArray<URebindableInputSetting*>& Conflicts) {
}

UUserSetting* UGameUserSettingsGunfire::FindUserSetting(FName NameID) const {
    return NULL;
}

bool UGameUserSettingsGunfire::AreSettingsInitialized() const {
    return false;
}

bool UGameUserSettingsGunfire::AllowsInputRebindings() const {
    return false;
}

UGameUserSettingsGunfire::UGameUserSettingsGunfire() {
}

