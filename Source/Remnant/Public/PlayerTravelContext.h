#pragma once
#include "CoreMinimal.h"
#include "PlayerTravelContext.generated.h"

class ARemnantPlayerController;
class ASpawnPoint;
class AZoneActor;
class UZoneLinkComponent;

USTRUCT(BlueprintType)
struct FPlayerTravelContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ARemnantPlayerController> Player;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AZoneActor> ZoneActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UZoneLinkComponent> LinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASpawnPoint> LinkSpawnPoint;
    
    REMNANT_API FPlayerTravelContext();
};

