#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorators.h"
#include "ActorStateID.h"
#include "Conditions.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "ActorState.generated.h"

class UActorStateTransition;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorState : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorStateID UniqueId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsReentrant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInterruptible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InterruptPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InterruptChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorStateDecorators Decorators;
    
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorStateTransition*> Transitions;
    
    UActorState();
    
    // Fix for true pure virtual functions not being implemented
};

