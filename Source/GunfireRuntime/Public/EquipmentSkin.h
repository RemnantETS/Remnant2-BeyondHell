#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "EquipmentSkin.generated.h"

class AEquipment;
class AEquipmentSkin;
class UInventoryComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipmentSkin : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AEquipment> EquipmentBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualID;
    
    AEquipmentSkin(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static bool IsSkinEquipped(UInventoryComponent* Inventory, int32 SkinID);
    
    UFUNCTION(BlueprintCallable)
    static TArray<int32> GetSkinsForItem(UInventoryComponent* Inventory, int32 ItemId);
    
    UFUNCTION(BlueprintCallable)
    static AEquipmentSkin* GetSkinForBP(UInventoryComponent* Inventory, TSoftClassPtr<AEquipment> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    static void EquipSkin(UInventoryComponent* Inventory, int32 ItemId, int32 SkinID);
    
};

