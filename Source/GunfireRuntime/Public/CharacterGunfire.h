#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "Engine/HitResult.h"
#include "ActiveRagdollInfo.h"
#include "CinematicInterface.h"
#include "DamageEvadeEventDelegateDelegate.h"
#include "DamageEventDelegateDelegate.h"
#include "DamageInfo.h"
#include "DamageSourceInterface.h"
#include "DamageableInterface.h"
#include "EDeadReason.h"
#include "EDecalReceiverType.h"
#include "EventDelegateDelegate.h"
#include "EventHandlerInterface.h"
#include "FocusChangedDelegateDelegate.h"
#include "HealingEventDelegateDelegate.h"
#include "ImpactDescriptorCharacterSet.h"
#include "InspectInfo.h"
#include "InspectStat.h"
#include "OnDeadDelegateDelegate.h"
#include "OnFactionChangeDelegateDelegate.h"
#include "OnHealthChangedDelegateDelegate.h"
#include "OnHealthRegenDelegateDelegate.h"
#include "OnTargetChangedDelegateDelegate.h"
#include "OnTargetedDelegateDelegate.h"
#include "ReplicatedDamageInfo.h"
#include "SpawnRelevanceInfo.h"
#include "SpectateChangeEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "WeaponPhantomInfo.h"
#include "CharacterGunfire.generated.h"

class AActor;
class ACharacterGunfire;
class AItem;
class APlayerControllerGunfire;
class UActionComponent;
class UCharacterManager;
class UDamageTypeGunfire;
class UDataTable;
class UFaction;
class UHitLogComponent;
class UInventoryComponent;
class UObject;
class UPrimitiveComponent;
class UReplicatedMovementComponent;
class USkeletalMeshComponent;
class UStatInfoSet;
class UStateMachineComponent;
class UStatsComponent;
class UWeaponPhantomComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ACharacterGunfire : public ACharacter, public IDamageableInterface, public IDamageSourceInterface, public IEventHandlerInterface, public ICinematicInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActionComponent* ActionComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponPhantomComponent* WeaponPhantomProviderComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitLogComponent* HitLogComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReplicatedMovementComponent* ReplicatedMovementComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle CapData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDataTable*> AdditionalStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStatInfoSet* InspectStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFaction> Faction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DefaultDamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FImpactDescriptorCharacterSet ImpactDescriptorSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalFootImpactOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveRagdollInfo ActiveRagdollInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDecalReceiverType ReceiveDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NetNotifyHitTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> AggroGroupStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName SpawnState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnRelevanceInfo SpawnRelevanceInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FName> InitialCharacterTags;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Health, meta=(AllowPrivateAccess=true))
    float HealthNormalized;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetChangedDelegate OnTargetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetedDelegate OnTargeted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateChangeEvent OnSpectatorAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateChangeEvent OnSpectatorRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFactionChangeDelegate OnFactionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyHitTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyTargetResistedHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealingEventDelegate OnNotifyHealedTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealingEventDelegate OnNotifyHealFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyTakeDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealingEventDelegate OnNotifyHealed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEvadeEventDelegate OnNotifyEvadeDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageEventDelegate OnNotifyBlockDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthChangedDelegate OnNotifyHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHealthRegenDelegate OnNotifyHealthRegen;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeadDelegate OnPreDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeadDelegate OnDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventDelegate OnEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFocusChangedDelegate OnViewportFocusEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableCharacterOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableAnimOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableAnimSignificanceOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSignificanceScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SuspendClothWhenNotVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UpdateRateDistanceMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationHalfHeightInflation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationRadiusInflation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveNetRepReferencesOnDestroy;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStateMachineComponent* CachedStateMachine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInventoryComponent* CachedInventory;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator ViewRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Target, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* CharacterTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* AimTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* DeathCauseActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerControllerGunfire* OldController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMeshComponent*> SkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseClothSimulationOnTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetAnimDynamicsOnResumeClothingSim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClothSimulationPauseThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCharacterManager* CharacterManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AItem>> ConsumedEntitlements;
    
public:
    ACharacterGunfire();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StopWeaponPhantom(UPrimitiveComponent* Shape);
    
    UFUNCTION(BlueprintCallable)
    void StopAllWeaponPhantoms();
    
    UFUNCTION(BlueprintCallable)
    void StartWeaponPhantom(UPARAM(Ref) FWeaponPhantomInfo& PhantomInfo);
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponPhantomsSuspended(bool bIsSuspended);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* Character);
    
    UFUNCTION(BlueprintCallable)
    void SetRagdollFXEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetOldController(APlayerControllerGunfire* OldControllerIn);
    
    UFUNCTION(BlueprintCallable)
    void SetIsTargetable(bool Targetable);
    
    UFUNCTION(BlueprintCallable)
    void SetHealth(float Health);
    
    UFUNCTION(BlueprintCallable)
    void SetFaction(TSubclassOf<UFaction> NewFaction);
    
    UFUNCTION(BlueprintCallable)
    void SetCooldown(FName Cooldown, float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetAllNamesCooldown(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetAimTarget(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetAimTarget(AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue);
    
    UFUNCTION(BlueprintCallable)
    void RestoreAggroGroup(FName PreviousAggroGroup, bool bRemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void ResetHealth(bool bResetHitLocations);
    
    UFUNCTION(BlueprintCallable)
    void ResetCooldown(FName Cooldown);
    
    UFUNCTION(BlueprintCallable)
    void ResetClothingSimulation(bool FullReset);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllNamesCooldown();
    
    UFUNCTION(BlueprintCallable)
    void RemoveTag(const FName& Tag, bool bRemoveAll);
    
    UFUNCTION(BlueprintCallable)
    void ReinitializeCloth();
    
    UFUNCTION(BlueprintCallable)
    bool ReduceCooldown(FName Cooldown, float Time);
    
    UFUNCTION(BlueprintCallable)
    void Ragdoll(const FName RootBoneName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Target(AActor* PreviousTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Health();
    
    UFUNCTION(BlueprintCallable)
    void OnRagdollHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocallyControlled();
    
    UFUNCTION(BlueprintCallable)
    void OnGameViewportFocusChanged(bool HasFocus);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterStateChanged(const FName& StateName, const FName& PreviousStateName);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnCharacterDead(EDeadReason Reason, AActor* Cause);
    
    UFUNCTION(BlueprintCallable)
    void ModifyStat(FName Stat, float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void MarkActorHit(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWounded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSceneCaptureCharacter() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsEditor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCinematicCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlive() const;
    
    UFUNCTION(BlueprintCallable)
    void HitPause(float Duration, float Dilation, float EaseInTime, float EaseOutTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    bool HasRecentlyHitActor(UObject* WorldContextObject, UPrimitiveComponent* Shape, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetViewRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStateMachineComponent* GetStateMachine() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerControllerGunfire* GetOldController() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIsTargetable();
    
    UFUNCTION(BlueprintCallable)
    FInspectStat GetInspectStatInfo(const FName& Stat);
    
    UFUNCTION(BlueprintCallable)
    FInspectInfo GetInspectInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthMax() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetEyeViewPointOverride(UPARAM(Ref) FVector& Location, UPARAM(Ref) FRotator& Rotation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetExtraNotifyTargetsForHit(const FDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    FString GetDebugInfo(int32 DebugLevel);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCooldownTotalDuration(FName Cooldown) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCooldownPct(FName Cooldown) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetCharacterInventory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetAimTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAggroGroup();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FilterIncomingDamage(const FDamageInfo& DamageInfo, float& DamageOut, bool& ShouldApplyDamage);
    
    UFUNCTION(BlueprintCallable)
    void EnableClothingSimulation();
    
    UFUNCTION(BlueprintCallable)
    void DisableClothingSimulation();
    
    UFUNCTION(BlueprintCallable)
    void ConsumeEntitlement(TSoftClassPtr<AItem> Entitlement);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyTargetResistedHit(const FReplicatedDamageInfo& RepDamageInfo);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyTakeDamage(AActor* Source, float Damage, int32 Power);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyHitEvents(const TArray<FReplicatedDamageInfo>& RepDamageInfos);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientApplyKnockback(float ImpactHeading, float KnockBackImpulse, float KnockUpImpulse);
    
    UFUNCTION(BlueprintCallable)
    void ClearAggroGroup();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckTags(const TArray<FName>& TagsToCheck, bool AllOrNothing) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckTag(FName Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckCooldown(FName Cooldown) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreWeaponPhantomsSuspended() const;
    
    UFUNCTION(BlueprintCallable)
    bool AreCharacterOptimizationsEnabled();
    
    UFUNCTION(BlueprintCallable)
    void ApplyHealthDelta(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void AddTag(const FName& Tag);
    
    UFUNCTION(BlueprintCallable)
    void AddAggroGroup(FName NewAggroGroup, bool bUniqueOnly);
    
    
    // Fix for true pure virtual functions not being implemented
};

