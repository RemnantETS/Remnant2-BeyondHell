#include "PerformanceUtils.h"

FProfileSummaryResult UPerformanceUtils::ProfileSummary(const FProfileHistory& ProfileHistory, bool bShouldLog) {
    return FProfileSummaryResult{};
}

void UPerformanceUtils::ProfileStatsLog(const FProfileDataStats& Stat) {
}

void UPerformanceUtils::ProfileLog(const FProfileData& NewProfile) {
}

FProfileData UPerformanceUtils::Profile(const UWorld* World, bool bAverage, bool bShouldLog) {
    return FProfileData{};
}

int32 UPerformanceUtils::GetTriCountWithCollision(UStaticMesh* Mesh) {
    return 0;
}

int32 UPerformanceUtils::GetPrimCountWithCollision(UStaticMesh* Mesh) {
    return 0;
}

UPerformanceUtils::UPerformanceUtils() {
}

