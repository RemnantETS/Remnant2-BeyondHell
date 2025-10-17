/* Copyright JsonAsAsset Contributors 2024-2025 */

#pragma once

#include "Importers/Constructor/Graph/MaterialGraph.h"

class IMaterialFunctionImporter : public IMaterialGraph {
public:
	IMaterialFunctionImporter(const FString& AssetName, const FString& FilePath, const TSharedPtr<FJsonObject>& JsonObject, UPackage* Package, UPackage* OutermostPkg, const TArray<TSharedPtr<FJsonValue>>& AllJsonObjects, UClass* AssetClass):
		IMaterialGraph(AssetName, FilePath, JsonObject, Package, OutermostPkg, AllJsonObjects, AssetClass) {
	}

	virtual bool Import() override;
};

REGISTER_IMPORTER(IMaterialFunctionImporter, {
	"MaterialFunction"
}, "Material Assets");