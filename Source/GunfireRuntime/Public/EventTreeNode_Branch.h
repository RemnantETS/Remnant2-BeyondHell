#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_Branch.generated.h"

class UBranch;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Branch : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UBranch*> Branches;
    
    UEventTreeNode_Branch();
};

