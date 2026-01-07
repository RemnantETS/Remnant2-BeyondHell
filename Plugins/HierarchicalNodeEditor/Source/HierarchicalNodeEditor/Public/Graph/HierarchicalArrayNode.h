#pragma once 

#include "Graph/HNE_Node.h"
#include "Framework/Commands/UIAction.h"
#include "HierarchicalArrayNode.generated.h"

UCLASS()
class UHierarchicalArrayNode : public UHNE_Node
{
	GENERATED_BODY()

public:
	UHierarchicalArrayNode();

public: // UEdGraphNode
	virtual FText GetNodeTitle(ENodeTitleType::Type TitelType) const override { return FText::FromString("Array"); }
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(0,0,0,0); }
	virtual FText GetTooltipText() { return FText::FromString("Array Node"); }
	virtual bool CanUserDeleteNode() const override { return true; }
	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

	virtual bool ShouldOverridePinNames() const override;
	virtual FText GetPinNameOverride(const UEdGraphPin& Pin) const override;

public:
	virtual void InitializeNode() override;
	void CreateOutputPin();
	void DeleteOutputPin();
	void SetNumberOfOutPins(uint32 TargetNumber);

public:

	FEdGraphPinType PinTypeTemplate;

	FUIAction CreatePinUIAction;

	FUIAction DeletePinUIAction;
};