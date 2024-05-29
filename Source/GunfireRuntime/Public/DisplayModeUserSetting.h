#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "DisplayModeUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UDisplayModeUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UDisplayModeUserSetting();
};

