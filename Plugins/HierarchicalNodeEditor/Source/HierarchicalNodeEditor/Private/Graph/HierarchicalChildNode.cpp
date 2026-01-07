#include "HierarchicalChildNode.h"
#include "Graph/HierarchicalNodeGraph.h"

void UHierarchicalChildNode::SetUpInputPins()
{

	FEdGraphPinType PinType;
	PinType.PinSubCategory = UHierarchicalGraphSchema::SC_ChildNode;
	PinType.PinSubCategoryObject = InnerClass;

	this->CreatePin(
		EGPD_Input,
		PinType,
		FName("Parent")
	);
}
