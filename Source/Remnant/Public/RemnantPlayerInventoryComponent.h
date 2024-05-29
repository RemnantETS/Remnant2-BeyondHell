#pragma once
#include "CoreMinimal.h"
#include "PlayerInventoryComponent.h"
#include "OnWeaponModUsedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "RemnantPlayerInventoryComponent.generated.h"

class AActor;
class AEquipment;
class AItem;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantPlayerInventoryComponent : public UPlayerInventoryComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoTransferWeaponMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> LimitInitialLevelClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> EquipmentVisualsSlotTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> NullReferenceReplacementClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWeaponModUsedDelegate OnUseMod;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AItem>, TSubclassOf<UItemType>> ItemTypeOverrideMap;
    
public:
    URemnantPlayerInventoryComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveItemTypeOverride(TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    void RemoveItemsOnDeath();
    
    UFUNCTION(BlueprintCallable)
    int32 ModifyLevelForNewItem(TSubclassOf<AItem> ItemBP, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetLevelForNewItem(AActor* Actor, TSubclassOf<AItem> ItemBP, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquippedItemByType(const TSubclassOf<UItemType> Type) const;
    
    UFUNCTION(BlueprintCallable)
    void AddItemTypeOverride(TSubclassOf<AItem> ItemBP, TSubclassOf<UItemType> Type);
    
};

