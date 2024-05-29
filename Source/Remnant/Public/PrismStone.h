#pragma once
#include "CoreMinimal.h"
#include "Conditions.h"
#include "EquipmentMod.h"
#include "InspectInfo.h"
#include "PotentialRoll.h"
#include "PrismStone.generated.h"

class AActor;
class UCurveFloat;
class UDataTable;
class UObject;

UCLASS(Blueprintable)
class REMNANT_API APrismStone : public AEquipmentMod {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* PrismStoneTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelUpRollsToChooseFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSegments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BonusSegmentsForNoFeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultExpRequiredPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ExperienceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSegmentLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions StoneRemoveSegmentsConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions PlayerRemoveSegmentsConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions StoneComboBypassConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions PlayerComboBypassConditions;
    
public:
    APrismStone();
    UFUNCTION(BlueprintCallable)
    void RemoveSegmentByName(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllSegments();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputePrismStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSegmentWithNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEmptySlots();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBeenFed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSegmentLevelByNameID(FName NameID, int32& OutLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProgressToNextLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPrismStoneLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPrismStoneExperienceLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FPotentialRoll> GetPossibleRollsFor(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSegments();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumEmptySlots();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNameIDForSegment(int32 SegmentIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNameIDForObject(TSoftObjectPtr<UObject> SoftObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxPossibleSegments();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FInspectInfo GetInspectInfoFromNameID(FName NameID, int32 InspectLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExperienceRequiredForLevel(int32 TargetLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetDataObjectForNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentMaxSegments();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UObject*> GetAllSegmentDataObjects() const;
    
    UFUNCTION(BlueprintCallable)
    void FeedGemData(FName FeedNameID, int32 GemLevelFed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> DetermineLevelUpRolls(AActor* TargetActor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputePrismStats();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanRemoveSegments();
    
    UFUNCTION(BlueprintCallable)
    bool AddSegmentToPrismByNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    void AddExperience(float Experience);
    
};

