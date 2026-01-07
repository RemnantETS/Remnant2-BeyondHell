#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "HierarchicalNodeGraph.generated.h"

//---- GRAPH SCHEMA ----
UCLASS()
class UHierarchicalGraphSchema : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A,const UEdGraphPin* B) const override;

public:
	static const FName SC_ChildNode; //SubCategoryObject is the Class of the associated Object.
	static const FName SC_StateTransition; //SubCategoryObject should be some child Class of ActorState.
};

const FName UHierarchicalGraphSchema::SC_ChildNode = FName("ChildNode");
const FName UHierarchicalGraphSchema::SC_StateTransition = FName("StateTransition");


//---- CHILD NODE ACTION ----

USTRUCT()
struct FNewChildNodeAction : public FEdGraphSchemaAction {
	GENERATED_BODY()
public:
	FNewChildNodeAction();
	FNewChildNodeAction(FText InNodeCategory, FText InMenuDescription, FText InToolTip, const int32 InGrouping) 
		: FEdGraphSchemaAction(InNodeCategory, InMenuDescription, InToolTip, InGrouping) {}

	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;

public:
	UPROPERTY()
	UClass* InnerClass = nullptr;
};


//---- ARRAY NODE ACTION ----

USTRUCT()
struct FNewArrayNodeAction : public FEdGraphSchemaAction {
	GENERATED_BODY()
public:
	FNewArrayNodeAction();
	FNewArrayNodeAction(FText InNodeCategory, FText InMenuDescription, FText InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(InNodeCategory, InMenuDescription, InToolTip, InGrouping) {
	}

	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};

//---- REROUTE NODE ACTION ----

USTRUCT()
struct FNewRerouteNodeAction : public FEdGraphSchemaAction {
	GENERATED_BODY()
public:
	FNewRerouteNodeAction();
	FNewRerouteNodeAction(FText InNodeCategory, FText InMenuDescription, FText InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(InNodeCategory, InMenuDescription, InToolTip, InGrouping) {
	}

	virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
};