#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "AimableInterface.h"
#include "CustomWeaponSpread.h"
#include "EHandedness.h"
#include "ERangedWeaponTrajectoryMode.h"
#include "OnCurrentAmmoChangedDelegate.h"
#include "OnFireDelegateDelegate.h"
#include "OnMaxAmmoChangedDelegate.h"
#include "OnReloadDelegateDelegate.h"
#include "ProjectileVisualizationContext.h"
#include "RangedWeaponMode.h"
#include "RangedWeaponModeInterface.h"
#include "ReplicatedHits.h"
#include "ReplicatedLocation.h"
#include "SoundGunfire.h"
#include "Templates/SubclassOf.h"
#include "WeaponBase.h"
#include "WeaponTracePath.h"
#include "RangedWeapon.generated.h"

class AActor;
class AItem;
class AProjectileBase;
class UAimingComponent;
class UInputAction;
class UNiagaraSystem;
class USceneComponent;
class UVitalityComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ARangedWeapon : public AWeaponBase, public IRangedWeaponModeInterface, public IAimableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponMode DefaultWeaponMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FireWhileAimingOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowActionOnFlinch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProjectileSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProjectileAssetToVisualize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> AmmoType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AmmoPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnlimitedAmmoForAICharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* FireInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* ReloadInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ReloadOnRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowAutoReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* AimInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireTagForAiming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* ScopeInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* DoubleClickScopeInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumAimTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FireInputBufferDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCameraWhenAimingWithScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraRelativeScopeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputAction* AimScopeInputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomWeaponSpread CustomSpread;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool WeaponDoesHitScanOnFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimScopeTag;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiresInHandToUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadLoopTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadEndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MuzzleAttachPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachMuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutOfAmmoSoundIDName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire OutOfAmmoSoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLowAmmoSounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LowAmmoCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire BulletWhizBySoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletWhizByRadius;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReloadDelegate OnFired;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReloadDelegate OnReload;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFireDelegate OnAdvanceFireState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMaxAmmoChanged OnMaxAmmoChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrentAmmoChanged OnCurrentAmmoChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RightOrientationAttachment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeftOrientationAttachment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseAltOrientAttachOnReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVitalityComponent* AmmoPoolComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* Muzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAimingComponent* AimingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRangedWeaponMode OverrideWeaponMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AProjectileBase*> FiredProjectiles;
    
public:
    ARangedWeapon(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerSoundAwareness(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void ToggleScopeInput(bool bRequiresAimInput);
    
    UFUNCTION(BlueprintCallable)
    void SetProjectileToVisualize(TSubclassOf<AActor> NewProjectileClass);
    
    UFUNCTION(BlueprintCallable)
    void SetOverrideWeaponMode(const FRangedWeaponMode& Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomUserState(bool InCustomUserState);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomUserSecondaryState(bool InCustomUserSecondaryState);
    
    UFUNCTION(BlueprintCallable)
    void SetClipAmount(int32 Amount);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetState(uint8 InState);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFireWithWindup(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, float ClientWindupTime);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFireWithCameraTransform(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFireWithAllData(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed, FVector_NetQuantize CameraLocation, FRotator CameraRotation, float ClientWindupTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerFireCustomReloadNotifications();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerFire(FVector_NetQuantize From, const FReplicatedHits& ClientHits, float WeaponSpread, uint32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAmmoFromClip(int32 Ammo);
    
    UFUNCTION(BlueprintCallable)
    void Reload();
    
public:
    UFUNCTION(BlueprintCallable)
    void PlayMuzzleFX(UNiagaraSystem* WeaponMuzzleFX, bool Attach);
    
    UFUNCTION(BlueprintCallable)
    void PlayFireAnimation(FName AnimationID);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindupOverdrawBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindupFull();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindupEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindupBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReloading();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnScopeInputPressed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReloaded();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFire(const FVector& From, const FVector& To, float WeaponSpread);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishReloading();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitCustomUserState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitCustomUserSecondaryState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEquipEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEquipBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterCustomUserState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterCustomUserSecondaryState();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDoubleClickScopeInputReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnDoubleClickScopeInputPressed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChangeHandedness(EHandedness Handedness);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetStateNS(uint8 InState);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetState(uint8 InState);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastFire(FVector_NetQuantize From, const FReplicatedLocation& To, float WeaponSpread, uint32 RandomSeed);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyMuzzleFXPointAndDirection(UPARAM(Ref) FVector& MuzzlePoint, UPARAM(Ref) FVector& MuzzleDirection, int32 SprayIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyMuzzleFX(UPARAM(Ref) FName& MuzzleFXName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWindupOverdrawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWindingUp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingToggleAimInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsScopeInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReloading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCustomUserState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCustomUserSecondaryState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFiring() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBusy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAimInputDown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAimingWithScope() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAiming() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    static void InitializeWeaponMode(UPARAM(Ref) FRangedWeaponMode& InWeaponMode, AActor* InterfaceObject);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasScope() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInfiniteReserve() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInfiniteClip() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetWindupTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWindupRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetWindupProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetWindupOverdrawProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRangedWeaponMode GetWeaponMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalWindup() const;
    
    UFUNCTION(BlueprintCallable)
    float GetTotalFireLength(FName AnimationID, int32& SeedOut);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetStateName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSprayCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScopeFOV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRateOfFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange(bool bIncludeFalloff) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRandomStream GetRandomStream();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProjectileVisualizationContext GetProjectileVisualization() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOverdrawTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNormalizedSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetMuzzleObstruction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMuzzleFXPointAndDirection(FVector& MuzzlePoint, FVector& MuzzleDirection, int32 SprayIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxAmmo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetFirstNonPiercedAimTarget(bool bInitialSegmentOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFalloff(bool bPrimaryFalloffOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageScalar(float Distance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBurstRateOfFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBurstCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FSoundGunfire GetBulletWhizBySound() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoPerReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoPerClip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmoInClip() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmmo() const;
    
    UFUNCTION(BlueprintCallable)
    void GetAimVector(FVector& From, FVector& To, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAimTargetLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetAimTarget(bool bInitialSegmentOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FWeaponTracePath GetAimPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAimingComponent* GetAimingComponent() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void ForceReload(bool FireReloadNotifications);
    
    UFUNCTION(BlueprintCallable)
    void ForceIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ForceFullReload();
    
public:
    UFUNCTION(BlueprintCallable)
    AActor* FireProjectile(AActor* Cause, const FVector& Origin, const FVector& End, float WeaponSpread, TSubclassOf<AActor> ProjectileBP, float Velocity);
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishEquip();
    
public:
    UFUNCTION(BlueprintCallable)
    void FillClip(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void EndUse();
    
    UFUNCTION(BlueprintCallable)
    void DoInstantHit(const FVector& Origin, const FVector& End, float WeaponSpread);
    
    UFUNCTION(BlueprintCallable)
    void DoImpact(const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool DoCustomReload(bool& FireReloadNotifications);
    
    UFUNCTION(BlueprintCallable)
    void ConsumeAmmo(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void ClearOverrideWeaponMode();
    
    UFUNCTION(BlueprintCallable)
    void ClearDoubleClickTimer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanWindup(float& PercentComplete) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanFireEndAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanFire() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void CancelWindup();
    
    UFUNCTION(BlueprintCallable)
    void CancelReload();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAutoReload() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginUse();
    
    UFUNCTION(BlueprintCallable)
    void BeginReload();
    
    UFUNCTION(BlueprintCallable)
    void ApplySpread(float Scalar);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyRecoil(float Scalar);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddAmmoToClip(int32 Ammo, bool bIsReload);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddAmmo(int32 Amount, bool NewFillClip);
    

    // Fix for true pure virtual functions not being implemented
};

