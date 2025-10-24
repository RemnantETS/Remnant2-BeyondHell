#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InheritableObject.generated.h"

UCLASS(Abstract, NotBlueprintable)
class GUNFIRERUNTIME_API UInheritableObject : public UObject {
    GENERATED_BODY()
public:
    UInheritableObject();
};

