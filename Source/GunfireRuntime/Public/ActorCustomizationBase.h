#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "ActorCustomizationBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationBase : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UActorCustomizationBase();
    
    // Fix for true pure virtual functions not being implemented
};

