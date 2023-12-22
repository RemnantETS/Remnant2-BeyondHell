#pragma once
#include "CoreMinimal.h"
#include "ActorCustomizationBase.h"
#include "ActorCustomizationEffect.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationEffect : public UActorCustomizationBase {
    GENERATED_BODY()
public:
    UActorCustomizationEffect();
};

