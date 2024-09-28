#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "PlayerRecordData.h"
#include "QuestRecordsInfo.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UQuestRecordsInfo : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerRecordData RecordInfo;
    
    UQuestRecordsInfo();


    // Fix for true pure virtual functions not being implemented
};

