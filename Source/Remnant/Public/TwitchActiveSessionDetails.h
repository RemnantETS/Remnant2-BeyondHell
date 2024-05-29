#pragma once
#include "CoreMinimal.h"
#include "TwitchActiveSessionDetails.generated.h"

USTRUCT(BlueprintType)
struct FTwitchActiveSessionDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ValidSession;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConnectedUser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UserIsLiveAndPlaying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActiveJWT;
    
    REMNANT_API FTwitchActiveSessionDetails();
};

