#include "Editor/HierarchicalEditorAppMode.h"
#include "Editor/HierarchicalEditAssetApp.h"
#include "Editor/HierachicalGraphTabFactory.h"
#include "Editor/HierachicalTargetTabFactory.h"
#include "Editor/HierachicalPropertiesTabFactory.h"
#include "Importer/HNE_AssetImporter.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

FHierarchicalEditorAppMode::FHierarchicalEditorAppMode(TSharedPtr<class FHierarchicalEditAssetApp> App) : FApplicationMode(ModeIdentifier)
{
	_App = App;

	_Tabs.RegisterFactory(MakeShareable<FHierachicalGraphTabFactory>(new FHierachicalGraphTabFactory(App)));
	_Tabs.RegisterFactory(MakeShareable<FHierachicalTargetTabFactory>(new FHierachicalTargetTabFactory(App)));
	_Tabs.RegisterFactory(MakeShareable<FHierachicalPropertiesTabFactory>(new FHierachicalPropertiesTabFactory(App)));

	TabLayout = FTabManager::NewLayout("FHierarchicalEditorAppMode_Layout_v1")
		->AddArea(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->Split(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.75)
					->AddTab(FHierachicalGraphTabFactory::CustomTabIdentifier, ETabState::OpenedTab)
				)
				->Split(
					FTabManager::NewSplitter()
					->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.25)
					->Split(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.25)
						->AddTab(FHierachicalTargetTabFactory::CustomTabIdentifier, ETabState::OpenedTab)
					)
					->Split(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.75)
						->AddTab(FHierachicalPropertiesTabFactory::CustomTabIdentifier, ETabState::OpenedTab)
					)
				)
			)
		);
}

void FHierarchicalEditorAppMode::ExtendToolbar() {
	

	ToolbarExtender->AddToolBarExtension(
		FName("Asset"),
		EExtensionHook::After,
		TSharedPtr<FUICommandList>(),
		FToolBarExtensionDelegate::CreateSP(SharedThis(this), &FHierarchicalEditorAppMode::FillToolbar)
	);
}

void FHierarchicalEditorAppMode::FillToolbar(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.AddToolBarButton(
		FUIAction(
			FExecuteAction::CreateLambda(
				[this]() {
					UE_LOG(LogTemp, Warning, TEXT("Button press"));
					if ( !(this->_App.IsValid()) ) return;
					TSharedPtr<FHierarchicalEditAssetApp> PinnedApp = _App.Pin();
					UHierarchicalEditAsset* WorkingAsset = PinnedApp->GetWorkingAsset();
					WorkingAsset->CompileGraphToAsset();
				}
			)
		),
		NAME_None,
		FText::FromString(TEXT("Compile")),
		FText::FromString(TEXT("Create runtime asset from editor graph"))
	);

	ToolbarBuilder.AddToolBarButton(
		FUIAction(
			FExecuteAction::CreateLambda(
				[this]() {
					UE_LOG(LogTemp, Warning, TEXT("Button press"));
					if (!(this->_App.IsValid())) return;
					TSharedPtr<FHierarchicalEditAssetApp> PinnedApp = _App.Pin();

					UHierarchicalEditAsset* WorkingAsset = PinnedApp->GetWorkingAsset();

					FOpenAssetDialogConfig OpenAssetDialogConfig;
					OpenAssetDialogConfig.DialogTitleOverride = NSLOCTEXT("", "OpenAssetDialogTitle", "Select Asset to import");
					OpenAssetDialogConfig.DefaultPath = WorkingAsset->GetPackage()->GetFName().ToString();
					OpenAssetDialogConfig.bAllowMultipleSelection = false;

					FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
					TArray<FAssetData> SelectedAssets = ContentBrowserModule.Get().CreateModalOpenAssetDialog(OpenAssetDialogConfig);

					if (!SelectedAssets.Num()) return;

					FAssetData SelectedAssetData = *(SelectedAssets.begin());

					UObject* SelectedAsset = SelectedAssetData.GetAsset();

					if (SelectedAsset == nullptr) return;

					const FText DialogTitle = FText::FromString("Set as output?");
					const FText DialogMessage = FText::FromString("Should the imported asset be set as the output target? Compiling will then overwrite it.");

					const EAppReturnType::Type Response = FMessageDialog::Open(EAppMsgType::YesNo, DialogMessage, &DialogTitle);

					FHNE_AssetImporter::ImportObjectIntoGraph(WorkingAsset, SelectedAsset, (Response == EAppReturnType::Yes) );
				}
			)
		),
		NAME_None,
		FText::FromString(TEXT("Import")),
		FText::FromString(TEXT("Overwrites the current graph with one created "))
	);
}

void FHierarchicalEditorAppMode::RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager)
{
	TSharedPtr< FHierarchicalEditAssetApp> App = _App.Pin();
	App->PushTabFactories(_Tabs);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FHierarchicalEditorAppMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
}

void FHierarchicalEditorAppMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
}
