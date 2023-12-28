#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "CraftingRecipeList.generated.h"

class UCraftingRecipe_Base;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCraftingRecipeList : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCraftingRecipe_Base*> Recipes;
    
    UCraftingRecipeList();
    
    // Fix for true pure virtual functions not being implemented
};

