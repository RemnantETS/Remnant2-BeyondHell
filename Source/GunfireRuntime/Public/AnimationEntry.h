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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, GetByRef))
    TArray<TSoftObjectPtr<UAnimSequenceBase>> Animations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, GetByRef))
    TArray< TSoftObjectPtr<UAnimSequenceBase>> SlaveAnimations;
    
    FAnimationEntry();
};

