#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ComputeStatsDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "StatsComponent.generated.h"

class UComputedStats;
class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UStatsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle StatData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle StatCapData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UComputedStats>> ComputedStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDataTable*> AdditionalStats;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputeStatsDelegate OnComputeStats;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputeStatsDelegate OnComputeDerivedStats;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputeStatsDelegate OnPostComputeStats;
    
    UStatsComponent();
    UFUNCTION(BlueprintCallable)
    void SetComputedStats(TSubclassOf<UComputedStats> NewComputedStats);
    
    UFUNCTION(BlueprintCallable)
    void ScaleStat(const FName& Name, float Scalar, bool AutoInitValue);
    
    UFUNCTION(BlueprintCallable)
    float ModifyStat(const FName& Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    bool IsStatCapped(FName Name, bool ApplyMod);
    
    UFUNCTION(BlueprintCallable)
    void Invalidate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStat(const FName& Name, bool ApplyMod);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatAsInt(FName Name, bool ApplyMod);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStatAsBool(FName Name, bool ApplyMod);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Name, bool ApplyMod);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UComputedStats> GetComputedStats();
    
    UFUNCTION(BlueprintCallable)
    void ComputeStatsIfDirty();
    
    UFUNCTION(BlueprintCallable)
    void ClampStat(UPARAM(Ref) float& Value, FName Stat);
    
    UFUNCTION(BlueprintCallable)
    void ApplyStats(const FDataTableRowHandle& DataTable, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void ApplyStatModsTo(UPARAM(Ref) float& Value, FName Stat, bool NewClampStat);
    
};

