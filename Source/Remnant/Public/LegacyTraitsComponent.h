#pragma once
#include "CoreMinimal.h"
#include "TraitsComponent.h"
#include "ETraitProgressionType.h"
#include "LegacyTraitsComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API ULegacyTraitsComponent : public UTraitsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETraitProgressionType ProgressionType;
    
    ULegacyTraitsComponent(const FObjectInitializer& ObjectInitializer);
};

