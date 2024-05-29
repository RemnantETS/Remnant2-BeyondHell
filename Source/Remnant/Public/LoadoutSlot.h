#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Conditions.h"
#include "HierarchicalEditInterface.h"
#include "LoadoutSlot.generated.h"

class ACharacterGunfire;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class REMNANT_API ULoadoutSlot : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    ULoadoutSlot();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldLoadSlot(ACharacterGunfire* Character) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRecordLevelForEntry(ACharacterGunfire* Character, int32 RecordIndex, int32 EntryIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumEntriesForSlot(ACharacterGunfire* Character, int32 RecordIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftClassPtr<UObject> GetDisplayClassForEntry(ACharacterGunfire* Character, int32 RecordIndex, int32 EntryIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftClassPtr<UObject> GetDispalyClass(ACharacterGunfire* Character, int32 RecordIndex) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

