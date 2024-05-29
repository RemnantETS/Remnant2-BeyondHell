#include "ItemType.h"
#include "Templates/SubclassOf.h"

void UItemType::SortQueryResults(const TArray<UInventoryComponent*>& Inventories, TArray<FItemQueryResult>& Results, const TArray<EItemQuerySortMethod>& SortMethods)  {
}

TArray<FItemQueryResult> UItemType::QueryRelevantItemsEx(const TArray<UInventoryComponent*>& Inventories, const FItemQueryFilter& Filter, TArray<EItemQuerySortMethod> SortMethods)  {
    return TArray<FItemQueryResult>();
}

TArray<FItemQueryResult> UItemType::QueryRelevantItems(const TArray<UInventoryComponent*>& Inventories, const FItemQueryFilter& Filter, EItemQuerySortMethod SortMethod)  {
    return TArray<FItemQueryResult>();
}

TArray<UInventoryComponent*> UItemType::GetRelevantInventoriesForType(AActor* Actor, TSubclassOf<UItemType> Type) {
    return TArray<UInventoryComponent*>();
}

UItemType::UItemType() {
    this->BaseType = NULL;
    this->ItemStats = NULL;
    this->CharacterStats = NULL;
    this->Icon = NULL;
    this->SortPriority = -1;
}

