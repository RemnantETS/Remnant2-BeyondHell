#pragma once
#include "CoreMinimal.h"
#include "GunfireAudioAttachParams.h"
#include "GunfireAudioPlayParams.h"
#include "GunfireAudioStopParams.h"
#include "SceneCustomization.h"
#include "SoftSoundGunfire.h"
#include "AudioCustomization.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UAudioCustomization : public USceneCustomization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftSoundGunfire StartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioPlayParams StartSoundPlayParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartSoundAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioAttachParams StartSoundAttachParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopStartSoundOnEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioStopParams StartSoundStopParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftSoundGunfire EndSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioPlayParams EndSoundPlayParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEndSoundAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunfireAudioAttachParams EndSoundAttachParams;
    
    UAudioCustomization();
};

