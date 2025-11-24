#pragma once

#include "Importers/Constructor/Importer.h"
#include "Engine/SCS_Node.h"
#include "EdGraph/EdGraphPin.h"

#include "Engine/TimelineTemplate.h"

class IBlueprintImporter final : public IImporter {
public:
	IBlueprintImporter(const FString& AssetName, const FString& FilePath, const TSharedPtr<FJsonObject>& JsonObject, UPackage* Package, UPackage* OutermostPkg, const TArray<TSharedPtr<FJsonValue>>& AllJsonObjects, UClass* AssetClass) :
		IImporter(AssetName, FilePath, JsonObject, Package, OutermostPkg, AllJsonObjects, AssetClass),
		Blueprint(nullptr), GeneratedPropertyNames(), GeneratedFunctionNames(), YOffset(4 * 128 + 64), bFailedImport(false), bIsPreExisting(false)
	{
	}

	~IBlueprintImporter() override;

	virtual bool Import() override;

private:
	UBlueprint* CreateBlueprint(UClass* ParentClass) const;

	bool AddTimelineComponent(const TSharedPtr<FJsonObject> ComponentItem);
	void AddTracksToTimeline(UTimelineTemplate* Timeline, TArray<TSharedPtr<FJsonValue>> TrackItems, FTTTrackBase::ETrackType TrackType);

	bool SetupSimpleConstructionScript(const TSharedPtr<FJsonValue> SCSExport);
	USCS_Node* CreateNodeFromNodeItem(const TSharedPtr<FJsonObject> NodeItem, bool bAddToSCS);

	FEdGraphPinType GetPinTypeFromPropertyItem(const TSharedPtr<FJsonObject> PropertyItem, bool* bPropertySubcatObjectFailed);

	bool AddEventToEventGraph(const TSharedPtr<FJsonObject> FunctionExport);
	bool AddFunctionGraph(const TSharedPtr<FJsonObject> FunctionExport, bool bIsDelegateSignature);

	int YOffset;
	void OffsetGraphNode(UEdGraphNode* Node);

	TArray<FString> GeneratedPropertyNames; 
	TArray<FString> GeneratedFunctionNames;

	static EPropertyFlags GetPropertyFlags(TArray<FString> Flags);
	static EFunctionFlags GetFunctionFlags(TArray<FString> Flags);

	bool SetUpDynamicBindings(const TSharedPtr<FJsonObject> DynamicBindings);

protected:
	/* Global Cached data to reuse */
	UBlueprint* Blueprint;

	TSharedPtr<FJsonObject> DefaultObjectProperties;

	bool bIsPreExisting;
	bool bFailedImport;
};

REGISTER_IMPORTER(IBlueprintImporter, (TArray<FString>{
	TEXT("BlueprintGeneratedClass")
}), TEXT("Blueprint Assets"));

