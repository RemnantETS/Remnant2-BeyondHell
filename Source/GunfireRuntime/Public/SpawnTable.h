#pragma once
#include "CoreMinimal.h"
#include "ESpawnTableType.h"
#include "ESpawnType.h"
#include "SpawnList.h"
#include "SpawnTableEntry.h"
#include "SpawnTable.generated.h"

class UObject;

UCLASS(BlueprintType, Blueprintable)
class GUNFIRERUNTIME_API USpawnTable : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnTableType TableType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpawnTableEntry*> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TableGroupRollMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TableGroupRollMax;
    
    USpawnTable();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void GenerateWithSeed(UObject* WorldContextObject, int32 Level, int32 Rating, const TArray<FName>& InTags, FSpawnList& SpawnList, ESpawnType Type, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void Generate(UObject* WorldContextObject, int32 Level, int32 Rating, const TArray<FName>& InTags, FSpawnList& SpawnList, ESpawnType Type);
    
};

