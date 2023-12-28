#include "CraftingRecipe_Base.h"

UCraftingRecipe_Base::UCraftingRecipe_Base() {
    this->Type = ERecipeType::Craft;
    this->Ingredient1Quantity = 1;
    this->Ingredient1DeconstructAmount = 0.5f;
    this->Ingredient1LevelRequirement = 0;
    this->bIngredient1HideIfMissing = false;
    this->bIngredient1SecretIfMissing = false;
    this->Ingredient2Quantity = 1;
    this->Ingredient2DeconstructAmount = 0.5f;
    this->Ingredient2LevelRequirement = 0;
    this->bIngredient2HideIfMissing = false;
    this->bIngredient2SecretIfMissing = false;
    this->Ingredient3Quantity = 1;
    this->Ingredient3DeconstructAmount = 0.5f;
    this->Ingredient3LevelRequirement = 0;
    this->bIngredient3HideIfMissing = false;
    this->bIngredient3SecretIfMissing = false;
    this->Ingredient4Quantity = 1;
    this->Ingredient4DeconstructAmount = 0.5f;
    this->Ingredient4LevelRequirement = 0;
    this->bIngredient4HideIfMissing = false;
    this->bIngredient4SecretIfMissing = false;
}

