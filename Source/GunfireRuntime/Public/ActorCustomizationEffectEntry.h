#pragma once
#include "CoreMinimal.h"
#include "ActorCustomizationBase.h"
#include "ActorCustomizationEffectEntry.generated.h"

class UActorCustomizationEffect;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationEffectEntry : public UActorCustomizationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorCustomizationEffect*> Nodes;
    
    UActorCustomizationEffectEntry();
};

