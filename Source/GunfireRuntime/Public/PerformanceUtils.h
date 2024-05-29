#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProfileData.h"
#include "ProfileDataStats.h"
#include "ProfileHistory.h"
#include "ProfileSummaryResult.h"
#include "PerformanceUtils.generated.h"

class UStaticMesh;
class UWorld;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UPerformanceUtils : public UObject {
    GENERATED_BODY()
public:
    UPerformanceUtils();
    UFUNCTION(BlueprintCallable)
    static FProfileSummaryResult ProfileSummary(const FProfileHistory& ProfileHistory, bool bShouldLog);
    
    UFUNCTION(BlueprintCallable)
    static void ProfileStatsLog(const FProfileDataStats& Stat);
    
    UFUNCTION(BlueprintCallable)
    static void ProfileLog(const FProfileData& NewProfile);
    
    UFUNCTION(BlueprintCallable)
    static FProfileData Profile(const UWorld* World, bool bAverage, bool bShouldLog);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetTriCountWithCollision(UStaticMesh* Mesh);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPrimCountWithCollision(UStaticMesh* Mesh);
    
};

