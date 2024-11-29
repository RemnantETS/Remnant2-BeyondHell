#pragma once
#include "CoreMinimal.h"
#include "DamageInfo.h"
#include "EMusicState.h"
#include "EventRegionCharacter.h"
#include "EventRegionDelegateDelegate.h"
#include "EventRegionPlayerDelegateDelegate.h"
#include "RemnantQuestComponent.h"
#include "RemnantQuestEventRegion.generated.h"

class AActor;
class ACharacterGunfire;
class AEventRegion;
class ARemnantCharacter;
class UMusicSetAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestEventRegion : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventRegionNameID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionDelegate OnBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionDelegate OnEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionPlayerDelegate OnPlayerEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventRegionPlayerDelegate OnPlayerExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicSetAsset* MusicSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideExistingSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AEventRegion* EventRegion;
    
public:
    URemnantQuestEventRegion(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetMusicState(EMusicState MusicState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNotifyTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnActorRegistered(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void LockEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventRegionActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARemnantCharacter*> GetPlayersInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPlayersInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantCharacter* GetFirstPlayerInRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEventRegion* GetEventRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetAggroGroup();
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventPlayerExit(FEventRegionCharacter Player);
    
    UFUNCTION(BlueprintCallable)
    void EventPlayerEnter(FEventRegionCharacter Player);
    
    UFUNCTION(BlueprintCallable)
    void EventOnEnd();
    
    UFUNCTION(BlueprintCallable)
    void EventOnBegin();
    
    UFUNCTION(BlueprintCallable)
    void EventCharacterExit(ACharacterGunfire* Character);
    
    UFUNCTION(BlueprintCallable)
    void EventCharacterEnter(ACharacterGunfire* Character);
    
public:
    UFUNCTION(BlueprintCallable)
    void End();
    
    UFUNCTION(BlueprintCallable)
    void CompleteEvent();
    
    UFUNCTION(BlueprintCallable)
    void Begin();
    
};

