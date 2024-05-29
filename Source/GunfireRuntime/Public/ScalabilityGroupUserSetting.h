#pragma once
#include "CoreMinimal.h"
#include "EScalabilityGroup.h"
#include "ScalabilityUserSettingBase.h"
#include "ScalabilityGroupUserSetting.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UScalabilityGroupUserSetting : public UScalabilityUserSettingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EScalabilityGroup ScalabilityGroup;
    
    UScalabilityGroupUserSetting();
};

