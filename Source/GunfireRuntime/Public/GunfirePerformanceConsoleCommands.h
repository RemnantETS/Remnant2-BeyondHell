#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GunfirePerformanceConsoleCommands.generated.h"

class UWorld;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGunfirePerformanceConsoleCommands : public UObject {
    GENERATED_BODY()
public:
    UGunfirePerformanceConsoleCommands();
    UFUNCTION(BlueprintCallable, Exec)
    static void ExecutePerf(const TArray<FString>& Args, UWorld* World);
    
    UFUNCTION(BlueprintCallable, Exec)
    static void ExecuteMem(const TArray<FString>& Args, UWorld* World);
    
};

