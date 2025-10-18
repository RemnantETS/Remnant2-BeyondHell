#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "EventTreeNode_List.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_List : public UEventTreeNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEventTreeNode*> Nodes;
    
    UEventTreeNode_List();
};

