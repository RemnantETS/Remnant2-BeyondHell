#pragma once 

#include "EdGraph/EdGraphNode.h"
#include "HNE_Node.generated.h"

UCLASS()
class UHNE_Node : public UEdGraphNode
{
	GENERATED_BODY()

public:
	UHNE_Node();
public: //UEdGraphNode
	virtual FText GetNodeTitle(ENodeTitleType::Type TitelType) const override { return FText::FromString("HNE Graph Node"); }
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(FColor::Black); }
	virtual bool CanUserDeleteNode() const override { return true; }
	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

public:
	virtual void InitializeNode();
	virtual void OnRefreshNodeAction();
	virtual void OnDeleteNodeAction();

public:
	FUIAction RefreshNodeUIAction;

	FUIAction DeleteNodeUIAction;
};