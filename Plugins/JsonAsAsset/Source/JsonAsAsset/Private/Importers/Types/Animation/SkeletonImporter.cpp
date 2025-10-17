/* Copyright JsonAsAsset Contributors 2024-2025 */

#include "Importers/Types/Animation/SkeletonImporter.h"

bool ISkeletonImporter::Import() {
	USkeleton* Skeleton = GetSelectedAsset<USkeleton>(true);

	if (Skeleton) {
		if (Skeleton->GetName() != AssetName) {
			Skeleton = nullptr;
		}
	}

	/* If there is no skeleton, create one. */
	if (!Skeleton) {
		Skeleton = NewObject<USkeleton>(Package, USkeleton::StaticClass(), *AssetName, RF_Public | RF_Standalone);

		ApplySkeletalChanges(Skeleton);
	} else {
		/* Empty the skeleton's sockets, blend profiles, and virtual bones */
		Skeleton->Sockets.Empty();
		Skeleton->BlendProfiles.Empty();

		TArray<FName> VirtualBoneNames;

		for (const FVirtualBone VirtualBone : Skeleton->GetVirtualBones()) {
			VirtualBoneNames.Add(VirtualBone.VirtualBoneName);
		}
		
		Skeleton->RemoveVirtualBones(VirtualBoneNames);
		Skeleton->AnimRetargetSources.Empty();
	}

	/* Deserialize Skeleton */
	DeserializeExports(Skeleton);
	GetObjectSerializer()->DeserializeObjectProperties(AssetData, Skeleton);

	ApplySkeletalAssetData(Skeleton);
	
	return OnAssetCreation(Skeleton);
}

void ISkeletonImporter::ApplySkeletalChanges(USkeleton* Skeleton) const {
	const TSharedPtr<FJsonObject> ReferenceSkeletonObject = AssetData->GetObjectField(TEXT("ReferenceSkeleton"));

	/* Get access to ReferenceSkeleton */
	FReferenceSkeleton& ReferenceSkeleton = const_cast<FReferenceSkeleton&>(Skeleton->GetReferenceSkeleton());
	FReferenceSkeletonModifier ReferenceSkeletonModifier(ReferenceSkeleton, Skeleton);

	TArray<TSharedPtr<FJsonValue>> FinalRefBoneInfo = ReferenceSkeletonObject->GetArrayField(TEXT("FinalRefBoneInfo"));
	TArray<TSharedPtr<FJsonValue>> FinalRefBonePose = ReferenceSkeletonObject->GetArrayField(TEXT("FinalRefBonePose"));

	int BoneIndex = 0;

	/* Go through each bone reference */
	for (const TSharedPtr<FJsonValue> FinalReferenceBoneInfoValue : FinalRefBoneInfo) {
		const TSharedPtr<FJsonObject> FinalReferenceBoneInfo = FinalReferenceBoneInfoValue->AsObject();

		FName Name(*FinalReferenceBoneInfo->GetStringField(TEXT("Name")));
		const int ParentIndex = FinalReferenceBoneInfo->GetIntegerField(TEXT("ParentIndex"));

		/* Fail-safe */
		if (!FinalRefBonePose.IsValidIndex(BoneIndex) || !FinalRefBonePose[BoneIndex].IsValid()) {
			continue;
		}
		
		TSharedPtr<FJsonObject> BonePoseTransform = FinalRefBonePose[BoneIndex]->AsObject();
		FTransform Transform; {
			PropertySerializer->DeserializeStruct(TBaseStructure<FTransform>::Get(), BonePoseTransform.ToSharedRef(), &Transform);
		}

		FMeshBoneInfo MeshBoneInfo = FMeshBoneInfo(Name, "", ParentIndex);

		/* Add the bone */
		ReferenceSkeletonModifier.Add(MeshBoneInfo, Transform);

		BoneIndex++;
	}

	/* Re-build skeleton */
	ReferenceSkeleton.RebuildRefSkeleton(Skeleton, true);
	
	Skeleton->ClearCacheData();
	Skeleton->MarkPackageDirty();
}

void ISkeletonImporter::ApplySkeletalAssetData(USkeleton* Skeleton) const {
	/* AnimRetargetSources ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
	const TSharedPtr<FJsonObject> AnimRetargetSources = AssetData->GetObjectField(TEXT("AnimRetargetSources"));

	for (const TPair<FString, TSharedPtr<FJsonValue>>& Pair : AnimRetargetSources->Values) {
		const FName KeyName = FName(*Pair.Key);
		const TSharedPtr<FJsonObject> RetargetObject = Pair.Value->AsObject();

		const FName PoseName(*RetargetObject->GetStringField(TEXT("PoseName")));

		/* Array of transforms for each bone */
		TArray<FTransform> ReferencePose;

		/* Add transforms for each bone */
		TArray<TSharedPtr<FJsonValue>> ReferencePoseArray = RetargetObject->GetArrayField(TEXT("ReferencePose"));

		for (TSharedPtr<FJsonValue> ReferencePoseTransformValue : ReferencePoseArray) {
			TSharedPtr<FJsonObject> ReferencePoseObject = ReferencePoseTransformValue->AsObject();
			
			FTransform Transform; {
				PropertySerializer->DeserializeStruct(TBaseStructure<FTransform>::Get(), ReferencePoseObject.ToSharedRef(), &Transform);
			}

			ReferencePose.Add(Transform);
		}
			
		/* Create reference pose */
		FReferencePose RetargetSource;
		RetargetSource.ReferencePose = ReferencePose;
		RetargetSource.PoseName = PoseName;

		Skeleton->AnimRetargetSources.Add(KeyName, RetargetSource);
	}

	RebuildSkeleton(Skeleton);
}

void ISkeletonImporter::RebuildSkeleton(const USkeleton* Skeleton) {
	/* Get access to ReferenceSkeleton */
	FReferenceSkeleton& ReferenceSkeleton = const_cast<FReferenceSkeleton&>(Skeleton->GetReferenceSkeleton());
	FReferenceSkeletonModifier ReferenceSkeletonModifier(ReferenceSkeleton, Skeleton);

	/* Re-build skeleton */
	ReferenceSkeleton.RebuildRefSkeleton(Skeleton, true);
}