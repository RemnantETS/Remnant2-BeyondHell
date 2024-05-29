#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MemorySceneInfo.generated.h"

class UWorld;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMemorySceneInfo : public AActor {
    GENERATED_BODY()
public:
    AMemorySceneInfo();
    UFUNCTION(BlueprintCallable)
    void ExecuteMemSceneInfo(const TArray<FString>& Args, UWorld* World);
    
};

