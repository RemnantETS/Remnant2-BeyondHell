#include "CraftingComponent.h"

void UCraftingComponent::UpgradeItem_Implementation(AActor* Source, int32 ItemId, FGuid RecipeID) {
}
bool UCraftingComponent::UpgradeItem_Validate(AActor* Source, int32 ItemId, FGuid RecipeID) {
    return true;
}

void UCraftingComponent::ReleaseRecipes() {
}

void UCraftingComponent::NotifyClientOnLoadRecipes_Implementation() {
}

void UCraftingComponent::LoadRecipesOnServer_Implementation(AActor* Source, ERecipeType Type) {
}
bool UCraftingComponent::LoadRecipesOnServer_Validate(AActor* Source, ERecipeType Type) {
    return true;
}

bool UCraftingComponent::HasRecipesOfType(AActor* Source, ERecipeType Type) {
    return false;
}

bool UCraftingComponent::HasAvailableUpgrades(const TArray<FName>& Tags) {
    return false;
}

bool UCraftingComponent::HasAvailableRecipes(const TArray<FName>& Tags) {
    return false;
}

bool UCraftingComponent::GetUpgrade(AActor* Source, int32 ItemId, FRecipeInfo& Info) {
    return false;
}

TArray<FRecipeInfo> UCraftingComponent::GetRecipesWithIngredient(AActor* Source, TSoftClassPtr<AItem> Ingredient, ERecipeType Type, int32 IngredientLevelRequirement) {
    return TArray<FRecipeInfo>();
}

TArray<FRecipeInfo> UCraftingComponent::GetRecipesForItem(AActor* Source, TSoftClassPtr<AItem> Item, ERecipeType Type, int32 ItemLevelRequirement) {
    return TArray<FRecipeInfo>();
}

void UCraftingComponent::GetRecipes(AActor* Source, ERecipeType Type, TArray<FRecipeInfo>& Recipes, FLatentActionInfo LatentInfo) {
}

FRecipeInfo UCraftingComponent::GetRecipeInfo(AActor* Source, FGuid RecipeID) {
    return FRecipeInfo{};
}

void UCraftingComponent::DowngradeItem_Implementation(AActor* Source, int32 ItemId) {
}
bool UCraftingComponent::DowngradeItem_Validate(AActor* Source, int32 ItemId) {
    return true;
}

void UCraftingComponent::CraftItem_Implementation(AActor* Source, FGuid RecipeID) {
}
bool UCraftingComponent::CraftItem_Validate(AActor* Source, FGuid RecipeID) {
    return true;
}

bool UCraftingComponent::CanDowngrade(AActor* Source, int32 ItemId, FRecipeInfo& OutDowngradeInfo) {
    return false;
}

UCraftingComponent::UCraftingComponent() {
}

