#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerformanceSceneInfo.generated.h"

class UPerformanceSceneGroup;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APerformanceSceneInfo : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Verbosity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPerformanceSceneGroup*> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GroupIdx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EditorOnlyActorsCount;
    
public:
    APerformanceSceneInfo();
    UFUNCTION(BlueprintCallable)
    void ExecutePerfSceneInfo(const TArray<FString>& Args);
    
};

