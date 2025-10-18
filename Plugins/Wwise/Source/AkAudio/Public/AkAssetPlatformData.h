#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAssetPlatformData.generated.h"

class UAkAssetData;

UCLASS(NotBlueprintable, EditInlineNew)
class AKAUDIO_API UAkAssetPlatformData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAkAssetData* CurrentAssetData;
    
    UAkAssetPlatformData();
};

