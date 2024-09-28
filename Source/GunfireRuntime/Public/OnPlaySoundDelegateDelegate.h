#pragma once
#include "CoreMinimal.h"
#include "GunfireAudioPlayParams.h"
#include "OnPlaySoundDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaySoundDelegate, const FName, SoundIDName, const FGunfireAudioPlayParams&, PlayParams);

