#include "CraftingRecipe_Base.h"

UCraftingRecipe_Base::UCraftingRecipe_Base() {
    this->Type = ERecipeType::Craft;
    this->Ingredient1Quantity = 1;
    this->Ingredient1LevelRequirement = 0;
    this->bIngredient1HideIfMissing = false;
    this->bIngredient1SecretIfMissing = false;
    this->Ingredient1DeconstructAmount = 1.00f;
    this->Ingredient2Quantity = 1;
    this->Ingredient2LevelRequirement = 0;
    this->bIngredient2HideIfMissing = false;
    this->bIngredient2SecretIfMissing = false;
    this->Ingredient2DeconstructAmount = 1.00f;
    this->Ingredient3Quantity = 1;
    this->Ingredient3LevelRequirement = 0;
    this->bIngredient3HideIfMissing = false;
    this->bIngredient3SecretIfMissing = false;
    this->Ingredient3DeconstructAmount = 1.00f;
    this->Ingredient4Quantity = 1;
    this->Ingredient4LevelRequirement = 0;
    this->bIngredient4HideIfMissing = false;
    this->bIngredient4SecretIfMissing = false;
    this->Ingredient4DeconstructAmount = 1.00f;
}

