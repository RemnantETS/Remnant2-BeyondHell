#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableAsset.h"
#include "InheritableNamedAsset.generated.h"

class UInheritableNamedObject;

UCLASS(Abstract, EditInlineNew, NotBlueprintable, meta = (UsesHierarchy))
class GUNFIRERUNTIME_API UInheritableNamedAsset : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInheritableNamedObject*> Entries;
    
    UInheritableNamedAsset();
    
    // Fix for true pure virtual functions not being implemented
};

