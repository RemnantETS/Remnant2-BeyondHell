#pragma once
#include "CoreMinimal.h"
#include "ActorCustomizationEffect.h"
#include "GunfireAudioAttachParams.h"
#include "GunfireAudioPlayParams.h"
#include "SoundGunfire.h"
#include "AudioCustomizationEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UAudioCustomizationEffect : public UActorCustomizationEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoundGunfire Sound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioPlayParams PlayParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioAttachParams AttachParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Component;
    
    UAudioCustomizationEffect();
};

