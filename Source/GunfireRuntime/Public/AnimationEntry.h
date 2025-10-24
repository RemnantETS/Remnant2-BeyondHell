#pragma once
#include "CoreMinimal.h"
#include "AnimationEntry.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAnimationEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> Animations;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> SlaveAnimations;
    
    FAnimationEntry();
};

