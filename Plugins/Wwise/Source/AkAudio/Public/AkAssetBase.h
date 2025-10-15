#pragma once
#include "CoreMinimal.h"
#include "AkAudioType.h"
#include "AkAssetBase.generated.h"

class UAkAssetPlatformData;

UCLASS(Blueprintable)
class AKAUDIO_API UAkAssetBase : public UAkAudioType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Instanced, meta=(AllowPrivateAccess=true))
    UAkAssetPlatformData* PlatformAssetData;
    
    UAkAssetBase();
};

