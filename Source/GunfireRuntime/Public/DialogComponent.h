#pragma once
#include "CoreMinimal.h"
#include "AudioComponentGunfire.h"
#include "DamageInfo.h"
#include "DialogCameraShotInfo.h"
#include "DialogEventDelegate.h"
#include "DialogInfo.h"
#include "DialogOption.h"
#include "DialogTokenValuePair.h"
#include "DialogVoidDelegateDelegate.h"
#include "EventTreeAttrib.h"
#include "EventTreeComponent.h"
#include "EventTreeStage.h"
#include "Templates/SubclassOf.h"
#include "DialogComponent.generated.h"

class AActor;
class ADialogStage;
class AItem;
class APlayerController;
class UDialogInstance;
class UEventTree;
class UEventTreeAsset;
class UEventTreeNode_ProximityTrigger;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDialogComponent : public UEventTreeComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventTree* EventTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoPlayDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableProximityTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpeakerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADialogStage> StageBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADialogStage* Stage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultAudioAttachSocket;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogBegin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogSetStage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogEvent OnDialogEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnOptionsUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogVoidDelegate OnDialogCameraUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool AllowMultipleSpeakers;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* DialogInitiator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Active, meta=(AllowPrivateAccess=true))
    bool DialogActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Stage, meta=(AllowPrivateAccess=true))
    FEventTreeStage DialogStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Dialog, meta=(AllowPrivateAccess=true))
    TArray<FEventTreeAttrib> DialogAttributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Dialog, meta=(AllowPrivateAccess=true))
    FDialogInfo Dialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Options, meta=(AllowPrivateAccess=true))
    TArray<FDialogOption> DialogOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CameraShot, meta=(AllowPrivateAccess=true))
    FDialogCameraShotInfo CameraShotInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FDialogTokenValuePair> TokenValuePairs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RelevantNPCS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioComponentGunfire DialogAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> DialogProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDialogInstance* CurrentDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UEventTreeNode_ProximityTrigger*, float> ProximityCooldowns;
    
public:
    UDialogComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void TokenValueSet(const FName& NameID, const FText& Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void SelectOptionByName(FName OptionName);
    
    UFUNCTION(BlueprintCallable)
    void SelectOption(uint8 OptionID);
    
    UFUNCTION(BlueprintCallable)
    void ResetStageFromCinematic();
    
    UFUNCTION(BlueprintCallable)
    void RemoveDialogProvider(UObject* Provider);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Stage();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Options();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Dialog();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CameraShot();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Active();
    
    UFUNCTION(BlueprintCallable)
    void OnInitiatorTakeAnyDamage(const FDamageInfo& Damage);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogFinished(UDialogInstance* Instance);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastShowEmote(const FName& Speaker, const FName& EmoteName, bool TargetAllPlayers);
    
public:
    UFUNCTION(BlueprintCallable)
    void JoinInProgressServer(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void JoinInProgressClient();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasOption(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValueForStage(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValueForOption(const FDialogOption& Option, FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAttributeValue(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveDialog();
    
    UFUNCTION(BlueprintCallable)
    void HandleEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTokenReplacedText() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> GetRelevantNPCs();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetRelevantNPC(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValueForStage(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValueForOption(const FDialogOption& Option, FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAttributeValue(FName Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEventTreeAsset* GetAttributeAssetForStage(FName Key);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteTrigger(const FName& TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteItemTrigger(TSoftClassPtr<AItem> ItemBP, AActor* Initiator);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EventTreeStageEvent(const FEventTreeStage& EventTreeStage);
    
    UFUNCTION(BlueprintCallable)
    void EventEnd();
    
    UFUNCTION(BlueprintCallable)
    void EventBegin();
    
public:
    UFUNCTION(BlueprintCallable)
    void DialogAdvance();
    
    UFUNCTION(BlueprintCallable)
    void BeginDialog(AActor* Initiator);
    
    UFUNCTION(BlueprintCallable)
    void AddRelevantNPC(AActor* NPC);
    
    UFUNCTION(BlueprintCallable)
    void AddDialogProvider(UObject* Provider);
    
};

