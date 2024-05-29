#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HierarchicalEditInterface.h"
#include "LoadoutTemplate.generated.h"

class ULoadoutSlot;

UCLASS(Blueprintable, EditInlineNew)
class REMNANT_API ULoadoutTemplate : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULoadoutSlot*> Slots;
    
    ULoadoutTemplate();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ULoadoutSlot* GetLoadoutSlotByNameID(FName NameID) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

