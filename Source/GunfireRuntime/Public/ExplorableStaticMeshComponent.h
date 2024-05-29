#pragma once
#include "CoreMinimal.h"
#include "ExplorableStaticMeshComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExplorableStaticMeshComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UExplorableStaticMeshComponent();
};

