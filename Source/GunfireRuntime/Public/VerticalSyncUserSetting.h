#pragma once
#include "CoreMinimal.h"
#include "BinaryUserSetting.h"
#include "VerticalSyncUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UVerticalSyncUserSetting : public UBinaryUserSetting {
    GENERATED_BODY()
public:
    UVerticalSyncUserSetting();
};

