#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GenericInput.h"
#include "UserSettingBuiltEventDelegate.h"
#include "GameUserSettingsGunfire.generated.h"

class URebindableInputSetting;
class UUserSetting;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGameUserSettingsGunfire : public UGameUserSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UUserSetting*> Settings;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserSettingBuiltEvent OnSettingsBuilt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserSettingBuiltEvent OnSettingsInitialized;
    
    UGameUserSettingsGunfire();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetUserSettingInt(const FName& NameID, int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetUserSettingFloat(const FName& NameID, int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsHardwareBenchmark() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UUserSetting*> GetSettingsForCategory(const FName& Category) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetInputConflicts(URebindableInputSetting* Setting, FGenericInput Key, const TArray<FName>& Categories, TArray<URebindableInputSetting*>& Conflicts);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUserSetting* FindUserSetting(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreSettingsInitialized() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowsInputRebindings() const;
    
};

