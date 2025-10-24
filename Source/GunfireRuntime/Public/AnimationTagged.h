#pragma once
#include "CoreMinimal.h"
#include "AnimationAssetTagged.h"
#include "AnimationTagged.generated.h"

class UAnimSequenceBase;

UCLASS(EditInlineNew, NotBlueprintable)
class GUNFIRERUNTIME_API UAnimationTagged : public UAnimationAssetTagged {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> Animations;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> SlaveAnimations;
    
    UAnimationTagged();
};

