#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TwitchActiveSessionDetails.h"
#include "TwitchConnectionEventDelegate.h"
#include "TwitchErrorEventDelegate.h"
#include "TwitchIntegrationManager.generated.h"

class APlayerState;
class UObject;
class UTexture2D;
class UTwitchIntegrationManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API UTwitchIntegrationManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTwitchErrorEvent OnTwitchError;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTwitchConnectionEvent OnTwitchConnectionEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTwitchActiveSessionDetails ActiveSessionDetails;
    
public:
    UTwitchIntegrationManager();
    UFUNCTION(BlueprintCallable)
    void StopTwitchIntegrationForReason(FText Reason);
    
    UFUNCTION(BlueprintCallable)
    void RefreshConnectionDetails();
    
    UFUNCTION(BlueprintCallable)
    void PopulateImagesOnServer();
    
    UFUNCTION(BlueprintCallable)
    void OnStopTwitchIntegration(bool KeepAuthToken);
    
    UFUNCTION(BlueprintCallable)
    void OnStartTwitchIntegration();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPawnChangedEvent();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerEquipmentChanged();
    
    UFUNCTION(BlueprintCallable)
    bool IsLive();
    
    UFUNCTION(BlueprintCallable)
    bool HasValidSession();
    
    UFUNCTION(BlueprintCallable)
    bool HasValidJWT();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTwitchIntegrationManager* GetTwitchIntegrationManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    FTwitchActiveSessionDetails GetSessionDetails();
    
    UFUNCTION(BlueprintCallable)
    void EncodeTexture(UTexture2D* Texture, FString& OutEncodedString, int32& OutSizeX, int32& OutSizeY);
    
    UFUNCTION(BlueprintCallable)
    void DecodeTexture(const FString& InEncodedString, const int32& InSizeX, const int32& InSizeY, UTexture2D*& OutTexture);
    
protected:
    UFUNCTION(BlueprintCallable)
    void BindToLocalControllerEvents(APlayerState* Player);
    
};

