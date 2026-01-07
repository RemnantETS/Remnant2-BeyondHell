// Copyright Epic Games, Inc. All Rights Reserved.

#include "HierarchicalNodeEditor.h"
#include "TypeAction/HierarchicalEditAssetAction.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "FHierarchicalNodeEditorModule"

void FHierarchicalNodeEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IAssetTools& AssetToolsModule = IAssetTools::Get();
	EAssetTypeCategories::Type AssetType = AssetToolsModule.RegisterAdvancedAssetCategory(FName(TEXT("HierarchicalEditAsset")), FText::FromString("Hierarchical Edit Assets"));
	TSharedPtr<FHierarchicalEditAssetAction> HierarchicalEditAssetAction = MakeShareable(new FHierarchicalEditAssetAction(AssetType));
	AssetToolsModule.RegisterAssetTypeActions(HierarchicalEditAssetAction.ToSharedRef());
}

void FHierarchicalNodeEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHierarchicalNodeEditorModule, HierarchicalNodeEditor)