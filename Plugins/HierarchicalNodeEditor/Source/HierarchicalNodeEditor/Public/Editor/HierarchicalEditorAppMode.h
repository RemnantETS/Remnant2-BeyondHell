// Copyright Gunfire Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FHierarchicalEditorAppMode : public FApplicationMode
{
public:
	FHierarchicalEditorAppMode(TSharedPtr<class FHierarchicalEditAssetApp> App);

public: // FApplicationMode
	virtual void RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

public:
	void ExtendToolbar();
	void FillToolbar(FToolBarBuilder& ToolbarBuilder);

public:
	static const FName ModeIdentifier;

private:
	TWeakPtr< class FHierarchicalEditAssetApp> _App;
	FWorkflowAllowedTabSet _Tabs;
};

const FName FHierarchicalEditorAppMode::ModeIdentifier = FName(TEXT("HierarchicalEditorAppMode"));
