// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "Editor/HierachicalGraphTabFactory.h"
#include "Editor/HierarchicalEditAssetApp.h"
#include "GraphEditor.h"
#include "BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

FHierachicalGraphTabFactory::FHierachicalGraphTabFactory(TSharedPtr<class FHierarchicalEditAssetApp> App) : FWorkflowTabFactory(CustomTabIdentifier, App)
{
	_App = App;
	TabLabel = FText::FromString(TEXT("Graph"));
	ViewMenuDescription = FText::FromString(TEXT("Graph view of the hierarchical asset."));
	ViewMenuTooltip = FText::FromString(TEXT("Show graph view."));
}

TSharedRef<SWidget> FHierachicalGraphTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<class FHierarchicalEditAssetApp> App = _App.Pin();

	SGraphEditor::FGraphEditorEvents GraphEvents;
	GraphEvents.OnSelectionChanged.BindRaw(App.Get(), &FHierarchicalEditAssetApp::OnGraphSelectionChanged);

	TSharedPtr <SGraphEditor> GraphEditorUI = SNew(SGraphEditor)
		.IsEditable(true)
		.GraphEvents(GraphEvents)
		.GraphToEdit(App->GetWorkingGraph());

	App->SetWorkingGraphUI(GraphEditorUI);

	return SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1)
		.HAlign(HAlign_Fill)
		[
			GraphEditorUI.ToSharedRef()
		];
}

FText FHierachicalGraphTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FText::FromString(TEXT("Graph view for modifying hierarchical assets."));
}
