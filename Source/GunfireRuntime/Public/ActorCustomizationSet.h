#pragma once
#include "CoreMinimal.h"
#include "HierarchicalEditInterface.h"
#include "InheritableAsset.h"
#include "ActorCustomizationSet.generated.h"

class UActorCustomizationSetEffect;
class UActorCustomizationSetSlot;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationSet : public UInheritableAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorCustomizationSetSlot*> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorCustomizationSetEffect*> Effects;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> HardReferencedAssets;
    
public:
    UActorCustomizationSet();
    
    // Fix for true pure virtual functions not being implemented
};

