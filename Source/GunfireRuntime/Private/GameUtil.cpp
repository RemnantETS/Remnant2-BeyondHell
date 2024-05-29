#include "GameUtil.h"
#include "Templates/SubclassOf.h"

void UGameUtil::XSSCollectGarbageIfNeeded() {
}

bool UGameUtil::WasComponentRecentlyRenderedOnScreen(UPrimitiveComponent* Component, float Tolerance) {
    return false;
}

bool UGameUtil::TestLineOfSightFromLocation(FVector Origin, AActor* To, const TArray<AActor*>& IgnoredActors) {
    return false;
}

bool UGameUtil::TestLineOfSight(AActor* From, AActor* To, const TArray<AActor*>& IgnoredActors) {
    return false;
}

bool UGameUtil::TestFOV(AActor* Source, const FVector& TargetLocation, float FOV) {
    return false;
}

bool UGameUtil::TagsAreEqual(const TArray<FName>& Tags1, const TArray<FName>& Tags2) {
    return false;
}

bool UGameUtil::SweepSphereAgainstActor(AActor* Actor, const FVector& Start, const FVector& End, float Radius, bool bTraceComplex, TEnumAsByte<ECollisionChannel> TraceChannel, FHitResult& Hit) {
    return false;
}

bool UGameUtil::SweepCharacterAgainstGround(const UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, float DrawTime) {
    return false;
}

bool UGameUtil::SweepCharacter(const UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, const TArray<TEnumAsByte<ECollisionChannel>>& IgnoreChannels, const TArray<TEnumAsByte<ECollisionChannel>>& OverlapChannels, const TArray<TEnumAsByte<ECollisionChannel>>& BlockChannels, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, bool bMoveCharacter, float DrawTime) {
    return false;
}

bool UGameUtil::StuckCheckForClass(const UObject* WorldContextObject, FVector FeetLocation, TSubclassOf<ACharacter> CharacterClass, const TArray<AActor*>& IgnoredActors, float RadiusOverride) {
    return false;
}

bool UGameUtil::StuckCheck(const UObject* WorldContextObject, FVector FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, float RadiusOverride) {
    return false;
}

void UGameUtil::StopForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FName Tag, int32 PlayerIndex) {
}

void UGameUtil::StopCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> CameraShake, bool bSkipBlendOut, int32 PlayerIndex) {
}

void UGameUtil::StartPIESession() {
}

APawn* UGameUtil::SpawnAIEx(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail, ELevelContextFallback LevelContextFallback, AActor* LevelContext, bool bDeferSpawning) {
    return NULL;
}

AActor* UGameUtil::SpawnActorEx(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandling, AActor* Owner, APawn* Instigator, bool Transient, ELevelContextFallback LevelContextFallback, AActor* LevelContext, ULevel* OverrideLevel, bool bDeferSpawning) {
    return NULL;
}

void UGameUtil::SortObjectArray(TArray<UObject*>& Objects, const FObjectArraySortPredicate& Predicate) {
}

void UGameUtil::SortIntArray(TArray<int32>& IntArray) {
}

void UGameUtil::SortFloatArray(TArray<float>& FloatArray) {
}

void UGameUtil::SortActorArrayByDistance(FVector Location, TArray<AActor*>& ActorArray) {
}

bool UGameUtil::SnapToNavMesh(UObject* WorldContextObject, const FVector& Position, float Radius, FVector& SnappedPosition) {
    return false;
}

bool UGameUtil::SnapToGround(UObject* WorldContextObject, const FVector& Position, FVector& SnappedPosition, float Offset, float CastDistance, bool TraceComplex) {
    return false;
}

bool UGameUtil::SnapCharacterToGround(ACharacter* Character, const FVector& Position, const TArray<AActor*>& IgnoredActors, float Offset, float CastDistance) {
    return false;
}

void UGameUtil::ShowRandomMesh(AActor* Actor, FName Slot, bool AllowNone) {
}

void UGameUtil::ShowComponents(TArray<USceneComponent*> Components) {
}

void UGameUtil::SetVisualStateForComponent(USceneComponent* SceneRoot, FName VisualState, bool PlayTransitions) {
}

void UGameUtil::SetVisualState(AActor* Actor, FName VisualState, bool PlayTransitions) {
}

void UGameUtil::SetVisible(AActor* Actor, bool Visible) {
}

void UGameUtil::SetVisibilityFlag(AActor* Actor, bool Active) {
}

void UGameUtil::SetTickableWhenPaused(AActor* Actor, bool TickWhenPaused) {
}

void UGameUtil::SetRenderCustomDepthForActor(AActor* Actor, bool bEnabled, uint8 Index, bool bPropagateToInventory) {
}

void UGameUtil::SetRecursiveSceneComponentStatus(USceneComponent* Component, bool Visibility, bool MatchActivatedStateToVisibility) {
}

void UGameUtil::SetMaterialVectorParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetMaterialScalarParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, float Value) {
}

void UGameUtil::SetComponentMaterialVectorParamForAll(UPrimitiveComponent* Component, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetComponentMaterialVectorParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetComponentMaterialScalarParamForAll(UPrimitiveComponent* Component, const FName& ParamName, float Value) {
}

void UGameUtil::SetComponentMaterialScalarParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, float Value) {
}

void UGameUtil::SetAllMaterialsTo(AActor* Actor, UMaterialInterface* Material, TArray<FCachedMaterialState>& CachedMaterialStates, bool RecurseChildren, bool bDisableNanite) {
}

void UGameUtil::SetActorsVisible(TArray<AActor*> Actors, bool Visible) {
}

void UGameUtil::SetActive(AActor* Actor, bool Active) {
}

void UGameUtil::ResetCachedMaterials(const TArray<FCachedMaterialState>& MaterialStates) {
}

void UGameUtil::RemoveTag(AActor* Actor, FName Tag) {
}

void UGameUtil::RemoveLevelInstanceByName(UObject* WorldContextObject, const FString& UniqueInstanceName) {
}

void UGameUtil::RemoveLevelInstance(UObject* WorldContextObject, ULevelStreaming* LevelInstance) {
}

void UGameUtil::PlayForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, bool bIgnoreTimeDilation, FName Tag, int32 PlayerIndex) {
}

void UGameUtil::PlayCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> CameraShake, float Scale, ECameraShakePlaySpace PlaySpace, FRotator UserPlaySpaceRot, int32 PlayerIndex) {
}

void UGameUtil::LatentDestroyActor(AActor* Actor) {
}

bool UGameUtil::IsVisible(AActor* Actor) {
    return false;
}

bool UGameUtil::IsValidTeleportDestination(const UObject* WorldContextObject, const FVector& FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, bool bValidateFloor, float FlatSurfaceDistance, float RadiusOverride, float BackwardsRadiusScale, float DebugDrawTime) {
    return false;
}

bool UGameUtil::IsSwimmingUnderwater(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsSwimmingOnSurface(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsSwimming(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsSoftDestroyed(AActor* Actor) {
    return false;
}

bool UGameUtil::IsSingleplayerGame(const UObject* WorldContextObject) {
    return false;
}

bool UGameUtil::IsShippingBuild() {
    return false;
}

bool UGameUtil::IsPlayingCinematic(const UObject* WorldContextObject) {
    return false;
}

bool UGameUtil::IsPIEActive() {
    return false;
}

bool UGameUtil::IsPC() {
    return false;
}

bool UGameUtil::IsLocallyControlled(AActor* Actor) {
    return false;
}

bool UGameUtil::IsInWater(const ACharacter* Character) {
    return false;
}

bool UGameUtil::IsInEditor() {
    return false;
}

bool UGameUtil::IsHDREnabled() {
    return false;
}

bool UGameUtil::IsActorInPersistentLevel(AActor* Actor) {
    return false;
}

FVector UGameUtil::InvokeVectorGetter(UObject* Object, FName EventName) {
    return FVector{};
}

int32 UGameUtil::InvokeIntegerGetter(UObject* Object, FName EventName) {
    return 0;
}

double UGameUtil::InvokeFloatGetter(UObject* Object, FName EventName) {
    return 0.0;
}

void UGameUtil::InvokeEvent(UObject* Object, FName EventName) {
}

bool UGameUtil::InvokeCondition(UObject* Object, FName EventName) {
    return false;
}

TArray<USceneComponent*> UGameUtil::HideVisibleComponents(AActor* Actor, TSubclassOf<USceneComponent> ComponentClass, bool RecurseChildren, const TArray<TSoftClassPtr<AActor>>& IgnoreClasses) {
    return TArray<USceneComponent*>();
}

bool UGameUtil::GetWaterSubmergeDepth(AActor* Actor, float& OutSubmergeDepth) {
    return false;
}

EVideoDeviceVendor UGameUtil::GetVideoDeviceVendor() {
    return EVideoDeviceVendor::UNKNOWN;
}

FString UGameUtil::GetScriptStack() {
    return TEXT("");
}

FName UGameUtil::GetPrefix(const FName& Name) {
    return NAME_None;
}

TArray<APlayerState*> UGameUtil::GetPlayerStates(const UObject* WorldContextObject) {
    return TArray<APlayerState*>();
}

TArray<APlayerController*> UGameUtil::GetPlayerControllers(const UObject* WorldContextObject) {
    return TArray<APlayerController*>();
}

APlayerController* UGameUtil::GetPlayerControllerFromPlayerState(APlayerState* PlayerState) {
    return NULL;
}

APlayerController* UGameUtil::GetPlayerControllerForActorComponent(UActorComponent* ActorComponent) {
    return NULL;
}

APlayerController* UGameUtil::GetPlayerControllerForActor(AActor* Actor) {
    return NULL;
}

ACharacter* UGameUtil::GetOwningCharacter(AActor* Actor) {
    return NULL;
}

UObject* UGameUtil::GetOwner(UObject* Object) {
    return NULL;
}

int32 UGameUtil::GetNumConnectedPlayers(const UObject* WorldContextObject) {
    return 0;
}

bool UGameUtil::GetNodeTransform(const AActor* Actor, const FName& NodeName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace) {
    return false;
}

void UGameUtil::GetMyHitItem(const FHitResult& Hit, int32& MyHitItem) {
}

ELocalizationLanguage UGameUtil::GetLocalizationLanguage() {
    return ELocalizationLanguage::en;
}

ALevelScriptActor* UGameUtil::GetLevelScriptActor(ULevel* Level) {
    return NULL;
}

FString UGameUtil::GetLevelPathName(ULevel* Level) {
    return TEXT("");
}

ULevelStreaming* UGameUtil::GetLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName) {
    return NULL;
}

ULevel* UGameUtil::GetLevelForActor(AActor* Actor) {
    return NULL;
}

UGameViewportClientGunfire* UGameUtil::GetGameViewport(const UObject* WorldContextObject) {
    return NULL;
}

AGameModeBase* UGameUtil::GetGameMode(AActor* Actor) {
    return NULL;
}

int64 UGameUtil::GetFrameCounter() {
    return 0;
}

int32 UGameUtil::GetCurrentPlatformVRam() {
    return 0;
}

UActorComponent* UGameUtil::GetComponentByTag(AActor* Actor, const FName& Tag) {
    return NULL;
}

UActorComponent* UGameUtil::GetComponentByName(AActor* Actor, const FName& NodeName) {
    return NULL;
}

bool UGameUtil::GetClosestUnblockedPointBetweenActors(const AActor* Target, const AActor* Source, TEnumAsByte<ECollisionChannel> TraceChannel, TEnumAsByte<ECollisionChannel> CollisionChannel, FVector& OutClosestPoint) {
    return false;
}

float UGameUtil::GetClosestPointInCharacterMesh(const ACharacterGunfire* Character, const FVector& Point, FVector& OutClosestPoint) {
    return 0.0f;
}

float UGameUtil::GetClosestPointInActor(const AActor* Actor, const FVector& Point, TEnumAsByte<ECollisionChannel> TraceChannel, FVector& OutClosestPoint) {
    return 0.0f;
}

EBuildType UGameUtil::GetBuildType() {
    return EBuildType::Debug;
}

int32 UGameUtil::GetBuildNumber() {
    return 0;
}

AActor* UGameUtil::GetBestWaterBounds(AActor* Actor, bool bConstrainToFluidFilled) {
    return NULL;
}

EBasePlatform UGameUtil::GetBasePlatform() {
    return EBasePlatform::Unknown;
}

bool UGameUtil::GetAttachSocketName(USceneComponent* Mesh, FName& OutSocketName) {
    return false;
}

void UGameUtil::GetActorsWithTagEx(const UObject* WorldContextObject, FName Tag, TArray<AActor*>& OutResults) {
}

void UGameUtil::GetActorsInShape(const UObject* WorldContextObject, const FVector& Position, const FActorQueryShapeDetails& ShapeDetails, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults) {
}

void UGameUtil::GetActorsInRangeEx(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults) {
}

void UGameUtil::GetActorsInRange(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<AActor*>& OutResults) {
}

void UGameUtil::GetActorsInBox(const UObject* WorldContextObject, const FVector& Position, const FVector& MinExtents, const FVector& MaxExtents, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults) {
}

void UGameUtil::GetActorBoundsSafe(AActor* Actor, bool bOnlyCollidingComponents, FVector& Origin, FVector& Extents) {
}

void UGameUtil::ForceGarbageCollection() {
}

AActor* UGameUtil::FinishSpawningDeferredActor(AActor* Actor, const FTransform& SpawnTransform) {
    return NULL;
}

bool UGameUtil::FindTeleportPositionNear(AActor* Actor, float Distance, FVector& OutPosition, bool InFOVOnly) {
    return false;
}

APlayerStart* UGameUtil::FindPlayerStart(UObject* WorldContextObject, const FName& PlayerStartTag) {
    return NULL;
}

UMeshComponent* UGameUtil::FindMeshWithSocket(AActor* Actor, FName SocketName) {
    return NULL;
}

bool UGameUtil::DoesPathIntersectWithBounds(const ACharacterGunfire* Character, const FVector& Origin, const FVector& Extents) {
    return false;
}

bool UGameUtil::DoesGameHaveFocus(UObject* WorldContextObject) {
    return false;
}

void UGameUtil::CustomError(AActor* ErrorContext, const FString& Message) {
}

bool UGameUtil::CharacterHasWindowOrTag(ACharacterGunfire* Character, FName Requirement) {
    return false;
}

void UGameUtil::CenterViewportCursor(const APlayerController* PlayerController) {
}

FVector UGameUtil::CalculateTraversableTeleportLocation(const UObject* WorldContextObject, ACharacter* Character, FVector AimStart, FVector AimEnd, const TArray<TEnumAsByte<ETraceTypeQuery>>& AdditionalChannels, float AimObstacleTolerance, float GroundDistance, float CliffTolerance, bool bConstrainToLedges, float ProbeDistance, float StuckCheckHeightOffset, float FlatSurfaceDistance, bool bDebugDraw) {
    return FVector{};
}

float UGameUtil::CalculateCharacterGroundSlope(const ACharacter* Character, float MoveHeading) {
    return 0.0f;
}

void UGameUtil::AddTag(AActor* Actor, FName Tag) {
}

ULevelStreaming* UGameUtil::AddLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, bool BlockOnLoad, bool ShouldBeLoaded, bool ShouldBeVisible, TSubclassOf<ULevelStreaming> LevelStreamingOverride) {
    return NULL;
}

UActorComponent* UGameUtil::AddComponent(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, FName Name, FName AttachSocketName, USceneComponent* AttachParent, EAttachmentRule AttachRule, bool bWeldSimulatedBodies, FVector RelativeLocation, FRotator RelativeRotation, bool bSkipAttachment) {
    return NULL;
}

void UGameUtil::ActivateSceneComponents(AActor* Actor, FName Slot, FName Tag, bool ActivateChildren, bool UseVisibility, bool InvertActive) {
}

void UGameUtil::ActivateSceneComponent(USceneComponent* SceneComponent, bool Active, bool ActivateChildren, bool UseVisibility) {
}

UGameUtil::UGameUtil() {
}

