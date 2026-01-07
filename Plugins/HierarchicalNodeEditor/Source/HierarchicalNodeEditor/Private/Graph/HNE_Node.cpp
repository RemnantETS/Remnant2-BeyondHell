#include "HNE_Node.h"

UHNE_Node::UHNE_Node()
{
	RefreshNodeUIAction = FUIAction(
		FExecuteAction::CreateLambda([this]() {this->OnRefreshNodeAction(); })
	);

	DeleteNodeUIAction = FUIAction(
		FExecuteAction::CreateLambda([this]() {this->OnDeleteNodeAction(); })
	);
}

void UHNE_Node::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->AddSection(TEXT("HNENodeActions"), FText::FromString(TEXT("Hierarchical Node Actions")));

	Section.AddMenuEntry(
		TEXT("RefreshNode"),
		FText::FromString(TEXT("Refresh Pin")),
		FText::FromString(TEXT("Reinitializes the selected node.")),
		FSlateIcon(TEXT(""), TEXT("")),
		RefreshNodeUIAction
	);

	if (CanUserDeleteNode()) {
		Section.AddMenuEntry(
			TEXT("DeleteNode"),
			FText::FromString(TEXT("Remove Node")),
			FText::FromString(TEXT("Removes the node from the graph.")),
			FSlateIcon(),
			DeleteNodeUIAction
		);
	}
}


void UHNE_Node::InitializeNode() {

	this->CreateNewGuid();
}

void UHNE_Node::OnRefreshNodeAction()
{
}

void UHNE_Node::OnDeleteNodeAction()
{
	if (CanUserDeleteNode()) GetGraph()->RemoveNode(this);
}
