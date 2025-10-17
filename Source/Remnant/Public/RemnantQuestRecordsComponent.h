#pragma once
#include "CoreMinimal.h"
#include "QuestRecordsComponent.h"
#include "RemnantQuestRecordsComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestRecordsComponent : public UQuestRecordsComponent {
    GENERATED_BODY()
public:
    URemnantQuestRecordsComponent(const FObjectInitializer& ObjectInitializer);

};

