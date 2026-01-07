// Copyright Gunfire Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"
#include "SGraphPanel.h"
#include "HierarchicalEditAsset.h"

/**
 * 
 */
class FHierarchicalEditAssetApp : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{
public:
	virtual void RegisterTabSpawners(const TSharedRef< class FTabManager >& TabManager) override;
	void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);

public: //FAssetEditorToolkit
	virtual FName GetToolkitFName() const override { return FName(TEXT("HierarchicalEditAssetEditorApp")); }
	virtual FText GetBaseToolkitName() const override { return FText::FromString(TEXT("HierarchicalEditAssetEditorApp")); }
	virtual FString GetWorldCentricTabPrefix() const override { return TEXT("HierarchicalEditAssetEditorApp"); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(0,1,0,0.5); }
	virtual void OnToolkitHostingStarted(const TSharedRef< IToolkit >& Toolkit) override {}
	virtual void OnToolkitHostingFinished(const TSharedRef< IToolkit >& Toolkit) override {}

public:
	UHierarchicalEditAsset* GetWorkingAsset() { return WorkingAsset; }
	class UEdGraph* GetWorkingGraph() { return WorkingAsset->WorkingGraph; }

	void SetWorkingGraphUI(TSharedPtr<SGraphEditor> WorkingGraphUI) { _WorkingGraphUI = WorkingGraphUI; }
	void SetNodeDetailsView(TSharedPtr<class IDetailsView> NodeDetailsView);
	void OnGraphSelectionChanged(const FGraphPanelSelectionSet& Selection);

protected:
	void DeleteGraphAction();
	bool CanDeleteGraphAction();

public:
	static const FName CustomAppIdentifier;

private:
	UPROPERTY()
	UHierarchicalEditAsset* WorkingAsset = nullptr;


	TSharedPtr<SGraphEditor> _WorkingGraphUI = nullptr;
	TSharedPtr<class IDetailsView> _NodeDetailsView = nullptr;
};

const FName FHierarchicalEditAssetApp::CustomAppIdentifier = FName(TEXT("HierarchicalEditAssetEditor"));