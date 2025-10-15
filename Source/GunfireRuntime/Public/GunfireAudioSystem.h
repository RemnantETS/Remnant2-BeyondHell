#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "AudioComponentGunfire.h"
#include "GunfireAudioAttachParams.h"
#include "GunfireAudioPlayParams.h"
#include "GunfireAudioPlayingID.h"
#include "GunfireAudioStopParams.h"
#include "OnGunfireAudioFinishedDelegate.h"
#include "SoundGunfire.h"
#include "Templates/SubclassOf.h"
#include "GunfireAudioSystem.generated.h"

class AVolume;
class USceneComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGunfireAudioSystem : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* PImpl;
    
public:
    UGunfireAudioSystem();
    UFUNCTION(BlueprintCallable)
    static bool UseSound();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject", AutoCreateRefTerm = "StopParams"))
    static void StopSound(UObject* WorldContextObject, const FGunfireAudioPlayingID& PlayingID, const FGunfireAudioStopParams& StopParams);
    
    UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm = "PlayParams, AttachParams"))
    static FAudioComponentGunfire SpawnSoundAttached(const FSoundGunfire& Sound, USceneComponent* AttachToComponent, const FGunfireAudioPlayParams& PlayParams, const FGunfireAudioAttachParams& AttachParams);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", AutoCreateRefTerm = "PlayParams"))
    static FAudioComponentGunfire SpawnSoundAtLocation(UObject* WorldContextObject, const FSoundGunfire& Sound, FVector Location, const FGunfireAudioPlayParams& PlayParams);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject", AutoCreateRefTerm = "PlayParams"))
    static FAudioComponentGunfire SpawnSound2D(UObject* WorldContextObject, const FSoundGunfire& Sound, const FGunfireAudioPlayParams& PlayParams);
    
private:
    UFUNCTION(BlueprintCallable)
    static bool Sound_IsValid(const FSoundGunfire& Sound);
    
    UFUNCTION(BlueprintCallable)
    static bool Sound_IsPlaying(const FSoundGunfire& Sound);
    
    UFUNCTION(BlueprintCallable)
    static bool Sound_IsLooping(const FSoundGunfire& Sound);
    
    UFUNCTION(BlueprintCallable)
    static float Sound_GetSampleRate(const FSoundGunfire& Sound);
    
    UFUNCTION(BlueprintCallable)
    static float Sound_GetDuration(const FSoundGunfire& Sound);
    
    UFUNCTION(BlueprintCallable)
    static float Sound_GetAttenuation(const FSoundGunfire& Sound);
    
public:
    UFUNCTION(BlueprintCallable)
    static void SetTransientMasterVolume(float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FGunfireAudioPlayingID PlaySoundAtLocation(UObject* WorldContextObject, const FSoundGunfire& Sound, FVector Location, const FGunfireAudioPlayParams& PlayParams);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static FGunfireAudioPlayingID PlaySound2D(UObject* WorldContextObject, const FSoundGunfire& Sound, const FGunfireAudioPlayParams& PlayParams);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompatibleSound(UObject* Object);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompatibleAudioVolume(AVolume* Volume);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompatibleAudioComponent(USceneComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<USceneComponent> GetSubtitleComponentClass();
    
    UFUNCTION(BlueprintCallable)
    static UClass* GetSoundClass();
    
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<AVolume> GetAudioVolumeClass();
    
    UFUNCTION(BlueprintCallable)
    static UObject* GetAudioInterface();
    
    UFUNCTION(BlueprintCallable)
    static TSubclassOf<USceneComponent> GetAudioComponentClass();
    
private:
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_Stop(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, const FGunfireAudioStopParams& StopParams, FGunfireAudioPlayingID PlayingID);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_SetVolumeMultiplier(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_SetSound(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, const FSoundGunfire& NewSound);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_SetPitchMultiplier(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_SetParameter(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, const FName& Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_SetAutoDestroy(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable)
    static FGunfireAudioPlayingID AudioComponent_PlaySound(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, const FSoundGunfire& Sound, const FGunfireAudioPlayParams& PlayParams);
    
    UFUNCTION(BlueprintCallable)
    static FGunfireAudioPlayingID AudioComponent_Play(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, const FGunfireAudioPlayParams& PlayParams);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_OnFinished_Unbind(const FAudioComponentGunfire& AudioComponent, UObject* Object);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_OnFinished_Bind(const FAudioComponentGunfire& AudioComponent, const FOnGunfireAudioFinished& Callback);
    
    UFUNCTION(BlueprintCallable)
    static bool AudioComponent_IsValid(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool AudioComponent_IsPlaying(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static float AudioComponent_GetVolumeMultiplier(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static FSoundGunfire AudioComponent_GetSound(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static float AudioComponent_GetPitchMultiplier(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static FGunfireAudioPlayingID AudioComponent_GetLastPlayingId(const FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_ForceInternalTransformUpdate(UPARAM(Ref) FAudioComponentGunfire& AudioComponent);
    
    UFUNCTION(BlueprintCallable)
    static void AudioComponent_AdjustVolume(UPARAM(Ref) FAudioComponentGunfire& AudioComponent, float AdjustVolumeDuration, float AdjustVolumeLevel);
    
};

