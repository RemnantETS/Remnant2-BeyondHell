// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "Editor/HierachicalTargetTabFactory.h"
#include "Editor/HierarchicalEditAssetApp.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"

FHierachicalTargetTabFactory::FHierachicalTargetTabFactory(TSharedPtr<class FHierarchicalEditAssetApp> App) : FWorkflowTabFactory(CustomTabIdentifier, App)
{
	_App = App;
	TabLabel = FText::FromString(TEXT("Properties"));
	ViewMenuDescription = FText::FromString(TEXT("Properties view of the selected node."));
	ViewMenuTooltip = FText::FromString(TEXT("Show properties view."));
}

TSharedRef<SWidget> FHierachicalTargetTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<class FHierarchicalEditAssetApp> App = _App.Pin();

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

	FDetailsViewArgs DetailsViewArgs;
	{
		DetailsViewArgs.bAllowSearch = false;
		DetailsViewArgs.bHideSelectionTip = true;
		DetailsViewArgs.bLockable = false;
		DetailsViewArgs.bSearchInitialKeyFocus = true;
		DetailsViewArgs.bUpdatesFromSelection = false;
		DetailsViewArgs.NotifyHook = nullptr;
		DetailsViewArgs.bShowOptions = true;
		DetailsViewArgs.bShowModifiedPropertiesOption = false;
		DetailsViewArgs.bShowScrollBar = false;
	}

	TSharedPtr<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->SetObject(App->GetWorkingAsset());

	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1)
		.HAlign(HAlign_Fill)
		[
			DetailsView.ToSharedRef()
		];
}

FText FHierachicalTargetTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("Properties view for modifying hierarchical asset node properties."));
}
