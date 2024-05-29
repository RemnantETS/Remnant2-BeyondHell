#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputCoreTypes.h"
#include "EInputDevice.h"
#include "OnDeviceChangedSignatureDelegate.h"
#include "OnNotifyDeviceChangedDelegate.h"
#include "OnPreDeviceChangedUpdateDelegate.h"
#include "OnResetIconCacheDelegate.h"
#include "InputDeviceManager.generated.h"

class APlayerController;
class UImageSet;
class UInputDeviceManager;

UCLASS(Blueprintable, Transient)
class GUNFIRERUNTIME_API UInputDeviceManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPreDeviceChangedUpdate OnPreDeviceChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNotifyDeviceChanged OnNotifyDeviceChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeviceChangedSignature OnDeviceChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResetIconCache OnResetIconCache;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UImageSet*> ImageSets;
    
public:
    UInputDeviceManager();
    UFUNCTION(BlueprintCallable)
    void ResetKeyboardIconCache();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnImageSetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingTouchController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingKeyboardAndMouse();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsUsingGamepadAnalogCursor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingGamepad();
    
    UFUNCTION(BlueprintCallable)
    static UInputDeviceManager* GetInstance();
    
    UFUNCTION(BlueprintCallable)
    static EInputDevice GetInputDeviceFromKey(const FKey Key);
    
    UFUNCTION(BlueprintCallable)
    UObject* GetImage(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    EInputDevice GetCurrentDeviceInUse(int32 ControllerId);
    
    UFUNCTION(BlueprintCallable)
    static bool CheckInputAction(const APlayerController* PlayerController, const FName& ActionName);
    
};

