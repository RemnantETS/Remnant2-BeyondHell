#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "StatInfoSet.generated.h"

class UStatInfo;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UStatInfoSet : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStatInfo*> Stats;
    
public:
    UStatInfoSet();
    
    // Fix for true pure virtual functions not being implemented
};

