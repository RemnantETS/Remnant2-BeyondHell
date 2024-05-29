#pragma once
#include "CoreMinimal.h"
#include "EDamageAuthority.generated.h"

UENUM(BlueprintType)
enum class EDamageAuthority : uint8 {
    Client,
    Server,
};

