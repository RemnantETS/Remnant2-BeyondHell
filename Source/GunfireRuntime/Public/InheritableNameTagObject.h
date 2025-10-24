#pragma once
#include "CoreMinimal.h"
#include "InheritableNamedObject.h"
#include "InheritableNameTagObject.generated.h"

class UInheritableTaggedObject;

UCLASS(Abstract, NotBlueprintable)
class GUNFIRERUNTIME_API UInheritableNameTagObject : public UInheritableNamedObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInheritableTaggedObject*> Entries;
    
public:
    UInheritableNameTagObject();
};

