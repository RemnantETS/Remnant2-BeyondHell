#pragma once
#include "CoreMinimal.h"
#include "CraftingRecipe_Base.h"
#include "CraftingRecipe.generated.h"

class AActor;
class AItem;
class UInventoryComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCraftingRecipe : public UCraftingRecipe_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemQuantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ItemTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SharedCraftedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MatchToHighestLevelIngredient;
    
    UCraftingRecipe();
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemLoaded(AActor* Owner, UInventoryComponent* Inventory);
    
};

