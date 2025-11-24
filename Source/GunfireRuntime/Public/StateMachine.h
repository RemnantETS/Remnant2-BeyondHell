#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableAsset.h"
#include "StateMachine.generated.h"

class UActorState;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UStateMachine : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultState;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> States;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> HitReactions;
    
    UStateMachine();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetStateParent(UActorState* State) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetState(const FName& NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetRootState(UActorState* State) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

