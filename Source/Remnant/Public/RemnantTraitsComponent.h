#pragma once
#include "CoreMinimal.h"
#include "TraitInfo.h"
#include "TraitsComponent.h"
#include "ETraitSortProperty.h"
#include "Templates/SubclassOf.h"
#include "TraitSortPriorityField.h"
#include "RemnantTraitsComponent.generated.h"

class UDataTable;
class UTrait;
class UTraitType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantTraitsComponent : public UTraitsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ArchetypeNameTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTypeForSortPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSortPropertyGreatestToLeast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETraitSortProperty TraitPropertySort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTraitType> ArchetypeTraitType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTraitSortPriorityField> TraitSortType;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> CachedSortedTraitList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTraitInfo> OwnedArchetypeTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UTrait>> ArchetypeAddedTraits;
    
public:
    URemnantTraitsComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInitializing() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipmentTrait(FTraitInfo TraitInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsArchetypeAppliedTrait(FTraitInfo TraitInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTraitProgress(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    TArray<FTraitInfo> GetSortedTraitList();
    
    UFUNCTION(BlueprintCallable)
    TArray<FTraitInfo> GetCustomSortedTraitList(UDataTable* TraitSortTable);
    
    UFUNCTION(BlueprintCallable)
    FText GetArchetypeNameForCombo(TSoftClassPtr<UTrait> ArchetypeA, TSoftClassPtr<UTrait> ArchetypeB);
    
protected:
    UFUNCTION(BlueprintCallable)
    void CheckOnTraitUpdated(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    void CheckOnTraitRemoved(TSubclassOf<UTrait> TraitBP);
    
    UFUNCTION(BlueprintCallable)
    void CheckOnTraitLevelChanged(TSubclassOf<UTrait> TraitBP, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void CheckOnTraitAdded(TSubclassOf<UTrait> TraitBP);
    
};

