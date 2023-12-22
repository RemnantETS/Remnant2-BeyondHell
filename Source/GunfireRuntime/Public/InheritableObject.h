#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InheritableObject.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UInheritableObject : public UDataAsset {
    GENERATED_BODY()
public:
    UInheritableObject();
};

