// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "HierarchicalEditAssetAction.h"
#include "HierarchicalEditAsset.h"
#include "Editor/HierarchicalEditAssetApp.h"

FHierarchicalEditAssetAction::FHierarchicalEditAssetAction(EAssetTypeCategories::Type Category)
{
	AssetCategory = Category;
}

FText FHierarchicalEditAssetAction::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_HierachicalEditAsset", "Hierarchical Edit Asset");
}

FColor FHierarchicalEditAssetAction::GetTypeColor() const
{
	return FColor::Green;
}

UClass* FHierarchicalEditAssetAction::GetSupportedClass() const
{
	return UHierarchicalEditAsset::StaticClass();
}

void FHierarchicalEditAssetAction::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	for (UObject* Object : InObjects) {
		UHierarchicalEditAsset* Asset = Cast<UHierarchicalEditAsset>(Object);
		if (Asset != nullptr) {
			TSharedRef<FHierarchicalEditAssetApp> Editor(new FHierarchicalEditAssetApp());
			Editor->InitEditor(Mode, EditWithinLevelEditor, Asset);
		}
	}
}

uint32 FHierarchicalEditAssetAction::GetCategories()
{
	return AssetCategory;
}
