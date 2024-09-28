#pragma once
#include "CoreMinimal.h"
#include "EquipmentMod.h"
#include "InspectInfo.h"
#include "EPrismSegmentCategory.h"
#include "FeedRatios.h"
#include "PotentialRoll.h"
#include "PrismStone.generated.h"

class AActor;
class UConditionList;
class UCurveFloat;
class UDataTable;
class UObject;
class UStatInfoSet;

UCLASS(Blueprintable)
class REMNANT_API APrismStone : public AEquipmentMod {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* PrismStoneTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* MythicPrismStoneTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelUpRollsToChooseFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSegments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSegmentLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MythicMaxSegmentLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BonusSegmentsWhenConditionsMet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* BonusSegmentsRequirementsToRoll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* MythicSegmentsRequirementsToRoll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultExpRequiredPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RequiredExperienceInc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RequiredExperienceExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredExperienceRound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MythicExpRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ExperienceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxLevelForNormalizedCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ExperienceCurveIsNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinalExpCurveRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeedDefaultExpGiven;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeedExperienceInc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeedExperienceExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FeedExperienceRound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FeedWeightCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FeedMaxLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FeedExperienceCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FeedExperienceCurveIsNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeedFinalCurveExpGiven;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    //TArray<FItemQuantity> ItemsToConsumeOnFlush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* StoneFeedConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* PlayerFeedConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* StoneFlushConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* PlayerFlushConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* StoneRemoveSegmentsConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* PlayerRemoveSegmentsConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* StoneComboBypassConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* PlayerComboBypassConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStatInfoSet* InspectStats;
    
public:
    APrismStone(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UIAddSegmentToPrismByNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetHasRolled(bool Rolled);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerGenerateStartSeed();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerFlushPrismStone(bool RemoveSegments, bool RemovePendingExp, bool RemoveFeedData, bool RemoveStoredLevels);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerFeedGemData(FName FeedNameID, int32 GemLevelFed);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerAddSegmentToPrismByNameID(FName NameID, int32 ModifiedSeed);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputePrismStats();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSegmentActionLoaded(FName SegmentNameID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnExperience(int32 Experience);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyIncomingExperience(UPARAM(Ref) int32& Experience);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMythicSegmentByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsComboSegmentByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSegmentWithNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMythicSegment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEmptySlots();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBeenFed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSegmentRarityByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSegmentMaxLevelByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSegmentLevelByNameID(FName NameID, int32& OutLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPrismSegmentCategory GetSegmentCategoryByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProgressToNextLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProgressToNextExperienceLevel();
    
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
    float GetMaxFeedBonus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLeftOverExperience();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FInspectInfo GetInspectInfoFromNameID(FName NameID, int32 InspectLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFeedBonusForNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFeedBonusForFeedLevel(int32 FeedLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFeedBonusAsRatioOfMaxForNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFeedBonusAsPercentForNameID(FName NameID, AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExperienceRequiredForLevel(int32 TargetLevel);
    
    UFUNCTION(BlueprintCallable)
    float GetExperienceGainFromFeedLevel(int32 GemLevelFed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetDataObjectForNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentMaxSegments();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UObject*> GetAllSegmentDataObjects() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FFeedRatios> GetAllFeedBonusAsRatioOfMax(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> DetermineLevelUpRolls(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable)
    bool ConsumeExperienceForLevel(int32 TargetLevel);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputePrismStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanRoll();
    
    UFUNCTION(BlueprintCallable)
    bool CanRemoveSegments();
    
    UFUNCTION(BlueprintCallable)
    bool CanFlushStone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeFed(bool CheckForPendingRoll);
    
    UFUNCTION(BlueprintCallable)
    void AddExperience(float Experience);
    
};

