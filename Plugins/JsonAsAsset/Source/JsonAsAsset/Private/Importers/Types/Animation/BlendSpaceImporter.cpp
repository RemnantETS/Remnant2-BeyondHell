/* Copyright JsonAsAsset Contributors 2024-2025 */

#include "Importers/Types/Animation/BlendSpaceImporter.h"
#include "Animation/BlendSpace.h"

bool IBlendSpaceImporter::Import() {
#if ENGINE_UE5
	auto BlendSpace = NewObject<UBlendSpace>(Package, AssetClass, *AssetName, RF_Public | RF_Standalone);
#else
	UBlendSpaceBase* BlendSpace = NewObject<UBlendSpaceBase>(Package, AssetClass, *AssetName, RF_Public | RF_Standalone);
#endif
	
	BlendSpace->Modify();
	
	GetObjectSerializer()->DeserializeObjectProperties(AssetData, BlendSpace);

	/* Ensure internal state is refreshed after adding all samples */
	BlendSpace->ValidateSampleData();
	BlendSpace->MarkPackageDirty();
	BlendSpace->PostEditChange();
	BlendSpace->PostLoad();

	return OnAssetCreation(BlendSpace);
}