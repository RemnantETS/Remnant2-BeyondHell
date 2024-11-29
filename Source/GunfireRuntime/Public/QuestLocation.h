#pragma once
#include "CoreMinimal.h"
#include "QuestComponent.h"
#include "QuestLocation.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UQuestLocation : public UQuestComponent {
    GENERATED_BODY()
public:
    UQuestLocation(const FObjectInitializer& ObjectInitializer);
};

