#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionBase.h"
#include "Templates/SubclassOf.h"
#include "ActionTeleport.generated.h"

class AActor;
class UCameraState;
class USceneComponent;

UCLASS(Blueprintable)
class UActionTeleport : public UActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReappearDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoHideActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> TeleportCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFaceTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMoveCameraOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraSnapMaxPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResetStateOnEnterTeleport;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector InitialLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTeleportInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTeleportFinalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> HiddenComponents;
    
public:
    UActionTeleport();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TryInitializeTeleport();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TryFinalizeTeleport();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerFinishTeleport(FVector FinalLocation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerBeginTeleport(AActor* Target, FVector FinalLocation);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OverrideTeleportLocation(FVector& OutTargetLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTeleportEnd(FVector FinalLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTeleportBegin(FVector FinalLocation);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastFinishTeleport(FVector NewLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastBeginTeleport(AActor* Target, FVector NewLocation);
    
    UFUNCTION(BlueprintCallable)
    void ClearTeleportCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanTeleport();
    
};

