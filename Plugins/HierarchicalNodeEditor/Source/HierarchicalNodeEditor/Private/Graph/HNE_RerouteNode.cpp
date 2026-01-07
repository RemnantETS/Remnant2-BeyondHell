#include "HNE_RerouteNode.h"

void UHNE_RerouteNode::InitializeNode()
{
	UHNE_Node::InitializeNode();

	FEdGraphPinType InputType(PinTypeTemplate);

	this->CreatePin(
		EGPD_Input,
		InputType,
		NAME_None
	);

	this->CreatePin(
		EGPD_Output,
		InputType,
		NAME_None
	);
}

bool UHNE_RerouteNode::ShouldOverridePinNames() const
{
	return true;
}

FText UHNE_RerouteNode::GetPinNameOverride(const UEdGraphPin& Pin) const
{
	// Keep the pin size tiny
	return FText::GetEmpty();
}

void UHNE_RerouteNode::OnRenameNode(const FString& NewName)
{
	NodeComment = NewName;
}


UEdGraphPin* UHNE_RerouteNode::GetPassThroughPin(const UEdGraphPin* FromPin) const
{
	if (FromPin && Pins.Contains(FromPin))
	{
		return FromPin == Pins[0] ? Pins[1] : Pins[0];
	}

	return nullptr;
}
