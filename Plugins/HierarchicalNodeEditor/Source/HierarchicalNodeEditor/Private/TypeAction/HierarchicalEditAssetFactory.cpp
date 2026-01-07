// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "TypeAction/HierarchicalEditAssetFactory.h"
#include "HierarchicalEditAsset.h"
#include "ClassViewerFilter.h"
#include "HierarchicalEditInterface.h"
#include "Kismet2/SClassPickerDialog.h"
#include "BlueprintEditorUtils.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HierarchicalRootNode.h"

// Filter class for things which implement a particular interface
// Copied from "/Engine/Plugins/Chooser/Source/ChooserEditor/Public/ObjectChooserClassFilter.h"
class FInterfaceClassFilter : public IClassViewerFilter
{
public:
	FInterfaceClassFilter(UClass* InInterfaceType) : InterfaceType(InInterfaceType) {};
	virtual ~FInterfaceClassFilter() override {};

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< class FClassViewerFilterFuncs > InFilterFuncs) override
	{
		return (InClass->ImplementsInterface(InterfaceType) && InClass->HasAnyClassFlags(CLASS_Abstract) == false);
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const class IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< class FClassViewerFilterFuncs > InFilterFuncs) override
	{
		return false;
	}
private:
	UClass* InterfaceType;
};

UHierarchicalEditAssetFactory::UHierarchicalEditAssetFactory(const FObjectInitializer& ObjectInitializer) : UFactory(ObjectInitializer)
{
	SupportedClass = UHierarchicalEditAsset::StaticClass();
}

UObject* UHierarchicalEditAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UHierarchicalEditAsset* Asset = NewObject< UHierarchicalEditAsset >(InParent, Name, Flags);

	UEdGraph* Graph = FBlueprintEditorUtils::CreateNewGraph(
		Asset,
		NAME_None,
		UEdGraph::StaticClass(),
		UHierarchicalGraphSchema::StaticClass()
	);

	Asset->WorkingGraph = Graph;

	UHierarchicalRootNode* Result = NewObject< UHierarchicalRootNode >(Graph);

	Result->NodePosX = 0;
	Result->NodePosY = 0;

	Graph->Modify();
	Graph->AddNode(Result, true, true);

	Result->InnerClass = AssetClass;
	Result->InitializeNode();

	return Asset;
}

bool UHierarchicalEditAssetFactory::CanCreateNew() const
{
	return true;
}

bool UHierarchicalEditAssetFactory::ConfigureProperties()
{
	// nullptr the DataAssetClass so we can check for selection
	AssetClass = nullptr;

	// Load the classviewer module to display a class picker
	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");

	// Fill in options
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;

	TSharedPtr<FInterfaceClassFilter> Filter = MakeShareable(new FInterfaceClassFilter(UHierarchicalEditInterface::StaticClass()));
	Options.ClassFilters.Add(Filter.ToSharedRef());

	const FText TitleText = NSLOCTEXT("HierarchicalNodeEditor", "CreateHierarchicalEditAssetOptions", "Pick Class For HierarchicalEditAsset Instance");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(TitleText, Options, ChosenClass, UDataAsset::StaticClass());

	if (bPressedOk)
	{
		AssetClass = ChosenClass;
	}

	return bPressedOk;
}
