#include "HierarchicalTableLinkNode.h"

TArray<FString> UHierarchicalTableLinkNode::GetFieldNamesToIgnore() const
{
	TArray<FString> IgnoreNames = UHierarchicalChildNode::GetFieldNamesToIgnore();
	IgnoreNames.Add("Table");
	return IgnoreNames;
}
