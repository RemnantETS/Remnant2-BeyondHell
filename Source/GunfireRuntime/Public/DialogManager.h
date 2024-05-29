#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogCompleteAllEventDelegate.h"
#include "DialogInfo.h"
#include "GunfireAudioAttachParams.h"
#include "GunfireAudioPlayParams.h"
#include "SoftSoundGunfire.h"
#include "Templates/SubclassOf.h"
#include "DialogManager.generated.h"

class AActor;
class UDialogInstance;
class UDialogManager;
class UDialog_Emote;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDialogManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DialogCullDistance;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogCompleteAllEvent OnCompleteAll;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDialogInstance*> ActiveDialog;
    
public:
    UDialogManager();
    UFUNCTION(BlueprintCallable)
    bool StopDialog(AActor* Source);
    
    UFUNCTION(BlueprintCallable)
    bool StopActiveDialog();
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* PlayDialogFromTargetSoundSet(AActor* Source, FName SoundID, const FGunfireAudioPlayParams& PlayParams, const FGunfireAudioAttachParams& AttachParams, bool IgnoreVocalRange, bool UseFacialAnimation, TSubclassOf<UDialog_Emote> Emote, bool LocalOnly);
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* PlayDialogFromSound(AActor* Source, FSoftSoundGunfire Dialog);
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* PlayDialog(AActor* Source, const FDialogInfo& Info);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UDialogManager* GetDialogManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    UDialogInstance* GetActiveDialog(AActor* Source);
    
};

