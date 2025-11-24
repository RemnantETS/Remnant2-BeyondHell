#pragma once
#include "CoreMinimal.h"
#include "ActorStateID.h"
#include "Conditions.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "ActorStateTransition.generated.h"

class UActorState;

UCLASS(Blueprintable,EditInlineNew)
class GUNFIRERUNTIME_API UActorStateTransition : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorStateID DestinationStateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetDestinationAnimationID;
    
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActorState* CachedState;
    
public:
    UActorStateTransition();
    
    // Fix for true pure virtual functions not being implemented
};

