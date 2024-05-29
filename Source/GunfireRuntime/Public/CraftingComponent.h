#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/LatentActionManager.h"
#include "ERecipeType.h"
#include "RecipeInfo.h"
#include "CraftingComponent.generated.h"

class AActor;
class AItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UCraftingComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RecipeTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<ERecipeType> ClientPrevRequestedLoads;
    
public:
    UCraftingComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void UpgradeItem(AActor* Source, int32 ItemId, FGuid RecipeID);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseRecipes();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void NotifyClientOnLoadRecipes();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void LoadRecipesOnServer(AActor* Source, ERecipeType Type);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRecipesOfType(AActor* Source, ERecipeType Type);
    
    UFUNCTION(BlueprintCallable)
    bool HasAvailableUpgrades(const TArray<FName>& Tags);
    
    UFUNCTION(BlueprintCallable)
    bool HasAvailableRecipes(const TArray<FName>& Tags);
    
    UFUNCTION(BlueprintCallable)
    bool GetUpgrade(AActor* Source, int32 ItemId, FRecipeInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRecipeInfo> GetRecipesWithIngredient(AActor* Source, TSoftClassPtr<AItem> Ingredient, ERecipeType Type, int32 IngredientLevelRequirement);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRecipeInfo> GetRecipesForItem(AActor* Source, TSoftClassPtr<AItem> Item, ERecipeType Type, int32 ItemLevelRequirement);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    void GetRecipes(AActor* Source, ERecipeType Type, TArray<FRecipeInfo>& Recipes, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable)
    FRecipeInfo GetRecipeInfo(AActor* Source, FGuid RecipeID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void DowngradeItem(AActor* Source, int32 ItemId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void CraftItem(AActor* Source, FGuid RecipeID);
    
    UFUNCTION(BlueprintCallable)
    bool CanDowngrade(AActor* Source, int32 ItemId, FRecipeInfo& OutDowngradeInfo);
    
};

