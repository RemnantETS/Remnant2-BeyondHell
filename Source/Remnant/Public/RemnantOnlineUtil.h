#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FindSessionsCallbackProxy.h"
#include "OnlineSessionDetailsRemnant.h"
#include "RemnantOnlineUtil.generated.h"

UCLASS(Blueprintable)
class REMNANT_API URemnantOnlineUtil : public UObject {
    GENERATED_BODY()
public:
    URemnantOnlineUtil();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void UpdateSessionCrossplayPlatformSetting(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void SetModeFilter(int32 Mode);
    
    UFUNCTION(BlueprintCallable)
    static void SetDifficultyFilter(int32 Difficulty);
    
    UFUNCTION(BlueprintCallable)
    static FOnlineSessionDetailsRemnant GetOnlineSessionDetails(const FBlueprintSessionResult& SessionResult);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FBlueprintSessionResult GetLocalSession(const UObject* WorldContextObject);
    
};

