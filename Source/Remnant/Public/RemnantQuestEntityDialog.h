#pragma once
#include "CoreMinimal.h"
#include "DialogProviderInterface.h"
#include "RemnantQuestComponent.h"
#include "RemnantQuestEntityDialog.generated.h"

class AActor;
class UEventTree;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestEntityDialog : public URemnantQuestComponent, public IDialogProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventTree* Dialog;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldBeContextProviderForDefaultTree;
    
    URemnantQuestEntityDialog();
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorSpawned(AActor* Actor);
    
    
    // Fix for true pure virtual functions not being implemented
};

