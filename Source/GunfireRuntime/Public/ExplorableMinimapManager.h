#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MinimapEntityRegistrationChangedDelegate.h"
#include "MinimapEntitySpawnRegisteredDelegate.h"
#include "ExplorableMinimapManager.generated.h"

class AActor;
class AExplorableMinimapModel;
class UExplorableMinimapManager;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UExplorableMinimapManager : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CameraSceneComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMinimapEntityRegistrationChanged MinimapEntityRegistrationChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMinimapEntitySpawnRegistered MinimapEntitySpawnRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMinimapEntitySpawnRegistered MinimapEntitySpawnUnregistered;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AExplorableMinimapModel* ExplorableMinimapModel;
    
public:
    UExplorableMinimapManager();
    UFUNCTION(BlueprintCallable)
    void ShutdownMinimap();
    
    UFUNCTION(BlueprintCallable)
    void SetCaptureEveryFrame(bool bValue);
    
    UFUNCTION(BlueprintCallable)
    bool IsTooltipEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsMinimapEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsFullscreenMinimapActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsFogOfWarEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetSpawnedMinimapEntities() const;
    
    UFUNCTION(BlueprintCallable)
    static AActor* GetRefActorFromMinimapEntity(const AActor* MinimapEntity);
    
    UFUNCTION(BlueprintCallable)
    AExplorableMinimapModel* GetExplorableMinimapModel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UExplorableMinimapManager* GetExplorableMinimapManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void EnableTooltips(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void EnableMinimap(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void EnableFogOfWar(bool bEnable);
    
};

