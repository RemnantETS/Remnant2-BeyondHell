#include "TargetManager.h"

void UTargetManager::QueryPotentialTargetsAlongAimVector(APawn* Source, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable, bool CullNotSoftTargetable, TArray<FTargetQueryResult>& Results, bool bSortResults) {
}

void UTargetManager::QueryPotentialTargets(AActor* Source, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable, bool CullNotSoftTargetable, TArray<FTargetQueryResult>& Results, bool bSortResults) {
}

UTargetableComponent* UTargetManager::QueryBestPotentialTargetAlongAimVector(APawn* Source, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable) {
    return NULL;
}

UTargetableComponent* UTargetManager::QueryBestPotentialTarget(AActor* Source, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, bool CullNotLockable) {
    return NULL;
}

float UTargetManager::K2_GetScoreForTargetLocation(AActor* Source, const FVector& Target, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible, const TArray<AActor*>& LOSIgnoreActors) {
    return 0.0f;
}

float UTargetManager::K2_GetScoreForTargetActor(AActor* Source, AActor* Target, float Yaw, float Pitch, float Range, float HorizontalArc, float VerticalArc, bool CullNotVisible) {
    return 0.0f;
}

FVector UTargetManager::GetSoftTargetLocation(AActor* Target, const FVector& OriginLocation) {
    return FVector{};
}

FVector UTargetManager::GetBestTargetingLocationOnActorForTarget(AActor* Source, const FVector& TargetLocation) {
    return FVector{};
}

UTargetManager::UTargetManager() {
}

