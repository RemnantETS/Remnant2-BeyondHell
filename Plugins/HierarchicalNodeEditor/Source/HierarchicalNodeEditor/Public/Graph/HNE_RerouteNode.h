#pragma once 

#include "Graph/HNE_Node.h"
#include "HNE_RerouteNode.generated.h"

UCLASS()
class UHNE_RerouteNode : public UHNE_Node
{
	GENERATED_BODY()

public: // UEdGraphNode
	virtual FText GetNodeTitle(ENodeTitleType::Type TitelType) const override { return FText(); }
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(0, 0, 0, 0); }
	virtual FText GetTooltipText() { return FText::FromString("Reroute Node"); }
	virtual bool CanUserDeleteNode() const override { return true; }
	virtual bool ShouldDrawNodeAsControlPointOnly(int32& OutInputPinIndex, int32& OutOutputPinIndex) const override { OutInputPinIndex = 0;  OutOutputPinIndex = 1; return true; }

	virtual bool ShouldOverridePinNames() const override;
	virtual FText GetPinNameOverride(const UEdGraphPin& Pin) const override;
	virtual void OnRenameNode(const FString& NewName) override;
	virtual UEdGraphPin* GetPassThroughPin(const UEdGraphPin* FromPin) const override;

public:
	virtual void InitializeNode() override;

public:
	FEdGraphPinType PinTypeTemplate;
};