#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ListUserSetting.h"
#include "ResolutionUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UResolutionUserSetting : public UListUserSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> AdditionalResolutions;
    
    UResolutionUserSetting();
};

