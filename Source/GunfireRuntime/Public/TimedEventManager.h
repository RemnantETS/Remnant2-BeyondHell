#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TimedEvent.h"
#include "TimedEventManager.generated.h"

class URootVariableContext;
class UTitleStorageFile;
class UVariableComponent;

UCLASS(Blueprintable, Config=Engine, DefaultConfig)
class GUNFIRERUNTIME_API UTimedEventManager : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVariableComponent* VariableComponent;
    
public:
    UTimedEventManager();
protected:
    UFUNCTION(BlueprintCallable)
    void OnRootVariableContextCreated(URootVariableContext* Context);
    /*
    UFUNCTION(BlueprintCallable)
    void OnFileManifestDownloaded(bool bSuccess, const TArray<UTitleStorageFile*>& FileManifest);
    
    UFUNCTION(BlueprintCallable)
    void OnFileDownloaded(bool bSuccess, UTitleStorageFile* File);
    */
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTags(const TArray<FName>& RequiredTags) ;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEvent(FName EventName) ;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetTags() ;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTimedEvent> GetEvents() ;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEvent(FName EventName, UPARAM(Ref) FTimedEvent& OutEvent) ;
    
};

