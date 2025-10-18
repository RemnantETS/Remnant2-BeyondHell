#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode_Base.h"
#include "Branch.generated.h"

class UEventTreeNode;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UBranch : public UEventTreeNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEventTreeNode*> Nodes;
    
    UBranch();
};

