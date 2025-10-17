/* Copyright JsonAsAsset Contributors 2024-2025 */

#pragma once

#include "CoreMinimal.h"
#include "Modules/UI/StyleModule.h"

#define LOCTEXT_NAMESPACE "FJsonAsAssetModule"

class FJsonAsAssetCommands : public TCommands<FJsonAsAssetCommands> {
public:
	FJsonAsAssetCommands()
		: TCommands(TEXT("JsonAsAsset"), NSLOCTEXT("Contexts", "JsonAsAsset", "JsonAsAsset"), NAME_None, FJsonAsAssetStyle::GetStyleSetName()) {
	}

	/* TCommands<> interface */
	virtual void RegisterCommands() override {
		UI_COMMAND(PluginAction, "JsonAsAsset", "Choose a JSON file to Convert", EUserInterfaceActionType::Button, FInputGesture());
	};

	TSharedPtr<FUICommandInfo> PluginAction;
};

#undef LOCTEXT_NAMESPACE
