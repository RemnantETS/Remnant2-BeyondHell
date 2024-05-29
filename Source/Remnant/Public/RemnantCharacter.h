#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DialogInitiatorInterface.h"
#include "PlayerGunfire.h"
#include "PersistenceKey.h"
#include "EGender.h"
#include "GunObstructionParameters.h"
#include "OnAggroEventDelegate.h"
#include "OnAimEventDelegate.h"
#include "OnPossessedByDelegate.h"
#include "PersistentBuff.h"
#include "Templates/SubclassOf.h"
#include "RemnantCharacter.generated.h"

class AActor;
class ACharacterGunfire;
class ACheckpoint;
class ARangedWeapon;
class ASpawnPoint;
class UActionBuff;
class UActorCustomizationComponent;
class UActorCustomizationSet;
class UAnimInstance;
class UDamageClass;
class UEmotesComponent;
class UGameUserSettingsGunfire;
class UItemType;
class URemnantPlayerInventoryComponent;
class USavedCharacter;
class USkeletalMesh;
class UUserSetting;

UCLASS(Blueprintable)
class REMNANT_API ARemnantCharacter : public APlayerGunfire, public IDialogInitiatorInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorCustomizationComponent* Customization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URemnantPlayerInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEmotesComponent* Emotes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> FemaleAnimInstanceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* FemaleSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorCustomizationSet* FemaleCustomizationSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EGender Gender;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPossessedBy OnPossessedBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bHasAggro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bHasCloseAggro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacterGunfire*> ProxyAggroCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=UpdatePlayerInfoTags, meta=(AllowPrivateAccess=true))
    int32 ControllerIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastUsedItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentPlayerInfoTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentPlayerGenderTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShowHelmet, meta=(AllowPrivateAccess=true))
    bool ShowHelmet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HelmetSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShowHelmetOption;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GrabbedCheckpoint, meta=(AllowPrivateAccess=true))
    ACheckpoint* GrabbedCheckpoint;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> PrimaryWeaponType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObstructedAdditionalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObstructedAdditionalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters StandingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters StandingExtentParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters CrouchingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters CrouchExtentParameters;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAimEvent OnAimChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAggroEvent OnAggroChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Deactivated, meta=(AllowPrivateAccess=true))
    bool bDeactivated;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FPersistentBuff> PersistentBuffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyExitDialogFromHostileDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bManualIgnoreDamageExitingDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UDamageClass>> ExitDialogDamageClasses;
    
    ARemnantCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UpdatePlayerInfoTags();
    
    UFUNCTION(BlueprintCallable)
    void UpdatePersistentBuffs();
    
    UFUNCTION(BlueprintCallable)
    void TeleportToSpawnPoint(AActor* SpawnPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnPoint(ASpawnPoint* SpawnPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetHelmetShown(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetGrabbedCheckpoint(ACheckpoint* NewCheckpoint);
    
    UFUNCTION(BlueprintCallable)
    void SetDeactivated();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetHelmetShown(bool bShow);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetAmmoInClip();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 RequestPowerLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 RequestArchetypeLevel() const;
    
    UFUNCTION(BlueprintCallable)
    void RemovePersistentBuff(const UActionBuff* Buff);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAggroProxyCharacter(ACharacterGunfire* Character);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnShowHelmetOptionChanged(UUserSetting* AppliedSetting, UGameUserSettingsGunfire* UserSettings);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRespawnAfterDeath();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ShowHelmet();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_GrabbedCheckpoint(ACheckpoint* Previous);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Deactivated();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCharacterDied(uint8 Reason, ACharacterGunfire* Character, AActor* Cause);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnArchetypeRevoked();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReviving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    
    UFUNCTION(BlueprintCallable)
    void InitializePersistentBuffs();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HasUnlockedSecondaryArchetype() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthClampMod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARangedWeapon* GetCurrentRangedWeapon() const;
    
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetCharacterInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 ComputePowerLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ComputeOffenseLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 ComputeItemLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ComputeEquipmentLevel(FName Tag, int32 HighestItemLevelWeight) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ComputeDefenseLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ComputeArchetypeLevel() const;
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientTeleportToSpawnPoint(ASpawnPoint* SpawnPoint);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientTeleport(FTransform Transform);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetSpawnPoint(const FPersistenceKey& SpawnPointID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRemoveAllPings();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastAimEvent(bool Aiming);
    
    UFUNCTION(BlueprintCallable)
    void AddOrUpdatePersistentBuff(const UActionBuff* Buff);
    
    UFUNCTION(BlueprintCallable)
    void AddAggroProxyCharacter(ACharacterGunfire* Character);
    
    
    // Fix for true pure virtual functions not being implemented
};

