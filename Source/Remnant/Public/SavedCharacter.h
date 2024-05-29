#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorCustomizationSlot.h"
#include "PersistenceBlob.h"
#include "AccountAwardInstance.h"
#include "EGender.h"
#include "ELastHostType.h"
#include "ERemnantCharacterType.h"
#include "EntitlementInstance.h"
#include "LoadoutRecord.h"
#include "SavedEquipmentVisual.h"
#include "SavedCharacter.generated.h"

class URemnantArchetype;
class URemnantSaveGameProfile;

UCLASS(Blueprintable)
class REMNANT_API USavedCharacter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TraitRank;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<URemnantArchetype> Archetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<URemnantArchetype> SecondaryArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool HasInitializedArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bFinishedIntro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSkipIntro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActorCustomizationSlot> Customizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSavedEquipmentVisual> EquipmentCustomizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FActorCustomizationSlot> CachedLastValidCustomizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSavedEquipmentVisual> CachedLastValidEquipmentCustomizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EGender Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ELastHostType HostType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> CharacterBlob;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FPersistenceBlob CharacterData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 QuestDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InitialDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 PowerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ItemLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> Keys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> Counters;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString Name;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ERemnantCharacterType CharacterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDeceased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 BossCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bValidExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InvalidExitCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAccountAwardInstance> ReceivedAwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasHandledCurrencyAward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FEntitlementInstance> EntitledAwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasEntitledArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastSavedTraitPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FLoadoutRecord> LoadoutRecords;
    
    USavedCharacter();
    UFUNCTION(BlueprintCallable)
    void SetSkipIntro(bool ShouldSkipIntro);
    
    UFUNCTION(BlueprintCallable)
    void SetKey(FName Key);
    
    UFUNCTION(BlueprintCallable)
    void SetCharacterType(ERemnantCharacterType NewCharacterType);
    
    UFUNCTION(BlueprintCallable)
    void MarkValidExit();
    
    UFUNCTION(BlueprintCallable)
    void IncrementCounter(FName Counter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRevokedEntitledArchetype(URemnantSaveGameProfile* Profile) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasKey(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCounter(FName Counter);
    
    UFUNCTION(BlueprintCallable)
    void ConditionallyMarkEntitledArchetype(URemnantSaveGameProfile* Profile, TSoftClassPtr<URemnantArchetype> NewArchetype);
    
    UFUNCTION(BlueprintCallable)
    bool CheckForInvalidExit();
    
};

