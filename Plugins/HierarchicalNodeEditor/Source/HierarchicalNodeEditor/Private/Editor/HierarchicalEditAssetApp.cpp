// Copyright Gunfire Games, LLC. All Rights Reserved.


#include "Editor/HierarchicalEditAssetApp.h"
#include "Editor/HierarchicalEditorAppMode.h"
#include "Graph/HierarchicalNode_Base.h"
#include "GenericCommands.h"

void FHierarchicalEditAssetApp::RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(TabManager);
}

void FHierarchicalEditAssetApp::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject)
{
	TArray<UObject*> ObjectsToEdit;
	ObjectsToEdit.Add(InObject);

	WorkingAsset = Cast< UHierarchicalEditAsset >(InObject);

	InitAssetEditor(
		Mode,
		InitToolkitHost,
		CustomAppIdentifier,
		FTabManager::FLayout::NullLayout,
		true,
		true,
		ObjectsToEdit
	);

	TSharedPtr< FHierarchicalEditorAppMode> AppMode = MakeShareable(new FHierarchicalEditorAppMode(SharedThis(this)));
	AppMode->ExtendToolbar();


	AddApplicationMode(FHierarchicalEditorAppMode::ModeIdentifier, AppMode.ToSharedRef());
	SetCurrentMode(FHierarchicalEditorAppMode::ModeIdentifier);

	ToolkitCommands->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this, &FHierarchicalEditAssetApp::DeleteGraphAction),
		FCanExecuteAction::CreateSP(this, &FHierarchicalEditAssetApp::CanDeleteGraphAction)
	);
}

void FHierarchicalEditAssetApp::SetNodeDetailsView(TSharedPtr<class IDetailsView> NodeDetailsView)
{
	_NodeDetailsView = NodeDetailsView;
}

void FHierarchicalEditAssetApp::OnGraphSelectionChanged(const FGraphPanelSelectionSet& Selection)
{
	TArray<UHierarchicalNode_Base*> SelectedNodes;

	for (UObject* SelectedObject : Selection) {
		UHierarchicalNode_Base* SelectionAsNode = Cast< UHierarchicalNode_Base>(SelectedObject);
		if (SelectionAsNode != nullptr) {
			SelectedNodes.Add(SelectionAsNode);
		}
	}

	if (SelectedNodes.Num() == 1) {
		_NodeDetailsView->SetObject((SelectedNodes[0])->GetInnerObject());
	}
	else {
		_NodeDetailsView->SetObject(nullptr);
	}
}

void FHierarchicalEditAssetApp::DeleteGraphAction()
{
	if (!_WorkingGraphUI.IsValid()) return;

	FGraphPanelSelectionSet SelectedNodes = _WorkingGraphUI->GetSelectedNodes();

	for (UObject* SelectedObject : SelectedNodes) {
		UHNE_Node* SelectionAsNode = Cast< UHNE_Node>(SelectedObject);
		if (SelectionAsNode != nullptr) {
			SelectionAsNode->OnDeleteNodeAction();
		}
	}
	
}

bool FHierarchicalEditAssetApp::CanDeleteGraphAction()
{
	TSharedPtr<SDockTab> Tab = GetTabManager()->GetOwnerTab();
	return Tab->IsForeground();
}
