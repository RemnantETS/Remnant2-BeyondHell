#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InheritableObject.generated.h"

UCLASS(Abstract, NotBlueprintable, meta = (UsesHierarchy))
class GUNFIRERUNTIME_API UInheritableObject : public UObject {
    GENERATED_BODY()
public:
    UInheritableObject();
};

