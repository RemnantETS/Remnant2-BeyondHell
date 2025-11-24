#pragma once
#include "CoreMinimal.h"
#include "ActorState.h"
#include "ActorStateID.h"
#include "CompoundState.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCompoundState : public UActorState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorStateID DefaultStateID;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> States;
    
    UCompoundState();
};

