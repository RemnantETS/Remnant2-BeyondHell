#pragma once
#include "CoreMinimal.h"
#include "GlobalMaterialCustomization.h"
#include "MaterialInstanceParamCustomization.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMaterialInstanceParamCustomization : public UGlobalMaterialCustomization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UMaterialInstanceParamCustomization();
};

