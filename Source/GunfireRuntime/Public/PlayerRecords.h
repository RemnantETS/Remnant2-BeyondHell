#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerRecordData.h"
#include "PlayerRecords.generated.h"

class APlayerState;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UPlayerRecords : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    APlayerState* Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FPlayerRecordData> Records;
    
    UPlayerRecords();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};

