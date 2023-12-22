#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "ActorCustomizationSetSlot.generated.h"

class UActorCustomizationID;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationSetSlot : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorCustomizationID*> CustomizationIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UActorCustomizationSetSlot();
    
    // Fix for true pure virtual functions not being implemented
};

