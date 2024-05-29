#pragma once
#include "CoreMinimal.h"
#include "EquipmentModInstanceData.h"
#include "FeedData.h"
#include "PrismSegment.h"
#include "PrismStoneInstanceData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class REMNANT_API UPrismStoneInstanceData : public UEquipmentModInstanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    TArray<FPrismSegment> CurrentSegments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FFeedData> CurrentFeedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool HasBeenFed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float PendingExperience;
    
    UPrismStoneInstanceData();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
};

