#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "Templates/SubclassOf.h"
#include "VariableDef.h"
#include "EventTree.generated.h"

class UDialogVocalRange;
class UDialog_Speaker;
class UEventTreeNode;
class UEventTreeNode_Standalone;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTree : public UDataAsset, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEventTreeNode*> Nodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialog_Speaker> DefaultSpeaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEventTreeNode_Standalone* MultiInteractionNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogVocalRange> DefaultVocalRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVariableDef> Variables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NextUniqueId;
    
    UEventTree();
    
    // Fix for true pure virtual functions not being implemented
};

