#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "QuestItemActionInterface.generated.h"

class UActionBase;

UINTERFACE(Blueprintable, MinimalAPI)
class UQuestItemActionInterface : public UInterface {
    GENERATED_BODY()
};

class IQuestItemActionInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetTargetZoneID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetTargetActiveQuestID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<UActionBase> GetGetActionToApply() const;
    
};

