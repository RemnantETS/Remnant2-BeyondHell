#pragma once
#include "CoreMinimal.h"
#include "CVarListUserSettingEntry.h"
#include "ListUserSetting.h"
#include "ConsoleVariableListUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UConsoleVariableListUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCVarListUserSettingEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultValue;
    
    UConsoleVariableListUserSetting();
};

