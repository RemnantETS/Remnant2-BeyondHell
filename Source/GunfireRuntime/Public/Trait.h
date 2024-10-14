#pragma once
#include "CoreMinimal.h"
#include "ActorModifier.h"
#include "EntitlementInterface.h"
#include "Templates/SubclassOf.h"
#include "Trait.generated.h"

class UConditionList;
class UDataTable;
class UEntitlementType;
class UTrait;
class UTraitType;

UCLASS(Blueprintable, Config=Game)
class GUNFIRERUNTIME_API UTrait : public UActorModifier, public IEntitlementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTraitType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* StatTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddIfAlreadyUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubsequentUnlockLevelIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTrait>> RequiredTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* ConditionList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UEntitlementType> RequiredEntitlement;
    
    UTrait();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldApplyStats();
    
    UFUNCTION(BlueprintCallable)
    bool HasModifier(TSubclassOf<UActorModifier> ModifierBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTraitStatValue(FName StatName, int32 TraitLevel);
    
    UFUNCTION(BlueprintCallable)
    void GetModifierBonus(TSubclassOf<UActorModifier> ModifierBP, int32 FromLevel, int32 ToLevel, int32& LevelBonus, int32& MaxLevelBonus);
    

    // Fix for true pure virtual functions not being implemented
};

