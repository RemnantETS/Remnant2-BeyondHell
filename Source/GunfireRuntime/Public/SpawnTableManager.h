#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SpawnTableManager.generated.h"

class UDataTable;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API USpawnTableManager : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* OverridesTable;
    
public:
    USpawnTableManager();
private:
    UFUNCTION(BlueprintCallable)
    void FinishLoadOverrideDataTable();
    
};

