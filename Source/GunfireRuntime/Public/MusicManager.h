#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EMusicEvent.h"
#include "EMusicState.h"
#include "MusicSetInstance.h"
#include "MusicManager.generated.h"

class UMusicManager;
class UMusicSetAsset;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UMusicManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMusicState AutomatedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMusicState ManualState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMusicSetInstance> ActiveMusicSets;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> ConversationRefObjects;
    
public:
    UMusicManager();
    UFUNCTION(BlueprintCallable)
    void PostMusicEvent(EMusicEvent Event);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMusicSetActive(UMusicSetAsset* MusicSet, UObject* Instigator) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UMusicManager* GetMusicManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMusicState GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable)
    void DeactivateMusicSet(UMusicSetAsset* MusicSet, UObject* Instigator, const FName& OutroStinger, bool bForceStop);
    
    UFUNCTION(BlueprintCallable)
    void ActivateMusicSet(UMusicSetAsset* MusicSet, UObject* Instigator);
    
};

