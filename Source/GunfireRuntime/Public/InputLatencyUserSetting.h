#pragma once
#include "CoreMinimal.h"
#include "BinaryUserSetting.h"
#include "InputLatencyUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UInputLatencyUserSetting : public UBinaryUserSetting {
    GENERATED_BODY()
public:
    UInputLatencyUserSetting();
};

