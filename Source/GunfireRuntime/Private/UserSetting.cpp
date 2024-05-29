#include "UserSetting.h"

void UUserSetting::ResetToDefault() {
}

bool UUserSetting::IsVisible() const {
    return false;
}

bool UUserSetting::IsEnabled() const {
    return false;
}

FText UUserSetting::GetLabel() const {
    return FText::GetEmpty();
}

FText UUserSetting::GetDisplayValue() const {
    return FText::GetEmpty();
}

FText UUserSetting::GetDescription() const {
    return FText::GetEmpty();
}

void UUserSetting::Apply_Implementation() {
}

UUserSetting::UUserSetting() {
    this->bMainMenuOnly = false;
    this->Platforms = 255;
    this->Settings = NULL;
}

