#pragma once
#include "CoreMinimal.h"
#include "QuestComponent.h"
#include "RemnantQuestComponent.generated.h"

class ARemnantQuest;
class AZoneActor;
class URemnantQuestEntity;
class URemnantQuestTile;
class URemnantQuestZone;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestComponent : public UQuestComponent {
    GENERATED_BODY()
public:
    URemnantQuestComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneLoaded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AZoneActor* GetZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRemnantQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestZone* GetQuestZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestTile* GetQuestTile();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestEntity* GetQuestEntity();
    
};

