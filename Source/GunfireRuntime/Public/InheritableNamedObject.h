#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "InheritableNamedObject.generated.h"

UCLASS(Abstract, EditInlineNew, NotBlueprintable, meta = (UsesHierarchy))
class GUNFIRERUNTIME_API UInheritableNamedObject : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid UniqueId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UInheritableNamedObject();
    
    // Fix for true pure virtual functions not being implemented
};

