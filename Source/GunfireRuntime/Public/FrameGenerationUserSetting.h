#pragma once
#include "CoreMinimal.h"
#include "BinaryUserSetting.h"
#include "FrameGenerationUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UFrameGenerationUserSetting : public UBinaryUserSetting {
    GENERATED_BODY()
public:
    UFrameGenerationUserSetting();
};

