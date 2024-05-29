#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogResultDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "UIActor.generated.h"

class AUIActor;
class AUIHud;
class UUserWidget;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AUIActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AUIHud* HUD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> WidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* WidgetInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ViewPortZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Caption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceFromCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZOffsetFromCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DialogLinger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCaptureInput;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPassInputToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysOnTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvulnerable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveOnHidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveWhenNotOnTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveOnCinematic;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFixedCameraFoV;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogResultDelegate OnDialogResult;
    
    AUIActor();
    UFUNCTION(BlueprintCallable)
    void SetWidgetText(FName Widget, FText WidgetText);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RefreshDialogState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSoftEndDialog(float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnResolutionChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPushDialog(AUIActor* Next);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPopDialog(AUIActor* Prev);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndDialog();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDialogLayer(int32 Depth);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeginDialog();
    
    UFUNCTION(BlueprintCallable)
    void Focus();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CreateInstance();
    
};

