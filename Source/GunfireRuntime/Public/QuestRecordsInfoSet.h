#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "QuestRecordsInfoSet.generated.h"

class UQuestRecordsInfo;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UQuestRecordsInfoSet : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UQuestRecordsInfo*> Records;
    
public:
    UQuestRecordsInfoSet();


    // Fix for true pure virtual functions not being implemented
};

