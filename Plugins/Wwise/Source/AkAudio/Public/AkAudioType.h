#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAudioType.generated.h"

UCLASS(EditInlineNew)
class AKAUDIO_API UAkAudioType : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ShortID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> UserData;
    
    UAkAudioType();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetShortID();
    
};

