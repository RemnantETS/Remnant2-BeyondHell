#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "InheritableTaggedObject.generated.h"

UCLASS(Abstract)
class GUNFIRERUNTIME_API UInheritableTaggedObject : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UInheritableTaggedObject();
    
    // Fix for true pure virtual functions not being implemented
};

