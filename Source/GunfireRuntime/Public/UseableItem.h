#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "ButtonEvent.h"
#include "EItemUseType.h"
#include "EUsableActivationType.h"
#include "Equipment.h"
#include "OnUseDelegateDelegate.h"
#include "UseDetails.h"
#include "UseableItem.generated.h"

class AActor;
class UConditionList;
class UUseableItemActivationInstance;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AUseableItem : public AEquipment {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* Conditions;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseDetails UseDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseDetails HoldUseDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseDetails DoublePressUseDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PlayRateStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UseAnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUsableActivationType ActivationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreInputWhileInUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeferHoldUseUntilRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValidateUseBeforeStartingHoldTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoublePressTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableTickAfterUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ValidationTags;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUseDelegate OnItemUsed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle HoldTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle DoublePressTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUseableItemActivationInstance*> UseInstances;
    
public:
    AUseableItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateUse(AActor* Actor, EItemUseType UseType);
    
    UFUNCTION(BlueprintCallable)
    void UseItem(EItemUseType UseType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Use(EItemUseType UseType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateTickState();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerKeyPressed(EItemUseType UseType);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetInput();
    
    UFUNCTION(BlueprintCallable)
    void RemoveItem();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnUseInstanceDetailsRemoved(UUseableItemActivationInstance* Instance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUseableHotkeyReleased();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUseableHotkeyPressed();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnUse(EItemUseType UseType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreApplyUseDetails(EItemUseType UseType, const FUseDetails& OutUseDetails);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInput(FName ButtonName, ButtonEvent Event);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MultiCreateUseInstance(EItemUseType UseType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyUseDetails(EItemUseType UseType, UPARAM(Ref) FUseDetails& OutUseDetails) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasHoldTimerElapsed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCooldownPct(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientOnItemUsed(EItemUseType UseType);
    
};

