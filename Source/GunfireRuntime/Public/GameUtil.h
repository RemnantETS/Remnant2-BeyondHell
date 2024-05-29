#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Camera/CameraTypes.h"
#include "Engine/EngineTypes.h"
#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "ActorQueryFilter.h"
#include "ActorQueryResult.h"
#include "ActorQueryShapeDetails.h"
#include "CachedMaterialState.h"
#include "EBasePlatform.h"
#include "EBuildType.h"
#include "ELevelContextFallback.h"
#include "ELocalizationLanguage.h"
#include "EVideoDeviceVendor.h"
#include "ObjectArraySortPredicateDelegate.h"
#include "Templates/SubclassOf.h"
#include "GameUtil.generated.h"

class AActor;
class ACharacter;
class ACharacterGunfire;
class AGameModeBase;
class ALevelScriptActor;
class APawn;
class APlayerController;
class APlayerStart;
class APlayerState;
class UActorComponent;
class UBehaviorTree;
class UCameraShakeBase;
class UForceFeedbackEffect;
class UGameViewportClientGunfire;
class ULevel;
class ULevelStreaming;
class UMaterialInterface;
class UMeshComponent;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGameUtil : public UObject {
    GENERATED_BODY()
public:
    UGameUtil();
    UFUNCTION(BlueprintCallable)
    static void XSSCollectGarbageIfNeeded();
    
    UFUNCTION(BlueprintCallable)
    static bool WasComponentRecentlyRenderedOnScreen(UPrimitiveComponent* Component, float Tolerance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TestLineOfSightFromLocation(FVector Origin, AActor* To, const TArray<AActor*>& IgnoredActors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TestLineOfSight(AActor* From, AActor* To, const TArray<AActor*>& IgnoredActors);
    
    UFUNCTION(BlueprintCallable)
    static bool TestFOV(AActor* Source, const FVector& TargetLocation, float FOV);
    
    UFUNCTION(BlueprintCallable)
    static bool TagsAreEqual(const TArray<FName>& Tags1, const TArray<FName>& Tags2);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepSphereAgainstActor(AActor* Actor, const FVector& Start, const FVector& End, float Radius, bool bTraceComplex, TEnumAsByte<ECollisionChannel> TraceChannel, FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SweepCharacterAgainstGround(const UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, float DrawTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SweepCharacter(const UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, const TArray<TEnumAsByte<ECollisionChannel>>& IgnoreChannels, const TArray<TEnumAsByte<ECollisionChannel>>& OverlapChannels, const TArray<TEnumAsByte<ECollisionChannel>>& BlockChannels, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, bool bMoveCharacter, float DrawTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StuckCheckForClass(const UObject* WorldContextObject, FVector FeetLocation, TSubclassOf<ACharacter> CharacterClass, const TArray<AActor*>& IgnoredActors, float RadiusOverride);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StuckCheck(const UObject* WorldContextObject, FVector FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, float RadiusOverride);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StopForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FName Tag, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StopCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> CameraShake, bool bSkipBlendOut, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static void StartPIESession();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static APawn* SpawnAIEx(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail, ELevelContextFallback LevelContextFallback, AActor* LevelContext, bool bDeferSpawning);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* SpawnActorEx(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandling, AActor* Owner, APawn* Instigator, bool Transient, ELevelContextFallback LevelContextFallback, AActor* LevelContext, ULevel* OverrideLevel, bool bDeferSpawning);
    
    UFUNCTION(BlueprintCallable)
    static void SortObjectArray(UPARAM(Ref) TArray<UObject*>& Objects, const FObjectArraySortPredicate& Predicate);
    
    UFUNCTION(BlueprintCallable)
    static void SortIntArray(UPARAM(Ref) TArray<int32>& IntArray);
    
    UFUNCTION(BlueprintCallable)
    static void SortFloatArray(UPARAM(Ref) TArray<float>& FloatArray);
    
    UFUNCTION(BlueprintCallable)
    static void SortActorArrayByDistance(FVector Location, UPARAM(Ref) TArray<AActor*>& ActorArray);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SnapToNavMesh(UObject* WorldContextObject, const FVector& Position, float Radius, FVector& SnappedPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool SnapToGround(UObject* WorldContextObject, const FVector& Position, FVector& SnappedPosition, float Offset, float CastDistance, bool TraceComplex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SnapCharacterToGround(ACharacter* Character, const FVector& Position, const TArray<AActor*>& IgnoredActors, float Offset, float CastDistance);
    
    UFUNCTION(BlueprintCallable)
    static void ShowRandomMesh(AActor* Actor, FName Slot, bool AllowNone);
    
    UFUNCTION(BlueprintCallable)
    static void ShowComponents(TArray<USceneComponent*> Components);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisualStateForComponent(USceneComponent* SceneRoot, FName VisualState, bool PlayTransitions);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisualState(AActor* Actor, FName VisualState, bool PlayTransitions);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisible(AActor* Actor, bool Visible);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisibilityFlag(AActor* Actor, bool Active);
    
    UFUNCTION(BlueprintCallable)
    static void SetTickableWhenPaused(AActor* Actor, bool TickWhenPaused);
    
    UFUNCTION(BlueprintCallable)
    static void SetRenderCustomDepthForActor(AActor* Actor, bool bEnabled, uint8 Index, bool bPropagateToInventory);
    
    UFUNCTION(BlueprintCallable)
    static void SetRecursiveSceneComponentStatus(USceneComponent* Component, bool Visibility, bool MatchActivatedStateToVisibility);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialVectorParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialScalarParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialVectorParamForAll(UPrimitiveComponent* Component, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialVectorParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialScalarParamForAll(UPrimitiveComponent* Component, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialScalarParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllMaterialsTo(AActor* Actor, UMaterialInterface* Material, UPARAM(Ref) TArray<FCachedMaterialState>& CachedMaterialStates, bool RecurseChildren, bool bDisableNanite);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorsVisible(TArray<AActor*> Actors, bool Visible);
    
    UFUNCTION(BlueprintCallable)
    static void SetActive(AActor* Actor, bool Active);
    
    UFUNCTION(BlueprintCallable)
    static void ResetCachedMaterials(const TArray<FCachedMaterialState>& MaterialStates);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveTag(AActor* Actor, FName Tag);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveLevelInstanceByName(UObject* WorldContextObject, const FString& UniqueInstanceName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RemoveLevelInstance(UObject* WorldContextObject, ULevelStreaming* LevelInstance);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, bool bIgnoreTimeDilation, FName Tag, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> CameraShake, float Scale, ECameraShakePlaySpace PlaySpace, FRotator UserPlaySpaceRot, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static void LatentDestroyActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsVisible(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool IsValidTeleportDestination(const UObject* WorldContextObject, const FVector& FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, bool bValidateFloor, float FlatSurfaceDistance, float RadiusOverride, float BackwardsRadiusScale, float DebugDrawTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimmingUnderwater(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimmingOnSurface(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimming(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSoftDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsSingleplayerGame(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsShippingBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPlayingCinematic(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPIEActive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPC();
    
    UFUNCTION(BlueprintCallable)
    static bool IsLocallyControlled(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInWater(const ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInEditor();
    
    UFUNCTION(BlueprintCallable)
    static bool IsHDREnabled();
    
    UFUNCTION(BlueprintCallable)
    static bool IsActorInPersistentLevel(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FVector InvokeVectorGetter(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static int32 InvokeIntegerGetter(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static double InvokeFloatGetter(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static void InvokeEvent(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static bool InvokeCondition(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<USceneComponent*> HideVisibleComponents(AActor* Actor, TSubclassOf<USceneComponent> ComponentClass, bool RecurseChildren, const TArray<TSoftClassPtr<AActor>>& IgnoreClasses);
    
    UFUNCTION(BlueprintCallable)
    static bool GetWaterSubmergeDepth(AActor* Actor, float& OutSubmergeDepth);
    
    UFUNCTION(BlueprintCallable)
    static EVideoDeviceVendor GetVideoDeviceVendor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetScriptStack();
    
    UFUNCTION(BlueprintCallable)
    static FName GetPrefix(const FName& Name);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<APlayerState*> GetPlayerStates(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<APlayerController*> GetPlayerControllers(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APlayerController* GetPlayerControllerFromPlayerState(APlayerState* PlayerState);
    
    UFUNCTION(BlueprintCallable)
    static APlayerController* GetPlayerControllerForActorComponent(UActorComponent* ActorComponent);
    
    UFUNCTION(BlueprintCallable)
    static APlayerController* GetPlayerControllerForActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ACharacter* GetOwningCharacter(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetOwner(UObject* Object);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static int32 GetNumConnectedPlayers(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool GetNodeTransform(const AActor* Actor, const FName& NodeName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetMyHitItem(const FHitResult& Hit, int32& MyHitItem);
    
    UFUNCTION(BlueprintCallable)
    static ELocalizationLanguage GetLocalizationLanguage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ALevelScriptActor* GetLevelScriptActor(ULevel* Level);
    
    UFUNCTION(BlueprintCallable)
    static FString GetLevelPathName(ULevel* Level);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ULevelStreaming* GetLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName);
    
    UFUNCTION(BlueprintCallable)
    static ULevel* GetLevelForActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UGameViewportClientGunfire* GetGameViewport(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AGameModeBase* GetGameMode(AActor* Actor);
    
    UFUNCTION(BlueprintPure)
    static int64 GetFrameCounter();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentPlatformVRam();
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* GetComponentByTag(AActor* Actor, const FName& Tag);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* GetComponentByName(AActor* Actor, const FName& NodeName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetClosestUnblockedPointBetweenActors(const AActor* Target, const AActor* Source, TEnumAsByte<ECollisionChannel> TraceChannel, TEnumAsByte<ECollisionChannel> CollisionChannel, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static float GetClosestPointInCharacterMesh(const ACharacterGunfire* Character, const FVector& Point, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static float GetClosestPointInActor(const AActor* Actor, const FVector& Point, TEnumAsByte<ECollisionChannel> TraceChannel, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static EBuildType GetBuildType();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetBuildNumber();
    
    UFUNCTION(BlueprintCallable)
    static AActor* GetBestWaterBounds(AActor* Actor, bool bConstrainToFluidFilled);
    
    UFUNCTION(BlueprintCallable)
    static EBasePlatform GetBasePlatform();
    
    UFUNCTION(BlueprintCallable)
    static bool GetAttachSocketName(USceneComponent* Mesh, FName& OutSocketName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetActorsWithTagEx(const UObject* WorldContextObject, FName Tag, TArray<AActor*>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetActorsInShape(const UObject* WorldContextObject, const FVector& Position, const FActorQueryShapeDetails& ShapeDetails, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetActorsInRangeEx(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetActorsInRange(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<AActor*>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetActorsInBox(const UObject* WorldContextObject, const FVector& Position, const FVector& MinExtents, const FVector& MaxExtents, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults);
    
    UFUNCTION(BlueprintCallable)
    static void GetActorBoundsSafe(AActor* Actor, bool bOnlyCollidingComponents, FVector& Origin, FVector& Extents);
    
    UFUNCTION(BlueprintCallable)
    static void ForceGarbageCollection();
    
    UFUNCTION(BlueprintCallable)
    static AActor* FinishSpawningDeferredActor(AActor* Actor, const FTransform& SpawnTransform);
    
    UFUNCTION(BlueprintCallable)
    static bool FindTeleportPositionNear(AActor* Actor, float Distance, FVector& OutPosition, bool InFOVOnly);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static APlayerStart* FindPlayerStart(UObject* WorldContextObject, const FName& PlayerStartTag);
    
    UFUNCTION(BlueprintCallable)
    static UMeshComponent* FindMeshWithSocket(AActor* Actor, FName SocketName);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesPathIntersectWithBounds(const ACharacterGunfire* Character, const FVector& Origin, const FVector& Extents);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DoesGameHaveFocus(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void CustomError(AActor* ErrorContext, const FString& Message);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CharacterHasWindowOrTag(ACharacterGunfire* Character, FName Requirement);
    
    UFUNCTION(BlueprintCallable)
    static void CenterViewportCursor(const APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FVector CalculateTraversableTeleportLocation(const UObject* WorldContextObject, ACharacter* Character, FVector AimStart, FVector AimEnd, const TArray<TEnumAsByte<ETraceTypeQuery>>& AdditionalChannels, float AimObstacleTolerance, float GroundDistance, float CliffTolerance, bool bConstrainToLedges, float ProbeDistance, float StuckCheckHeightOffset, float FlatSurfaceDistance, bool bDebugDraw);
    
    UFUNCTION(BlueprintCallable)
    static float CalculateCharacterGroundSlope(const ACharacter* Character, float MoveHeading);
    
    UFUNCTION(BlueprintCallable)
    static void AddTag(AActor* Actor, FName Tag);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ULevelStreaming* AddLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, bool BlockOnLoad, bool ShouldBeLoaded, bool ShouldBeVisible, TSubclassOf<ULevelStreaming> LevelStreamingOverride);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* AddComponent(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, FName Name, FName AttachSocketName, USceneComponent* AttachParent, EAttachmentRule AttachRule, bool bWeldSimulatedBodies, FVector RelativeLocation, FRotator RelativeRotation, bool bSkipAttachment);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSceneComponents(AActor* Actor, FName Slot, FName Tag, bool ActivateChildren, bool UseVisibility, bool InvertActive);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSceneComponent(USceneComponent* SceneComponent, bool Active, bool ActivateChildren, bool UseVisibility);
    
};

