#pragma once
#include "CoreMinimal.h"
#include "R:\UnrealProjects\Remnant2-BeyondHell\Source\GunfireRuntime\Public\QuestRecordsComponent.h"
#include "RemnantQuestRecordsComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestRecordsComponent : public UQuestRecordsComponent {
    GENERATED_BODY()
public:
    URemnantQuestRecordsComponent(const FObjectInitializer& ObjectInitializer);

};

