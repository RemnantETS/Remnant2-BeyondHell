#include "Importers/Types/Blueprint/BlueprintImporter.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Engine/SimpleConstructionScript.h"
#include "EdGraphSchema_K2.h"

#include "K2Node_Timeline.h"

#include "K2Node_Event.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "K2Node_EditablePinBase.h"
#include "K2Node_ComponentBoundEvent.h"

#include "Utilities/JsonUtilities.h"

#include "ObjectTools.h"

const EPropertyFlags RelevantPropertyFlags = CPF_Transient | CPF_DuplicateTransient |
CPF_BlueprintVisible | CPF_BlueprintReadOnly |
CPF_InstancedReference | CPF_ContainsInstancedReference |
CPF_NonTransactional |
CPF_Edit | CPF_DisableEditOnTemplate | CPF_DisableEditOnInstance |
CPF_Parm | CPF_ConstParm | CPF_ReferenceParm | CPF_OutParm |
CPF_Net | CPF_RepNotify;

extern bool GShowBlueprintImporterWarning = true;

IBlueprintImporter::~IBlueprintImporter()
{
	if (!bIsPreExisting && bFailedImport && Blueprint) {
		ObjectTools::DeleteObjects({Blueprint}, false);
	}
}

bool IBlueprintImporter::Import() {
	if (GShowBlueprintImporterWarning) {
		SpawnPrompt("Preface Warning", "None of this is final, this is completely a work in progress with flaws. None of it is perfect. If you find a issue, fix it.\n\nTo remove this warning, go to BlueprintImporter.cpp and set GShowBlueprintImporterWarning to false.");
		GShowBlueprintImporterWarning = false;
	}

	if (Package->GetOuter() != nullptr) {
		FString msg = Package->GetPathName();
		UE_LOG(LogJson, Error, TEXT("Package \"%s\" is not a top level package"), *msg);
		bFailedImport = true;
		return false;
	}
	bool bIsPreExistingBlueprint = false;
	/*
	Blueprint = GetSelectedAsset<UBlueprint>(true);

	//Ignore selected Blueprint if it's named differently
	if (Blueprint) {
		if (!(Blueprint->GetOuter()->GetPathName() == Package->GetPathName()) || !(Blueprint->GetFName() == FName(AssetName))) {
			Blueprint = nullptr;
		}
		else {
			bool bPromptedToFail = false;
			auto SetExitOnRefusal = [&bPromptedToFail](bool bAcceptedOverride) {
				if (!bAcceptedOverride) {
					bPromptedToFail = true;
				}
			};
			SpawnYesNoPrompt("Override Existing", "The blueprint already exists. Do you want to override it?\nThis will result in loss of existing changes.", SetExitOnRefusal);

			if (bPromptedToFail) {
				UE_LOG(LogJson, Log, TEXT("Stopping import attempt as per user request."))
				bFailedImport = true;
				return false;
			}
			bIsPreExisting = true;
		}
	}
	*/

	//Create new blueprint if none exists
	if (!Blueprint) {

		if (FindObject<UBlueprint>(Package, *AssetName, false) != nullptr) {
			UE_LOG(LogJson, Warning, TEXT("Tried to override existing Blueprint."));
			bFailedImport = true;
			return false;
		}


		UClass* ParentClass = nullptr;
		if (AssetData->HasTypedField<EJson::Object>("SuperStruct")) {
			const TSharedPtr<FJsonObject> SuperStruct = AssetData->GetObjectField("SuperStruct");
			ParentClass = LoadClass(SuperStruct);

			if (!ParentClass) {
				UE_LOG(LogJson, Error, TEXT("Unable to load SuperStruct: \"%s\""), *(GetFullPath(SuperStruct)));
				bFailedImport = true;
				return false;
			}
		}
		else if (AssetData->HasTypedField<EJson::Object>("Super")) {
			const TSharedPtr<FJsonObject> SuperClass = AssetData->GetObjectField("Super");
			ParentClass = LoadClass(SuperClass);

			if (!ParentClass) {
				UE_LOG(LogJson, Error, TEXT("Unable to load Super class: \"%s\""), *(GetFullPath(SuperClass)));
				bFailedImport = true;
				return false;
			}
		}
		else {
			UE_LOG(LogJson, Error, TEXT("Neither SuperStruct nor Super class specififed."));
			bFailedImport = true;
			return false;
		}

		Blueprint = CreateBlueprint(ParentClass);
	}

	if (!Blueprint) return false;

	if (AssetData->HasTypedField<EJson::Array>("Interfaces")) {
		if (Blueprint->ImplementedInterfaces.Num()) {
			UE_LOG(LogJson, Warning, TEXT("Clearing existing Interfaces."));
			Blueprint->ImplementedInterfaces.Empty();
		}

		UE_LOG(LogJson, Warning, TEXT("Loading Interfaces."));
		bool bFailedAny = false;
		for (const TSharedPtr<FJsonValue> InterfaceData : AssetData->GetArrayField("Interfaces")) {
			const TSharedPtr<FJsonObject> InterfaceJson = InterfaceData->AsObject();

			const TSharedPtr<FJsonObject> InterfaceClassPath = InterfaceJson->GetObjectField("Class");

			UClass* InterfaceClassObject = LoadClass(InterfaceClassPath);

			if (!InterfaceClassObject) {
				UE_LOG(LogJson, Error, TEXT("Unable to load Interface class: \"%s\""), *(GetFullPath(InterfaceClassPath)));
				bFailedAny = true;
			}

			FBPInterfaceDescription InterfaceDescription;
			InterfaceDescription.Interface = InterfaceClassObject;

			Blueprint->ImplementedInterfaces.Add(InterfaceDescription);
		}
		if (bFailedAny) {
			bFailedImport = true;
			return false;
		}
	}

	if (AssetData->HasTypedField<EJson::Object>("SimpleConstructionScript")) {

		TArray<USCS_Node*> ExistingNodes = Blueprint->SimpleConstructionScript->GetAllNodes();
		if (ExistingNodes.Num()) {
			UE_LOG(LogJson, Log, TEXT("Clearing existing components"));
			for (USCS_Node* Node : ExistingNodes) {
				Blueprint->SimpleConstructionScript->RemoveNode(Node);
			}
		}

		const TSharedPtr<FJsonObject> SCSPath = AssetData->GetObjectField("SimpleConstructionScript");
		const TSharedPtr<FJsonValue> SCSExport = GetExportByObjectPath(SCSPath);
		if (!SetupSimpleConstructionScript(SCSExport)) {
			UE_LOG(LogJson, Warning, TEXT("Failed to setup SCS properly."));
			bFailedImport = true;
			return false;
		}
	}

	if (AssetData->HasTypedField<EJson::Array>("Timelines")) {
		UE_LOG(LogJson, Log, TEXT("Adding timeline components."));
		for (const TSharedPtr<FJsonValue> TimelinePathData : AssetData->GetArrayField("Timelines")) {
			const TSharedPtr<FJsonObject> TimelinePath = TimelinePathData->AsObject();
			const TSharedPtr<FJsonValue> TimelineTemplateItem = GetExportByObjectPath(TimelinePath);
			const TSharedPtr<FJsonObject> TimelineTemplate = TimelineTemplateItem->AsObject();

			AddTimelineComponent(TimelineTemplate);
		}
	}

	if (AssetData->HasTypedField<EJson::Array>("DynamicBindingObjects")) {
		for (const TSharedPtr<FJsonValue> DynBindingObjectPathItem : AssetData->GetArrayField("DynamicBindingObjects")) {
			const TSharedPtr<FJsonObject> DynBindingObjectPath = DynBindingObjectPathItem->AsObject();
			const TSharedPtr<FJsonValue> DynBindingObjectExport = GetExportByObjectPath(DynBindingObjectPath);
			const TSharedPtr<FJsonObject> DynBindingObject = DynBindingObjectExport->AsObject();

			if (!SetUpDynamicBindings(DynBindingObject)) {
				UE_LOG(LogJson, Warning, TEXT("Failed to setup bindings properly."));
				bFailedImport = true;
				return false;
			}
		}
	}

	if (Blueprint->DelegateSignatureGraphs.Num()) {
		UE_LOG(LogJson, Log, TEXT("Clearing existing delegate graphs"));
		Blueprint->DelegateSignatureGraphs.Empty();
	}

	if (AssetData->HasTypedField<EJson::Array>("ChildProperties")) {
		if (Blueprint->NewVariables.Num()) {
			UE_LOG(LogJson, Log, TEXT("Clearing existing member variables."));
			Blueprint->NewVariables.Empty();
		}

		UE_LOG(LogJson, Log, TEXT("Adding member variables."));

		bool bAllPropertySubCatObjectsLoaded = true;
		for (const TSharedPtr<FJsonValue> PropertyData : AssetData->GetArrayField("ChildProperties")) {
			const TSharedPtr<FJsonObject> PropertyJson = PropertyData->AsObject();

			FString PropName = PropertyJson->GetStringField("Name");
			if (GeneratedPropertyNames.Contains(PropName)) {
				continue;
			}

			TArray<FString> PropertyFlags{};
			GetFlagProperty(PropertyJson, "PropertyFlags", PropertyFlags);

			if (PropertyFlags.Contains("Transient")) {
				continue;
			}

			FEdGraphPinType VarType = GetPinTypeFromPropertyItem(PropertyJson, &bAllPropertySubCatObjectsLoaded);

			FName ChildVarName = FName(PropName);
			FBlueprintEditorUtils::AddMemberVariable(Blueprint, ChildVarName, VarType);

			const int32 VarIndex = FBlueprintEditorUtils::FindNewVariableIndex(Blueprint, ChildVarName);

			if (VarIndex != INDEX_NONE) {

				uint64* NewPropertyFlags = FBlueprintEditorUtils::GetBlueprintVariablePropertyFlags(Blueprint, ChildVarName);
				*NewPropertyFlags &= ~RelevantPropertyFlags;

				FBlueprintEditorUtils::SetBlueprintOnlyEditableFlag(Blueprint, ChildVarName, PropertyFlags.Contains("DisableEditOnInstance"));
				FBlueprintEditorUtils::SetBlueprintPropertyReadOnlyFlag(Blueprint, ChildVarName, PropertyFlags.Contains("BlueprintReadOnly"));
				FBlueprintEditorUtils::SetInterpFlag(Blueprint, ChildVarName, PropertyFlags.Contains("Interp"));
				FBlueprintEditorUtils::SetVariableTransientFlag(Blueprint, ChildVarName, PropertyFlags.Contains("Transient"));
				FBlueprintEditorUtils::SetVariableSaveGameFlag(Blueprint, ChildVarName, PropertyFlags.Contains("SaveGame"));
				FBlueprintEditorUtils::SetVariableAdvancedDisplayFlag(Blueprint, ChildVarName, PropertyFlags.Contains("AdvancedDisplay"));
				FBlueprintEditorUtils::SetVariableDeprecatedFlag(Blueprint, ChildVarName, PropertyFlags.Contains("Deprecated"));

				*NewPropertyFlags |= GetPropertyFlags(PropertyFlags);

				if (!(*NewPropertyFlags & CPF_DisableEditOnInstance)) {
					FBlueprintEditorUtils::SetBlueprintVariableMetaData(Blueprint, ChildVarName, nullptr, FBlueprintMetadata::MD_ExposeOnSpawn, "True");
				}

				FBPVariableDescription NewChildVar = Blueprint->NewVariables[VarIndex];
				NewChildVar.RepNotifyFunc = PropertyJson->HasTypedField<EJson::String>("RepNotifyFunc") ? FName(PropertyJson->GetStringField("RepNotifyFunc")) : FName("None");
			}

		}
		if (!bAllPropertySubCatObjectsLoaded) {
			bFailedImport = true;
			return false;
		}
	}

	if (Blueprint->FunctionGraphs.Num()) {
		UE_LOG(LogJson, Log, TEXT("Clearing existing function graphs"));
		Blueprint->FunctionGraphs.Empty();
	}

	TArray<UK2Node_Event*> ExistingEvents;
	FBlueprintEditorUtils::GetAllNodesOfClass<UK2Node_Event>(Blueprint, ExistingEvents);
	if (ExistingEvents.Num()) {
		UE_LOG(LogJson, Log, TEXT("Clearing existing event nodes"));
		for (UK2Node_Event* EventNode : ExistingEvents) {
			FBlueprintEditorUtils::RemoveNode(Blueprint, EventNode, true);
		}
	}


	if (AssetData->HasTypedField<EJson::Array>("Children")) {
		bool bAllFunctionsAdded = true;
		UE_LOG(LogJson, Log, TEXT("Adding functions and events"));
		for (const TSharedPtr<FJsonValue> FunctionExportPathItem : AssetData->GetArrayField("Children")) {
			const TSharedPtr<FJsonObject> FunctionExportPath = FunctionExportPathItem->AsObject();
			const TSharedPtr<FJsonValue> FunctionExportItem = GetExportByObjectPath(FunctionExportPath);
			const TSharedPtr<FJsonObject> FunctionExport = FunctionExportItem->AsObject();

			FString FuncName = FunctionExport->GetStringField("Name");
			if (GeneratedFunctionNames.Contains(FuncName)) {
				continue;
			}

			TArray<FString> FunctionFlags{};
			GetFlagProperty(FunctionExport, "FunctionFlags", FunctionFlags);

			if (FunctionFlags.Contains("FUNC_UbergraphFunction")) {
				continue;
			}

			if (FunctionFlags.Contains("FUNC_Event") ||
				(!FunctionFlags.Contains("FUNC_Private") && !FunctionFlags.Contains("FUNC_Protected") && !FunctionFlags.Contains("FUNC_Public"))) {
				bAllFunctionsAdded &= AddEventToEventGraph(FunctionExport);
			}
			else {
				bAllFunctionsAdded &=  AddFunctionGraph(FunctionExport, false);
			}
		}
		if (!bAllFunctionsAdded) {
			bFailedImport = true;
			return false;
		}
	}

	if (AssetData->HasTypedField<EJson::Object>("ClassDefaultObject")) {
		const TSharedPtr<FJsonObject> DefaultObjectPath = AssetData->GetObjectField("ClassDefaultObject");
		const TSharedPtr<FJsonValue> DefaultObjectItem = GetExportByObjectPath(DefaultObjectPath);
		const TSharedPtr<FJsonObject> DefaultObject = DefaultObjectItem->AsObject();
		const TSharedPtr<FJsonObject> DefaultObjectProps = DefaultObject->GetObjectField("Properties");


		const UBlueprintGeneratedClass* GeneratedClass = Cast<UBlueprintGeneratedClass>(Blueprint->GeneratedClass);

		GObjectSerializer->Exports = AllJsonObjects;
		GObjectSerializer->DeserializeObjectProperties(RemovePropertiesShared(DefaultObjectProps, {
			"RootComponent"
			}), GeneratedClass->GetDefaultObject());
	}

	

	GObjectSerializer->DeserializeObjectProperties(RemovePropertiesShared(AssetData, {
		"SuperStruct",
		"Super",
		"Interfaces",
		"Timelines",
		"FuncMap",
		"ChildProperties",
		"bCooked",
		"Children",
		"UberGraphFunction",
		"UberGraphFramePointerProperty",
		"SimpleConstructionScript",
		"InheritableComponentHandler"
		}), Blueprint);


	FKismetEditorUtilities::CompileBlueprint(
		Blueprint,
		EBlueprintCompileOptions::None
	);

	return OnAssetCreation(Blueprint);

}

UBlueprint* IBlueprintImporter::CreateBlueprint(UClass* ParentClass) const {
	EBlueprintType BlueprintType = BPTYPE_Normal;

	if (ParentClass->HasAnyClassFlags(CLASS_Const)) {
		BlueprintType = BPTYPE_Const;
	}
	if (ParentClass == UBlueprintFunctionLibrary::StaticClass()) {
		BlueprintType = BPTYPE_FunctionLibrary;
	}
	if (ParentClass == UInterface::StaticClass()) {
		BlueprintType = BPTYPE_Interface;
	}

	UBlueprint* Blueprint = FKismetEditorUtilities::CreateBlueprint(ParentClass, Package, FName(*AssetName), BlueprintType, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());

	if (Blueprint != nullptr) {
		return Cast<UBlueprint>(Blueprint);
	}

	return nullptr;
}

bool IBlueprintImporter::AddTimelineComponent(const TSharedPtr<FJsonObject> TimelineTemplate)
{
	const TSharedPtr<FJsonObject> TimelineProps = TimelineTemplate->GetObjectField("Properties");

	FString TimelineName = TimelineProps->GetStringField("VariableName");
	FString TimelineGuid = TimelineProps->GetStringField("TimelineGuid");
	bool bIgnoreTimeDilation = TimelineProps->HasTypedField<EJson::Boolean>("bIgnoreTimeDilation") ? TimelineProps->GetBoolField("bIgnoreTimeDilation") : false;
	float TimelineLength = TimelineProps->GetNumberField("TimelineLength");

	UTimelineTemplate* Timeline = FBlueprintEditorUtils::AddNewTimeline(Blueprint, FName(TimelineName));
	Timeline->TimelineGuid = FGuid(TimelineGuid);
	Timeline->bIgnoreTimeDilation = bIgnoreTimeDilation;
	Timeline->TimelineLength = TimelineLength;

	if (TimelineProps->HasTypedField<EJson::Array>("FloatTracks")) {
		TArray<TSharedPtr<FJsonValue>> FloatTracks = TimelineProps->GetArrayField("FloatTracks");
		AddTracksToTimeline(Timeline, FloatTracks, FTTTrackBase::ETrackType::TT_FloatInterp);
	}

	if (TimelineProps->HasTypedField<EJson::Array>("EventTracks")) {
		TArray<TSharedPtr<FJsonValue>> EventTracks = TimelineProps->GetArrayField("EventTracks");
		AddTracksToTimeline(Timeline, EventTracks, FTTTrackBase::ETrackType::TT_Event);
	}

	if (TimelineProps->HasTypedField<EJson::Array>("VectorTracks")) {
		TArray<TSharedPtr<FJsonValue>> VectorTracks = TimelineProps->GetArrayField("VectorTracks");
		AddTracksToTimeline(Timeline, VectorTracks, FTTTrackBase::ETrackType::TT_VectorInterp);
	}

	if (TimelineProps->HasTypedField<EJson::Array>("LinearColorTracks")) {
		TArray<TSharedPtr<FJsonValue>> LinearColorTracks = TimelineProps->GetArrayField("LinearColorTracks");
		AddTracksToTimeline(Timeline, LinearColorTracks, FTTTrackBase::ETrackType::TT_LinearColorInterp);
	}

	UEdGraph* EventGraph = FBlueprintEditorUtils::FindEventGraph(Blueprint);

	FGraphNodeCreator<UK2Node_Timeline> NodeCreator(*EventGraph);
	UK2Node_Timeline* TimelineNode = NodeCreator.CreateNode();

	TimelineNode->TimelineName = FName(TimelineName);
	TimelineNode->TimelineGuid = FGuid(TimelineGuid);
	TimelineNode->bIgnoreTimeDilation = bIgnoreTimeDilation;

	FString TimelineDirPropertyName = TimelineProps->GetStringField("DirectionPropertyName");
	GeneratedPropertyNames.Add(TimelineDirPropertyName);

	FString UpdateFuncName = TimelineProps->GetStringField("UpdateFunctionName");
	FString FinishFuncName = TimelineProps->GetStringField("FinishedFunctionName");

	GeneratedFunctionNames.Add(UpdateFuncName);
	GeneratedFunctionNames.Add(FinishFuncName);

	OffsetGraphNode(TimelineNode);

	NodeCreator.Finalize();

	return false;
}

void IBlueprintImporter::AddTracksToTimeline(UTimelineTemplate* Timeline, TArray<TSharedPtr<FJsonValue>> TrackItems, FTTTrackBase::ETrackType TrackType)
{
	for (TSharedPtr<FJsonValue> TrackDataItem : TrackItems) {
		TSharedPtr<FJsonObject> TrackData = TrackDataItem->AsObject();

		FString TrackName = TrackData->GetStringField("TrackName");
		if (TrackType == FTTTrackBase::ETrackType::TT_Event) {

		}
		else {
			FString PropertyName = TrackData->GetStringField("PropertyName");
			GeneratedPropertyNames.Add(PropertyName);

			if (TrackType == FTTTrackBase::ETrackType::TT_FloatInterp) {
				FTTFloatTrack FloatTrack{};
				UCurveFloat* NewCurveFloat = NewObject<UCurveFloat>(Blueprint, UCurveFloat::StaticClass());
				FloatTrack.CurveFloat = NewCurveFloat;
				FloatTrack.SetTrackName(FName(TrackName), Timeline);
				FloatTrack.bIsExternalCurve = false;

				Timeline->FloatTracks.Add(FloatTrack);
			}
		}
	}
}

bool IBlueprintImporter::SetupSimpleConstructionScript(const TSharedPtr<FJsonValue> SCSExport) {
	UE_LOG(LogJson, Log, TEXT("Beginning SCS setup"))
	const TSharedPtr<FJsonObject> SCSItem = SCSExport->AsObject();

	const TSharedPtr<FJsonObject> SCS_Properties = SCSItem->GetObjectField("Properties");

	if (SCS_Properties->HasTypedField<EJson::Array>("RootNodes")) {
		UE_LOG(LogJson, Log, TEXT("Iterating over SCS Root Nodes"));
		bool bAnyNodeFailed = false;
		for (const TSharedPtr<FJsonValue> NodePathExport : SCS_Properties->GetArrayField("RootNodes")) {
			const TSharedPtr<FJsonObject> NodePathItem = NodePathExport->AsObject();
			const TSharedPtr<FJsonObject> RootNodeItem = GetExportByObjectPath(NodePathItem)->AsObject();

			USCS_Node* RootNode = CreateNodeFromNodeItem(RootNodeItem, true);

			if (!RootNode) {
				bAnyNodeFailed = true;
			}
		}

		if (bAnyNodeFailed) {
			UE_LOG(LogJson, Error, TEXT("Failed to properly setup SimpleConstructionScript"));
			return false;
		}
	}

	UE_LOG(LogJson, Log, TEXT("SCS setup done"));
	return true;
}

//Recursively constructs SCS nodes for Components. Returns nullptr if the component for this node or any of its child nodes cannot be loaded.
USCS_Node* IBlueprintImporter::CreateNodeFromNodeItem(const TSharedPtr<FJsonObject> NodeItem, bool bAddToSCS) {

	const TSharedPtr<FJsonObject> NodeProperties = NodeItem->GetObjectField("Properties");

	FString VariableName = NodeProperties->GetStringField("InternalVariableName");
	FString VariableGuid = NodeProperties->GetStringField("VariableGuid");
	FString ParentComponent = NodeProperties->HasTypedField<EJson::String>("ParentComponentOrVariableName") ? NodeProperties->GetStringField("ParentComponentOrVariableName") : "None";
	bool bParentNative = NodeProperties->HasTypedField<EJson::Boolean>("bIsParentComponentNative") ? NodeProperties->GetBoolField("bIsParentComponentNative") : false;

	const TSharedPtr<FJsonObject> ComponentClass = NodeProperties->GetObjectField("ComponentClass");

	UClass* ComponentClassObject = LoadClass(ComponentClass);

	if (!ComponentClassObject) {
		UE_LOG(LogJson, Error, TEXT("Unable to load Interface class: \"%s\""), *(GetFullPath(ComponentClass)));
		return nullptr;
	}

	USimpleConstructionScript* SCSInstance = Blueprint->SimpleConstructionScript;

	USCS_Node* CreatedNode = SCSInstance->CreateNode(ComponentClassObject, FName(VariableName));

	FGuid CreatedNodeGuid = FGuid(VariableGuid);
	CreatedNode->VariableGuid = CreatedNodeGuid;
	CreatedNode->ParentComponentOrVariableName = FName(ParentComponent);
	CreatedNode->bIsParentComponentNative = bParentNative;

	if (bAddToSCS) {
		SCSInstance->AddNode(CreatedNode);
	}

	if (NodeProperties->HasTypedField<EJson::Array>("ChildNodes")) {
		bool bAnyNodeFailed = false;
		for (const TSharedPtr<FJsonValue> NodePathExport : NodeProperties->GetArrayField("ChildNodes")) {
			const TSharedPtr<FJsonObject> NodePathItem = NodePathExport->AsObject();
			const TSharedPtr<FJsonObject> ChildNodeItem = GetExportByObjectPath(NodePathItem)->AsObject();

			USCS_Node* ChildNode = CreateNodeFromNodeItem(ChildNodeItem, false);

			if (!ChildNode) {
				bAnyNodeFailed = true;	//Still keep going to discover other component types that might be missing.
				continue;
			}

			CreatedNode->AddChildNode(ChildNode, true);
		}

		if (bAnyNodeFailed) {
			return nullptr;
		}
	}

	GeneratedPropertyNames.Add(VariableName);

	return CreatedNode;
}

const TMap<FString, EPinContainerType> PinContainerTypeByTypeName{
		{"ArrayProperty", EPinContainerType::Array},
		{"MapProperty", EPinContainerType::Map},
		{"SetProperty", EPinContainerType::Set}
};

const TMap<FString, const FName> PinCategoryByTypeName{
		{ "BoolProperty", UEdGraphSchema_K2::PC_Boolean },
		{ "ByteProperty", UEdGraphSchema_K2::PC_Byte },
		{ "IntProperty", UEdGraphSchema_K2::PC_Int },
		{ "Int64Property", UEdGraphSchema_K2::PC_Int64 },
		{ "FloatProperty", UEdGraphSchema_K2::PC_Float },
		{ "DoubleProperty", UEdGraphSchema_K2::PC_Double },
		{ "NameProperty", UEdGraphSchema_K2::PC_Name },
		{ "StrProperty", UEdGraphSchema_K2::PC_String },
		{ "TextProperty", UEdGraphSchema_K2::PC_Text },
		{ "StructProperty", UEdGraphSchema_K2::PC_Struct },
		{ "EnumProperty", UEdGraphSchema_K2::PC_Enum },
		{ "InterfaceProperty", UEdGraphSchema_K2::PC_Interface },
		{ "ObjectProperty", UEdGraphSchema_K2::PC_Object },
		{ "ObjectPtrProperty", UEdGraphSchema_K2::PC_Object },
		{ "ClassProperty", UEdGraphSchema_K2::PC_Class },
		{ "SoftClassProperty", UEdGraphSchema_K2::PC_SoftClass },
		{ "SoftObjectProperty", UEdGraphSchema_K2::PC_SoftObject },
		{ "DelegateProperty", UEdGraphSchema_K2::PC_Delegate },
		{ "MulticastDelegateProperty", UEdGraphSchema_K2::PC_MCDelegate },
		{ "MulticastInlineDelegateProperty", UEdGraphSchema_K2::PC_MCDelegate },
		{ "FieldPathProperty", UEdGraphSchema_K2::PC_FieldPath }
};

const TMap<FString, FString> SubCategoryObjectKeysByTypeName{
		{ "InterfaceProperty", "InterfaceClass"},
		{ "ObjectProperty", "PropertyClass"},
		{ "ObjectPtrProperty", "PropertyClass"},
		{ "SoftObjectProperty", "PropertyClass"},
		{ "ClassProperty", "MetaClass"},
		{ "SoftClassProperty", "MetaClass"},
		//{ "FieldPathProperty", "FieldClass"}
};

const TArray<FString> EnumPropertyTypeNames{
	"ByteProperty",
	"IntProperty",
	"EnumProperty"
};

const TArray<FString> DelegatePropertyTypeNames{
	"DelegateProperty",
	"MulticastDelegateProperty",
	"MulticastInlineDelegateProperty"
};

FEdGraphPinType IBlueprintImporter::GetPinTypeFromPropertyItem(const TSharedPtr<FJsonObject> PropertyItem, bool* bAllSubCatObjectsLoaded = nullptr) {
	FEdGraphPinType OutPinType{};


	const FString PropertyType = PropertyItem->GetStringField("Type");

	TArray<FString> PropertyFlags;
	GetFlagProperty(PropertyItem, "PropertyFlags", PropertyFlags);

	OutPinType.bIsConst = PropertyFlags.Contains("ConstParm");
	OutPinType.bIsReference = PropertyFlags.Contains("ReferenceParm");
	OutPinType.bIsUObjectWrapper = PropertyFlags.Contains("UObjectWrapper");
	//OutPinType.bIsWeakPointer = PropertyFlags.Contains("AutoWeak");
	//OutPinType.bSerializeAsSinglePrecisionFloat = PropertyFlags.Contains(""); //How to check for this?

	const EPinContainerType* ContainerTypeEntry = PinContainerTypeByTypeName.Find(PropertyType);
	const EPinContainerType ContainerType = (ContainerTypeEntry) ? *ContainerTypeEntry : EPinContainerType::None;
	OutPinType.ContainerType = ContainerType;

	TSharedPtr<FJsonObject> InnermostType = nullptr;

	switch (ContainerType) {
	case (EPinContainerType::None):
		InnermostType = PropertyItem;
		break;
	case (EPinContainerType::Array):
		InnermostType = PropertyItem->GetObjectField("Inner");
		break;
	case (EPinContainerType::Set):
		InnermostType = PropertyItem->GetObjectField("ElementProp");
		break;
	case (EPinContainerType::Map):
		InnermostType = PropertyItem->GetObjectField("KeyProp");
		break;
	};

	const FString InnerPropertyType = InnermostType->GetStringField("Type");

	const FName* PinCategoryEntry = PinCategoryByTypeName.Find(InnerPropertyType);
	if (PinCategoryEntry) {
		OutPinType.PinCategory = *PinCategoryEntry;
	}

	const FString* SubCatObjectFieldEntry = SubCategoryObjectKeysByTypeName.Find(InnerPropertyType);
	if (SubCatObjectFieldEntry) {
		FString SubCatObjectField = *SubCatObjectFieldEntry;
		if (InnermostType->HasTypedField<EJson::Object>(SubCatObjectField)) {
			const TSharedPtr<FJsonObject> SubCatObjectItem = InnermostType->GetObjectField(SubCatObjectField);

			UObject* SubCatObjectClass = LoadClass(SubCatObjectItem);

			if (!SubCatObjectClass) {
				UE_LOG(LogJson, Error, TEXT("Unable to load Subcategory Object for property type %s: \"%s\""), *InnerPropertyType, *(GetFullPath(SubCatObjectItem)));
				if (bAllSubCatObjectsLoaded) {
					*bAllSubCatObjectsLoaded = false;
				}
			}

			OutPinType.PinSubCategoryObject = SubCatObjectClass;

		}
	}
	else if (InnerPropertyType == "StructProperty") {
		const TSharedPtr<FJsonObject> SubCatObjectItem = InnermostType->GetObjectField("Struct");

		UObject* SubCatObjectClass = LoadStruct(SubCatObjectItem);

		if (!SubCatObjectClass) {
			UE_LOG(LogJson, Error, TEXT("Unable to load Subcategory Object for property type %s: \"%s\""), *InnerPropertyType, *(GetFullPath(SubCatObjectItem)));
			if (bAllSubCatObjectsLoaded) {
				*bAllSubCatObjectsLoaded = false;
			}
		}

		OutPinType.PinSubCategoryObject = SubCatObjectClass;
	}
	else if (EnumPropertyTypeNames.Contains(InnerPropertyType) && InnermostType->HasTypedField<EJson::Object>("Enum")) {
		if (InnerPropertyType == "EnumProperty") {
			OutPinType.PinCategory = UEdGraphSchema_K2::PC_Byte;
		}
		OutPinType.PinSubCategory = UEdGraphSchema_K2::PSC_Bitmask;

		const TSharedPtr<FJsonObject> SubCatObjectItem = InnermostType->GetObjectField("Enum");

		UObject* SubCatObjectClass = LoadEnum(SubCatObjectItem);

		if (!SubCatObjectClass) {
			UE_LOG(LogJson, Error, TEXT("Unable to load Subcategory Object for property type %s: \"%s\""), *InnerPropertyType, *(GetFullPath(SubCatObjectItem)));
			if (bAllSubCatObjectsLoaded) {
				*bAllSubCatObjectsLoaded = false;
			}
		}

		OutPinType.PinSubCategoryObject = SubCatObjectClass;
	}
	else if (DelegatePropertyTypeNames.Contains(InnerPropertyType)) {
		const TSharedPtr<FJsonObject> SubCatObjectPath = InnermostType->GetObjectField("SignatureFunction");
		const TSharedPtr<FJsonValue> SigFuncExport = GetExportByObjectPath(SubCatObjectPath);
		const TSharedPtr<FJsonObject> SigFuncItem = SigFuncExport->AsObject();

		FString SigFuncName = SigFuncItem->GetStringField("Name");
		GeneratedFunctionNames.Add(SigFuncName);
		AddFunctionGraph(SigFuncItem, true);

		UFunction* SignatureFunc = nullptr;
		FBlueprintEditorUtils::GetOverrideFunctionClass(Blueprint, FName(SigFuncName), &SignatureFunc);

		if (!SignatureFunc) {
			UE_LOG(LogJson, Error, TEXT("Unable to load Delegate Signature for property %s."), *SigFuncName);
			if (bAllSubCatObjectsLoaded) {
				*bAllSubCatObjectsLoaded = false;
			}
		}

		OutPinType.PinSubCategoryObject = SignatureFunc;
	}

	if (OutPinType.PinCategory == UEdGraphSchema_K2::PC_Float || OutPinType.PinCategory == UEdGraphSchema_K2::PC_Double) {
		OutPinType.PinSubCategory = OutPinType.PinCategory;
		OutPinType.PinCategory = UEdGraphSchema_K2::PC_Real;
	}

	if (ContainerType == EPinContainerType::Map) {
		const TSharedPtr<FJsonObject> ValTypeItem = PropertyItem->GetObjectField("ValueProp");
		FEdGraphPinType ValPinType = GetPinTypeFromPropertyItem(ValTypeItem, bAllSubCatObjectsLoaded);
		FEdGraphTerminalType ValTerminalType = FEdGraphTerminalType::FromPinType(ValPinType);

		OutPinType.PinValueType = ValTerminalType;
	}

	return OutPinType;
}

const TMap<FString, EPropertyFlags> PropertyFlagsByString{
	{"None",CPF_None},
	{"Edit", CPF_Edit},
	{"ConstParm", CPF_ConstParm},
	{"BlueprintVisible", CPF_BlueprintVisible},
	{"ExportObject", CPF_ExportObject},
	{"BlueprintReadOnly", CPF_BlueprintReadOnly},
	{"Net", CPF_Net},
	{"EditFixedSize", CPF_EditFixedSize},
	{"Parm", CPF_Parm},
	{"OutParm", CPF_OutParm},
	{"ZeroConstructor", CPF_ZeroConstructor},
	{"ReturnParm", CPF_ReturnParm},
	{"DisableEditOnTemplate", CPF_DisableEditOnTemplate},
	{"NonNullable", CPF_NonNullable},
	{"Transient", CPF_Transient},
	{"Config", CPF_Config},
	{"RequiredParm", CPF_RequiredParm},
	{"DisableEditOnInstance", CPF_DisableEditOnInstance},
	{"EditConst", CPF_EditConst},
	{"GlobalConfig", CPF_GlobalConfig},
	{"InstancedReference", CPF_InstancedReference},
	{"DuplicateTransient", CPF_DuplicateTransient},
	{"SaveGame", CPF_SaveGame},
	{"NoClear", CPF_NoClear},
	{"ReferenceParm", CPF_ReferenceParm},
	{"BlueprintAssignable", CPF_BlueprintAssignable},
	{"Deprecated", CPF_Deprecated},
	{"IsPlainOldData", CPF_IsPlainOldData},
	{"RepSkip", CPF_RepSkip},
	{"RepNotify", CPF_RepNotify},
	{"Interp", CPF_Interp},
	{"NonTransactional", CPF_NonTransactional},
	{"EditorOnly", CPF_EditorOnly},
	{"NoDestructor", CPF_NoDestructor},
	{"AutoWeak", CPF_AutoWeak},
	{"ContainsInstancedReference", CPF_ContainsInstancedReference},
	{"AssetRegistrySearchable", CPF_AssetRegistrySearchable},
	{"SimpleDisplay", CPF_SimpleDisplay},
	{"AdvancedDisplay", CPF_AdvancedDisplay},
	{"Protected", CPF_Protected},
	{"BlueprintCallable", CPF_BlueprintCallable},
	{"BlueprintAuthorityOnly", CPF_BlueprintAuthorityOnly},
	{"TextExportTrnasient", CPF_TextExportTransient},
	{"NonPIEDuplicateTransient", CPF_NonPIEDuplicateTransient},
	{"ExposeOnSpawn", CPF_ExposeOnSpawn},
	{"PersistentInstance", CPF_PersistentInstance},
	{"UObjectWrapper", CPF_UObjectWrapper},
	{"HasGetValueTypeHash", CPF_HasGetValueTypeHash},
	{"NativeAccessSpecifierPublic", CPF_NativeAccessSpecifierPublic},
	{"NativeAccessSpecififerProtected", CPF_NativeAccessSpecifierProtected},
	{"NativeAccessSpecififerPrivate", CPF_NativeAccessSpecifierPrivate},
	{"SkipSerialization", CPF_SkipSerialization}
};

EPropertyFlags IBlueprintImporter::GetPropertyFlags(TArray<FString> Flags) {
	EPropertyFlags Out = EPropertyFlags::CPF_None;
	for (FString FlagString : Flags) {
		const EPropertyFlags* ResolvedFlag = PropertyFlagsByString.Find(FlagString);
		if (ResolvedFlag) {
			Out |= *ResolvedFlag;
		}
	}
	return Out;
}

const TMap<FString, EFunctionFlags> FunctionFlagsByString{
	// Function flags.
	{"FUNC_None",FUNC_None},
	{"FUNC_Final",FUNC_Final},
	{"FUNC_RequiredAPI",FUNC_RequiredAPI},
	{"FUNC_BlueprintAuthorityOnly",FUNC_BlueprintAuthorityOnly},
	{"FUNC_BlueprintCosmetic",FUNC_BlueprintCosmetic},
	{"FUNC_Net",FUNC_Net},
	{"FUNC_NetReliable",FUNC_NetReliable},
	{"FUNC_NetRequest",FUNC_NetRequest},
	{"FUNC_Exec",FUNC_Exec},
	{"FUNC_Native",FUNC_Native},
	{"FUNC_Event",FUNC_Event},
	{"FUNC_NetResponse",FUNC_NetResponse},
	{"FUNC_Static",FUNC_Static},
	{"FUNC_NetMulticast",FUNC_NetMulticast},
	{"FUNC_UbergraphFunction",FUNC_UbergraphFunction},
	{"FUNC_MulticastDelegate",FUNC_MulticastDelegate},
	{"FUNC_Public",FUNC_Public},
	{"FUNC_Private",FUNC_Private},
	{"FUNC_Protected",FUNC_Protected},
	{"FUNC_Delegate",FUNC_Delegate},
	{"FUNC_NetServer",FUNC_NetServer},
	{"FUNC_HasOutParms",FUNC_HasOutParms},
	{"FUNC_HasDefaults",FUNC_HasDefaults},
	{"FUNC_NetClient",FUNC_NetClient},
	{"FUNC_DLLImport",FUNC_DLLImport},
	{"FUNC_BlueprintCallable",FUNC_BlueprintCallable},
	{"FUNC_BlueprintEvent",FUNC_BlueprintEvent},
	{"FUNC_BlueprintPure",FUNC_BlueprintPure},
	{"FUNC_EditorOnly",FUNC_EditorOnly},
	{"FUNC_Const",FUNC_Const},
	{"FUNC_NetValidate",FUNC_NetValidate},
	{"FUNC_AllFlags",FUNC_AllFlags}
};

EFunctionFlags IBlueprintImporter::GetFunctionFlags(TArray<FString> Flags) {
	EFunctionFlags Out = EFunctionFlags::FUNC_None;
	for (FString FlagString : Flags) {
		const EFunctionFlags* ResolvedFlag = FunctionFlagsByString.Find(FlagString);
		if (ResolvedFlag) {
			Out |= *ResolvedFlag;
		}
	}
	return Out;
}

const TArray<FString> BindingArrayFieldNames{
	"ComponentDelegateBindings",
	"WidgetAnimationDelegateBindings",
	"InputActionDelegateBindings",
	"InputAxisDelegateBindings",
	"InputAxisKeyDelegateBindings",
	"InputKeyDelegateBindings",
	"InputTouchDelegateBindings",
	"InputActionDelegateBindings",
	"InputActionValueBindings",
	"InputDebugKeyDelegateBindings"
};

bool IBlueprintImporter::SetUpDynamicBindings(const TSharedPtr<FJsonObject> DynamicBindings)
{
	//UEdGraph* EventGraph = FBlueprintEditorUtils::FindEventGraph(Blueprint);
	const FString BindingType = DynamicBindings->GetStringField("Type");
	const TSharedPtr<FJsonObject> DynBindingProperties = DynamicBindings->GetObjectField("Properties");
	bool bAllSuccessful = true;

	for (FString BindingArrayField : BindingArrayFieldNames) {
		if (DynBindingProperties->HasTypedField<EJson::Array>(BindingArrayField)) {
			for (const TSharedPtr<FJsonValue> Binding : DynBindingProperties->GetArrayField(BindingArrayField)) {
				const TSharedPtr<FJsonObject> BindingObject = Binding->AsObject();
				FString FunctionName = BindingObject->GetStringField("FunctionNameToBind");

				GeneratedFunctionNames.Add(FunctionName);

				UE_LOG(LogJson, Log, TEXT("Dynamic binding import not implemented: %s -> %s"), *BindingType, *FunctionName);

				/*
				FString ComponentName = BindingObject->GetStringField("ComponentPropertyName");
				FString DelegateName = BindingObject->GetStringField("DelegatePropertyName");

				UE_LOG(LogJson, Log, TEXT("Import for component event binding not implemented: %s -> %s"), *ComponentName, *DelegateName);

				UObject* Component = FindObject<UActorComponent>(Blueprint, *FunctionName);

				if (!Component) {
					bAllSuccessful = false;
					UE_LOG(LogJson, Warning, TEXT("No owner component of name %s for event %s"), *ComponentName, *DelegateName);
					continue;
				}

				UClass* ComponentClass = Component->GetClass();

				FGraphNodeCreator<UK2Node_ComponentBoundEvent> NodeCreator(*EventGraph);
				UK2Node_ComponentBoundEvent* EventNode = NodeCreator.CreateNode();

				EventNode->ComponentPropertyName = FName(ComponentName);
				EventNode->DelegatePropertyName = FName(DelegateName);
				//EventNode->DelegateOwnerClass = ComponentClass;

				OffsetGraphNode(EventNode);
				NodeCreator.Finalize();
				*/
			}
		}
	}

	return bAllSuccessful;
}

bool IBlueprintImporter::AddEventToEventGraph(const TSharedPtr<FJsonObject> FunctionExport)
{
	UEdGraph* EventGraph = FBlueprintEditorUtils::FindEventGraph(Blueprint);

	FString FuncNameRaw = FunctionExport->GetStringField("Name");
	FName FuncName = FName(FuncNameRaw);

	TArray<FString> FunctionFlags{};
	GetFlagProperty(FunctionExport, "FunctionFlags", FunctionFlags);

	UFunction* SigFuncObj = nullptr;
	UClass* SignatureFunction = FBlueprintEditorUtils::GetOverrideFunctionClass(Blueprint, FuncName, &SigFuncObj);

	if (SignatureFunction && (!UEdGraphSchema_K2::FunctionCanBePlacedAsEvent(SigFuncObj))/* || FunctionFlags.Contains("FUNC_HasOutParms")*/) {
		UE_LOG(LogJson, Warning, TEXT("Function marked as event, but isn't: %s"), *FuncNameRaw);
		return AddFunctionGraph(FunctionExport, false);
	}

	bool bIsOverride = (SignatureFunction != nullptr);
	bool bIsCustom = (!FunctionFlags.Contains("FUNC_Event"));

	if (bIsOverride) {
		if (FBlueprintEditorUtils::FindOverrideForFunction(Blueprint, SignatureFunction, FuncName)) {
			return true;
		}

		FGraphNodeCreator<UK2Node_Event> NodeCreator(*EventGraph);
		UK2Node_Event* EventNode = NodeCreator.CreateNode();

		EventNode->bOverrideFunction = bIsOverride;

		EventNode->EventReference.SetExternalMember(FuncName, SignatureFunction);

		OffsetGraphNode(EventNode);

		NodeCreator.Finalize();

		return true;
	}
	else if (bIsCustom){

		UE_LOG(LogJson, Warning, TEXT("Adding new custom event: %s"), *FuncNameRaw);
		FGraphNodeCreator<UK2Node_CustomEvent> NodeCreator(*EventGraph);
		UK2Node_CustomEvent* EventNode = NodeCreator.CreateNode();

		EventNode->bOverrideFunction = bIsOverride;

		EventNode->CustomFunctionName = FName(FuncName);

		EventNode->FunctionFlags = GetFunctionFlags(FunctionFlags);

		OffsetGraphNode(EventNode);

		NodeCreator.Finalize();

		EventNode->Modify();

		bool bAllPropertySubCatObjectsLoaded = true;

		if (FunctionExport->HasTypedField<EJson::Array>("ChildProperties")) {
			for (const TSharedPtr<FJsonValue> PropertyItem : FunctionExport->GetArrayField("ChildProperties")) {
				const TSharedPtr<FJsonObject> PropertyData = PropertyItem->AsObject();

				FString PropertyName = PropertyData->GetStringField("Name");

				TArray<FString> PropertyFlags;
				GetFlagProperty(PropertyData, "PropertyFlags", PropertyFlags);

				if (PropertyFlags.Contains("Parm")) {

					FName PinName = FName(PropertyName);
					FEdGraphPinType PinType = GetPinTypeFromPropertyItem(PropertyData, &bAllPropertySubCatObjectsLoaded);
					EEdGraphPinDirection PinDirection = EEdGraphPinDirection::EGPD_Output;

					EventNode->CreateUserDefinedPin(PinName, PinType, PinDirection);
				}
			}
		}
		return bAllPropertySubCatObjectsLoaded;
	}

	return true;
}

bool IBlueprintImporter::AddFunctionGraph(const TSharedPtr<FJsonObject> FunctionExport, bool bIsDelegateSignature)
{
	FString FuncNameRaw = FunctionExport->GetStringField("Name");
	if (bIsDelegateSignature) {
		FuncNameRaw = FuncNameRaw.Replace(TEXT("__DelegateSignature"), TEXT(""));
	}

	FName FuncName = FName(FuncNameRaw);

	TArray<FString> FunctionFlags{};
	GetFlagProperty(FunctionExport, "FunctionFlags", FunctionFlags);


	bool bHasOutParam = FunctionFlags.Contains("FUNC_HasOutParms");

	UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(Blueprint, FuncName, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());

	const UEdGraphSchema* Schema = NewGraph->GetSchema();
	const UEdGraphSchema_K2* K2Schema = Cast<const UEdGraphSchema_K2>(Schema);

	UFunction* SignatureFunctionObj = nullptr;
	UClass* SignatureFunction = FBlueprintEditorUtils::GetOverrideFunctionClass(Blueprint, FuncName, &SignatureFunctionObj);
	

	if (!bIsDelegateSignature) {
		FBlueprintEditorUtils::AddFunctionGraph<UClass>(Blueprint, NewGraph, true, SignatureFunction);
	}
	else {
		//Altered from FBlueprintEditorUtils::AddFunctionGraph
		FBlueprintEditorUtils::CreateFunctionGraph(Blueprint, NewGraph, true, SignatureFunction);

		Blueprint->DelegateSignatureGraphs.Add(NewGraph);

		// Potentially adjust variable names for any child blueprints
		FBlueprintEditorUtils::ValidateBlueprintChildVariables(Blueprint, NewGraph->GetFName());

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	}

	EFunctionFlags ParsedFlags = (SignatureFunctionObj) ? SignatureFunctionObj->FunctionFlags : GetFunctionFlags(FunctionFlags);

	for (UEdGraphNode* GraphNode : NewGraph->Nodes) {
		UK2Node_FunctionEntry* EntryNode = Cast< UK2Node_FunctionEntry>(GraphNode);

		if (EntryNode) {
			//UE_LOG(LogJson, Log, TEXT("Setting up function flags: %s"), *FunctionExport->GetStringField("FunctionFlags"));
			EntryNode->ClearExtraFlags(FUNC_AllFlags);
			EntryNode->SetExtraFlags(ParsedFlags);
			EntryNode->Modify();
		}
	}

	if (!SignatureFunction) {

		//setup parameters
		UK2Node_FunctionEntry* EntryNode = nullptr;
		UK2Node_FunctionResult* ExitNode = nullptr;

		for (UEdGraphNode* GraphNode : NewGraph->Nodes) {
			EntryNode = Cast< UK2Node_FunctionEntry>(GraphNode);

			if (EntryNode) {
				break;
			}
		}

		if (bHasOutParam)
		{
			FGraphNodeCreator<UK2Node_FunctionResult> NodeCreator(*NewGraph);
			ExitNode = NodeCreator.CreateNode();

			UEdGraphNode* LastExecNode = EntryNode;
			UEdGraphPin* OutExec = nullptr;

			while (LastExecNode) {

				OutExec = K2Schema->FindExecutionPin(*EntryNode, EGPD_Output);

				if (OutExec->LinkedTo.Num()) {
					UEdGraphPin* Connected = *OutExec->LinkedTo.begin();
					LastExecNode = Connected->GetOwningNode();
				}
				else {
					LastExecNode = nullptr;
				}
			}

			LastExecNode = OutExec->GetOwningNode();

			ExitNode->FunctionReference = EntryNode->FunctionReference;
			ExitNode->NodePosX = LastExecNode->NodePosX + LastExecNode->NodeWidth + 256;
			ExitNode->NodePosY = EntryNode->NodePosY;
			NodeCreator.Finalize();
			UEdGraphSchema_K2::SetNodeMetaData(ExitNode, FNodeMetadata::DefaultGraphNode);

			// Auto-connect the pins for entry and exit, so that by default the signature is properly generated
			UEdGraphPin* ResultNodeExec = K2Schema->FindExecutionPin(*ExitNode, EGPD_Input);

			if (ResultNodeExec && OutExec)
			{
				OutExec->MakeLinkTo(ResultNodeExec);
			}

			if (LastExecNode != EntryNode) {
				K2Schema->LinkDataPinFromOutputToInput(LastExecNode, ExitNode);
			}
		}

		if (FunctionExport->HasTypedField<EJson::Array>("ChildProperties")) {

			bool bAllPropertySubCatObjectsLoaded = true;
			for (const TSharedPtr<FJsonValue> PropertyItem : FunctionExport->GetArrayField("ChildProperties")) {
				const TSharedPtr<FJsonObject> PropertyData = PropertyItem->AsObject();

				FString PropertyName = PropertyData->GetStringField("Name");

				TArray<FString> PropertyFlags;
				GetFlagProperty(PropertyData, "PropertyFlags", PropertyFlags);

				if (PropertyFlags.Contains("Parm")) {

					UK2Node_FunctionTerminator* NodeToModify = EntryNode;

					FName PinName = FName(PropertyName);
					FEdGraphPinType PinType = GetPinTypeFromPropertyItem(PropertyData, &bAllPropertySubCatObjectsLoaded);
					EEdGraphPinDirection PinDirection = EEdGraphPinDirection::EGPD_Output;

					if (PropertyFlags.Contains("OutParm") && !PropertyFlags.Contains("ReferenceParm")) {
						NodeToModify = ExitNode;
						PinDirection = EEdGraphPinDirection::EGPD_Input;
					}

					NodeToModify->CreateUserDefinedPin(PinName, PinType, PinDirection);
				}
			}
			return bAllPropertySubCatObjectsLoaded;
		}
	}

	return true;
}

void IBlueprintImporter::OffsetGraphNode(UEdGraphNode* Node)
{
	Node->NodePosY = YOffset;
	Node->NodePosX = 0;
	YOffset += Node->NodeHeight + 128;
}
