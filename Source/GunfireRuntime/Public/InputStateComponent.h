#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ButtonEvent.h"
#include "EMoveInputMethod.h"
#include "InputButton.h"
#include "InputButtonDelegateDelegate.h"
#include "InputButtonEventDelegate.h"
#include "InputStateDelegateDelegate.h"
#include "InputStateComponent.generated.h"

class APlayerController;
class UInputAction;
class UInputHandler;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UInputStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputButton> Buttons;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRefreshButtonStatesOnSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMoveInputMethod MoveInputMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StickyMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyMovementThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WalkingToggleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWalkingInput;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputButtonEvent InputEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputStateDelegate MoveInputEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UInputAction*, UInputHandler*> InputHandlerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float LastCameraRelativeInputDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float LastCameraRelativeVerticalInputDirection;
    
public:
    UInputStateComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetWalking(bool InIsWalking);
    
    UFUNCTION(BlueprintCallable)
    void SetMoveInputEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonStateByName(const FName& Name, ButtonEvent Event);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateCameraRelativeInputDirections(float Direction, float VerticalDirection);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetButton(FName ButtonName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveButtonListener(const FName& Name, const FInputButtonDelegate& Event);
    
    UFUNCTION(BlueprintCallable)
    void OnSwitchCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMoveInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActionPressed(APlayerController* PlayerController, const UInputAction* InputAction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasVerticalMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasHorizontalMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetScreenRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetRelativeMoveInput(FRotator Rotation, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable)
    void GetMoveInput(UPARAM(Ref) FVector& OutMoveInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWalking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCameraRotation(FRotator& OutCameraRotation, bool bAllowSticky);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraRelativeMoveInput_UseCameraUp(bool bAllowSticky, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ButtonEvent GetButtonStateByName(const FName& Name) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckForEventByName(const FName& Name, ButtonEvent Event, float Window) const;
    
    UFUNCTION(BlueprintCallable)
    void AddButtonListener(const FName& Name, const FInputButtonDelegate& Event);
    
};

