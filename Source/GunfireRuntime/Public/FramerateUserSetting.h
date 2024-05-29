#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "FramerateUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UFramerateUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UFramerateUserSetting();
};

