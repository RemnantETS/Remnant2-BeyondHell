#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "SpawningOwnerInterface.generated.h"

class AActor;
class ULevel;

UINTERFACE(Blueprintable, MinimalAPI)
class USpawningOwnerInterface : public UInterface {
    GENERATED_BODY()
};

class ISpawningOwnerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ULevel* GetWorldLevelForDrop(AActor* SourceActor);
    
};

