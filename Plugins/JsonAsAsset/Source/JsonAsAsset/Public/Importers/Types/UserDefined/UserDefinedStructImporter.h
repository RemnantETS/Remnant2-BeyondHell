/* Copyright JsonAsAsset Contributors 2024-2025 */

#pragma once

#include "Importers/Constructor/Importer.h"
#include "Engine/UserDefinedStruct.h"

class IUserDefinedStructImporter : public IImporter {
public:
	IUserDefinedStructImporter(const FString& AssetName, const FString& FilePath, const TSharedPtr<FJsonObject>& JsonObject, UPackage* Package, UPackage* OutermostPkg, const TArray<TSharedPtr<FJsonValue>>& AllJsonObjects, UClass* AssetClass):
		IImporter(AssetName, FilePath, JsonObject, Package, OutermostPkg, AllJsonObjects, AssetClass) {
	}

	virtual bool Import() override;

protected:
	TSharedPtr<FJsonObject> CookedStructMetaData;
	TSharedPtr<FJsonObject> DefaultProperties;

	FEdGraphPinType ResolvePropertyPinType(const TSharedPtr<FJsonObject>& PropertyJsonObject);
	void ImportPropertyIntoStruct(UUserDefinedStruct* UserDefinedStruct, const TSharedPtr<FJsonObject>& PropertyJsonObject);
	UObject* LoadObjectFromJsonReference(const TSharedPtr<FJsonObject>& ParentJsonObject, const FString& ReferenceKey);
};

REGISTER_IMPORTER(IUserDefinedStructImporter, {
	TEXT("UserDefinedStruct")
}, "User Defined Assets");
