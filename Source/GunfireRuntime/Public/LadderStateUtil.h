#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LadderStateUtil.generated.h"

class ACharacterGunfire;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ULadderStateUtil : public UObject {
    GENERATED_BODY()
public:
    ULadderStateUtil();
    UFUNCTION(BlueprintCallable)
    static bool GetCurrentLadderEntryExit(ACharacterGunfire* Character, FVector& Top, FVector& Bottom);
    
};

