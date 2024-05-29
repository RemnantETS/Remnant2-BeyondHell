#pragma once
#include "CoreMinimal.h"
#include "SceneCollision.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FSceneCollision {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PrimCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TriCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComponentCount;
    
    FSceneCollision();
};

