// Copyright Gunfire Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FHierachicalGraphTabFactory : public FWorkflowTabFactory
{
public:
	FHierachicalGraphTabFactory(TSharedPtr<class FHierarchicalEditAssetApp> App);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

public:
	static const FName CustomTabIdentifier;

private:
	TWeakPtr<class FHierarchicalEditAssetApp> _App;
};

const FName FHierachicalGraphTabFactory::CustomTabIdentifier = FName("HierachicalGraphTab");