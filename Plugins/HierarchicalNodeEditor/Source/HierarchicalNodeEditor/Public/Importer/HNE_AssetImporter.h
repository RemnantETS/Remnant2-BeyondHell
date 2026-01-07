#pragma once
#include "CoreMinimal.h"
#include "HNE_ConnectionBuilder.h"

struct FBranchImportTask;
struct FBranchExtentWrapper;

class FHNE_AssetImporter {
public:
	static bool ImportObjectIntoGraph(UHierarchicalEditAsset* GraphAsset, UObject* InObject, bool bSetImportedAsTarget);
	static bool HandleBranchImportTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker);
	static bool HandleArrayBranchTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker);
	static bool HandleChildBranchTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker);
};
