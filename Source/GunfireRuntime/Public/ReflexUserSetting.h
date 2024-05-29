#pragma once
#include "CoreMinimal.h"
#include "ListUserSetting.h"
#include "ReflexUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UReflexUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UReflexUserSetting();
};

