#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LoadoutRecord.h"
#include "LoadoutRecordEntry.h"
#include "LoadoutTemplateSlot.h"
#include "OnLoadoutLoadedDelegate.h"
#include "OnLoadoutsUpdatedDelegate.h"
#include "LoadoutComponent.generated.h"

class ULoadoutSlot;
class ULoadoutTemplate;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API ULoadoutComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoadoutUpdateDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LoadoutCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoadoutCooldownDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLoadoutTemplateSlot> Slots;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadoutLoaded OnLoadoutLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadoutsUpdated OnLoadoutCommitted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLoadoutsUpdated OnLoadoutCleared;
    
    ULoadoutComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePendingLoadout();
    
public:
    UFUNCTION(BlueprintCallable)
    bool SetDisplayNameForLoadout(ULoadoutTemplate* Loadout, int32 Index, const FText& NewDisplayName);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerLoadLoadout(const FLoadoutRecord& ClientRecord);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveObjectClassFromLoadouts(TSoftClassPtr<UObject> DeprecatedClass);
    
    UFUNCTION(BlueprintCallable)
    bool LoadLoadout(ULoadoutTemplate* Loadout, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    bool IsLoadoutEquipped(ULoadoutTemplate* Loadout, int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadingLoadout() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRecord(ULoadoutTemplate* Loadout, int32 Index, bool bHasAnyEntries) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxRecordsForTemplate(ULoadoutTemplate* Loadout) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEntryForLoadoutSlot(ULoadoutTemplate* Loadout, int32 Index, ULoadoutSlot* Slot, FLoadoutRecordEntry& Entry) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetDisplayNameForLoadout(ULoadoutTemplate* Loadout, int32 Index) const;
    
    UFUNCTION(BlueprintCallable)
    bool CommitLoadout(ULoadoutTemplate* Loadout, int32 Index);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientPostLoadLoadout(ULoadoutTemplate* Loadout);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ClearLoadout(ULoadoutTemplate* Loadout, int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanLoadLoadout() const;
    
};

