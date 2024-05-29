#include "CraftingRecipe.h"

void UCraftingRecipe::OnItemLoaded(AActor* Owner, UInventoryComponent* Inventory) {
}

UCraftingRecipe::UCraftingRecipe() {
    this->ItemLevel = 0;
    this->ItemQuantity = 1;
    this->SharedCraftedItem = false;
    this->MatchToHighestLevelIngredient = false;
}

