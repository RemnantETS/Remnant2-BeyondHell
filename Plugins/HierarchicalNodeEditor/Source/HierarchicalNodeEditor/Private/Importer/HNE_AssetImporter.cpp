#include "HNE_AssetImporter.h"
#include "HierarchicalEditInterface.h"
#include "HierarchicalEditAsset.h"
#include "Graph/HNE_Node.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HNE_GraphUtils.h"
#include "Graph/HierarchicalRootNode.h"
#include "Graph/HierarchicalChildNode.h"
#include "Graph/HierarchicalArrayNode.h"

#include "Importer/HNE_ConnectionBuilder.h"
#include "Importer/HNE_StateIDConnectionTracker.h"

#include "Algo/Reverse.h"

enum EBranchType {
    Array,
    Child
};

struct FBranchImportTask {
    EBranchType BranchType;
    UEdGraphPin* FromPin;
    FProperty* ValidateProperty;
    void* ValuePtr;
    TSharedPtr<FBranchExtentWrapper> ParentBranchWrapper;
    FString NamePath;
};

struct FBranchExtentWrapper {
    UEdGraphNode* Node;
    TArray<TSharedPtr<FBranchExtentWrapper>> ChildWrappers;
    int BranchHeight;
};


bool FHNE_AssetImporter::ImportObjectIntoGraph(UHierarchicalEditAsset* GraphAsset, UObject* InObject, bool bSetImportedAsTarget)
{
    if (InObject == nullptr) return false;

    if ( !(InObject->GetClass()->ImplementsInterface(UHierarchicalEditInterface::StaticClass())) ) {
        return false;
    }


    //InObject = DuplicateObject(InObject, GetTransientPackage());
    //Can't do that here, messes with FGUIDs; instead done inside Node->SetInnerObject

    UEdGraph* GraphToOverwrite = GraphAsset->WorkingGraph;
    GraphToOverwrite->Modify();

    //Clear all existing nodes.
    UE_LOG(LogTemp, Log, TEXT("Clearing existing graph nodes"));
    TArray< UHNE_Node*> AllNodes;
    GraphToOverwrite->GetNodesOfClass<UHNE_Node>(AllNodes);
    for (UHNE_Node* Node : AllNodes) {
        GraphToOverwrite->RemoveNode(Node);
    }

    //Setup tracker for non-parent/child connections
    TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker = MakeShared< FHNE_MultiConnectionBuilder>( 
        TMap<FName, TSharedPtr<FHNE_ConnectionTracker>>
        {
            {UHierarchicalGraphSchema::SC_StateTransition, MakeShared<FHNE_StateIDConnectionTracker>()}
        }
    );



    //Create new root node

    UHierarchicalRootNode* RootNode = NewObject< UHierarchicalRootNode>(GraphToOverwrite, UHierarchicalRootNode::StaticClass());
    RootNode->InnerClass = InObject->GetClass();

    GraphToOverwrite->AddNode(RootNode);

    RootNode->InitializeNode();
    RootNode->SetInnerObject(InObject);


    //Create tasks for branches
    TQueue<FBranchImportTask> BranchTasks;
    TArray< TSharedPtr<FBranchExtentWrapper>> BranchWrappers;
    TSharedPtr<FBranchExtentWrapper> OuterMostWrapper = MakeShared<FBranchExtentWrapper>();
    OuterMostWrapper->Node = RootNode;

    BranchWrappers.Add(OuterMostWrapper);

    for (UEdGraphPin* Pin : RootNode->Pins) {

        FProperty* ChildProp = RootNode->InnerClass->FindPropertyByName(Pin->GetFName());

        if (ChildProp == nullptr) continue;

        void* ChildValuePtr = ChildProp->ContainerPtrToValuePtr<void>(RootNode->GetInnerObject());

        FEdGraphPinType PinType = Pin->PinType;
        if (PinType.PinSubCategory != UHierarchicalGraphSchema::SC_ChildNode && PinType.ContainerType != EPinContainerType::Array) {
            ConnectionTracker->RegisterValuePin(Pin, ChildProp, ChildValuePtr);
        }

        if (Pin->Direction != EGPD_Output) continue; //child creation should only happen on output

        if (PinType.ContainerType == EPinContainerType::Array) {
            FBranchImportTask ArrayBranch;
            {
                ArrayBranch.BranchType = EBranchType::Array;
                ArrayBranch.FromPin = Pin;
                ArrayBranch.ValidateProperty = ChildProp;
                ArrayBranch.ValuePtr = ChildValuePtr;
                ArrayBranch.ParentBranchWrapper = OuterMostWrapper;
                ArrayBranch.NamePath = InObject->GetFName().ToString();
            }
                
            BranchTasks.Enqueue(ArrayBranch);
        }
        else if (PinType.PinSubCategory == UHierarchicalGraphSchema::SC_ChildNode) {
            FBranchImportTask ChildBranch;
            {
                ChildBranch.BranchType = EBranchType::Child;
                ChildBranch.FromPin = Pin;
                ChildBranch.ValidateProperty = ChildProp;
                ChildBranch.ValuePtr = ChildValuePtr;
                ChildBranch.ParentBranchWrapper = OuterMostWrapper;
                ChildBranch.NamePath = InObject->GetFName().ToString();
            }

            BranchTasks.Enqueue(ChildBranch);
        }
    }


    UE_LOG(LogTemp, Log, TEXT("Doing tasks"));

    while (!BranchTasks.IsEmpty()) {
        FBranchImportTask NextImportTask;
        BranchTasks.Dequeue(NextImportTask);
        bool bSuccess = FHNE_AssetImporter::HandleBranchImportTask(NextImportTask, BranchTasks, BranchWrappers, ConnectionTracker);
        if (!bSuccess) {

            UE_LOG(LogTemp, Log, TEXT("Failed task"));
        }
    }

    int MarginX = 256;
    int MarginY = 64;

    // discover branch heights
    UE_LOG(LogTemp, Log, TEXT("Determining Node positions"));
    for (int i = BranchWrappers.Num() - 1; i >= 0; --i) {
        TSharedPtr<FBranchExtentWrapper> Wrapper = BranchWrappers[i];

        for (TSharedPtr<FBranchExtentWrapper> ChildWrapper : Wrapper->ChildWrappers) {
            Wrapper->BranchHeight += ChildWrapper->BranchHeight + MarginY;
        }

        Wrapper->BranchHeight = std::max(Wrapper->BranchHeight, Wrapper->Node->NodeHeight + MarginY);
    }

    for (TSharedPtr<FBranchExtentWrapper> Wrapper : BranchWrappers) {
        int OffsetY = 0;
        UEdGraphNode* Node = Wrapper->Node;
        for (TSharedPtr<FBranchExtentWrapper> ChildWrapper : Wrapper->ChildWrappers) {
            ChildWrapper->Node->NodePosX = Node->NodePosX + std::max(Node->NodeWidth, MarginX);
            ChildWrapper->Node->NodePosY = Node->NodePosY + OffsetY;

            OffsetY += ChildWrapper->BranchHeight;
        }
    }


    UE_LOG(LogTemp, Log, TEXT("Setting up non-ownership connections"));
    ConnectionTracker->SetUpConnections();

    if (bSetImportedAsTarget) {
        GraphAsset->TargetInfo.OutAsset = InObject;
        GraphAsset->Modify();
    }

    //Clear all values governed by node connections.
    TArray< UHierarchicalNode_Base*> AllObjectNodes;
    GraphToOverwrite->GetNodesOfClass<UHierarchicalNode_Base>(AllObjectNodes);
    for (UHierarchicalNode_Base* Node : AllObjectNodes) {
        Node->ClearOutPinValues();
    }

    GraphToOverwrite->NotifyGraphChanged();

    return true;
}

bool FHNE_AssetImporter::HandleArrayBranchTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker)
{
    UE_LOG(LogTemp, Log, TEXT("%s"), *(Task.ValidateProperty->GetFName().ToString()));

    FArrayProperty* PropAsArray = CastField< FArrayProperty>(Task.ValidateProperty);

    if (PropAsArray == nullptr) return false; //Wasn't actually an array

    FScriptArrayHelper ArrayHelper(PropAsArray, Task.ValuePtr);

    if (!ArrayHelper.Num()) return true;

    UEdGraphPin* FromPin = Task.FromPin;


    UEdGraph* ParentGraph = FromPin->GetOwningNode()->GetGraph();
    FEdGraphPinType PinType = FromPin->PinType;

    UHierarchicalArrayNode* ArrayNode = NewObject< UHierarchicalArrayNode>(ParentGraph, UHierarchicalArrayNode::StaticClass());
    ArrayNode->PinTypeTemplate = FromPin->PinType;
    ArrayNode->InitializeNode();
    ArrayNode->SetNumberOfOutPins(ArrayHelper.Num());

    ParentGraph->Modify();
    ParentGraph->AddNode(ArrayNode, true);

    UEdGraphPin* ArrayParentPin = ArrayNode->FindPin(FName("Input"));

    ParentGraph->GetSchema()->TryCreateConnection(FromPin, ArrayParentPin);

    TSharedPtr<FBranchExtentWrapper> BranchWrapper = MakeShared< FBranchExtentWrapper>();
    BranchWrapper->Node = ArrayNode;

    OutBranchWrappers.Add(BranchWrapper);
    Task.ParentBranchWrapper->ChildWrappers.Add(BranchWrapper);

    if (PinType.PinSubCategory == UHierarchicalGraphSchema::SC_ChildNode) {

        for (int i = 0; i < ArrayHelper.Num(); ++i) {
            FBranchImportTask ChildBranchTask;
            {
                ChildBranchTask.BranchType = EBranchType::Child;
                ChildBranchTask.FromPin = ArrayNode->Pins[i + 1];
                ChildBranchTask.ParentBranchWrapper = BranchWrapper;
                ChildBranchTask.ValidateProperty = PropAsArray->Inner;
                ChildBranchTask.ValuePtr = ArrayHelper.GetRawPtr(i);
                ChildBranchTask.NamePath = Task.NamePath;
            }
            OutChildBranchQueue.Enqueue(ChildBranchTask);
        }

    }
    else {
        // get connection tracker for subcategory
        ConnectionTracker->RegisterArrayPins(ArrayNode->Pins, PropAsArray, Task.ValuePtr);
    }

    return true;
}


bool FHNE_AssetImporter::HandleChildBranchTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker)
{
    FProperty* InProperty = Task.ValidateProperty;

    if (InProperty == nullptr) return false;

    FObjectProperty* PropAsObject = CastField< FObjectProperty>(InProperty);

    if (PropAsObject == nullptr) return false;

    if (!PropAsObject->PropertyClass->ImplementsInterface(UHierarchicalEditInterface::StaticClass())) return false;

    UObject** ObjectPtr = (UObject**)Task.ValuePtr;
    UObject* InObject = *ObjectPtr;

    if (InObject == nullptr) return false;

    FString NamePath = Task.NamePath + "." + InObject->GetFName().ToString();

    UE_LOG(LogTemp, Log, TEXT("Object path: %s"), *(InObject->GetPathName()));
    UE_LOG(LogTemp, Log, TEXT("Import path: %s"), *(NamePath));


    UEdGraphPin* FromPin = Task.FromPin;

    UEdGraph* ParentGraph = FromPin->GetOwningNode()->GetGraph();

    UClass* NodeClass = FHNE_GraphUtils::GetNodeClassForObjectClass(InObject->GetClass());

    UE_LOG(LogTemp, Warning, TEXT("Creating Node object"))
    UHierarchicalChildNode* Result = NewObject<UHierarchicalChildNode>(ParentGraph, NodeClass);

    ParentGraph->Modify();
    ParentGraph->AddNode(Result, true);

    Result->InnerClass = InObject->GetClass();
    Result->InitializeNode();
    Result->SetInnerObject(InObject);

    UEdGraphPin* ParentPin = Result->FindPin(FName("Parent"));

    ParentGraph->GetSchema()->TryCreateConnection(FromPin, ParentPin);


    TSharedPtr<FBranchExtentWrapper> BranchWrapper = MakeShared< FBranchExtentWrapper>();
    BranchWrapper->Node = Result;

    OutBranchWrappers.Add(BranchWrapper);
    Task.ParentBranchWrapper->ChildWrappers.Add(BranchWrapper);


    for (UEdGraphPin* Pin : Result->Pins) {

        FProperty* OutProp = Result->InnerClass->FindPropertyByName(Pin->GetFName());
        if (OutProp == nullptr) continue;

        void* PropValue = OutProp->ContainerPtrToValuePtr<void>(Result->GetInnerObject());

        FEdGraphPinType PinType = Pin->PinType;
        if (PinType.PinSubCategory != UHierarchicalGraphSchema::SC_ChildNode && PinType.ContainerType != EPinContainerType::Array) {
            ConnectionTracker->RegisterValuePin(Pin, OutProp, PropValue);
        }

        if (Pin->Direction != EGPD_Output) continue;


        if (PinType.ContainerType == EPinContainerType::Array) {
            FBranchImportTask ArrayBranch;
            {
                ArrayBranch.BranchType = EBranchType::Array;
                ArrayBranch.FromPin = Pin;
                ArrayBranch.ValidateProperty = OutProp;
                ArrayBranch.ValuePtr = PropValue;
                ArrayBranch.ParentBranchWrapper = BranchWrapper;
                ArrayBranch.NamePath = NamePath;
            }

            OutChildBranchQueue.Enqueue(ArrayBranch);
        }
        else if (PinType.PinSubCategory == UHierarchicalGraphSchema::SC_ChildNode) {
            FBranchImportTask ChildBranch;
            {
                ChildBranch.BranchType = EBranchType::Child;
                ChildBranch.FromPin = Pin;
                ChildBranch.ValidateProperty = OutProp;
                ChildBranch.ValuePtr = PropValue;
                ChildBranch.ParentBranchWrapper = BranchWrapper;
                ChildBranch.NamePath = NamePath;
            }

            OutChildBranchQueue.Enqueue(ChildBranch);
        }
    }

    return true;
}

bool FHNE_AssetImporter::HandleBranchImportTask(FBranchImportTask Task, TQueue<FBranchImportTask>& OutChildBranchQueue, TArray< TSharedPtr<FBranchExtentWrapper>>& OutBranchWrappers, TSharedPtr<FHNE_ConnectionTracker> ConnectionTracker)
{
    if (Task.BranchType == EBranchType::Array) {
        return FHNE_AssetImporter::HandleArrayBranchTask(Task, OutChildBranchQueue, OutBranchWrappers, ConnectionTracker);
    } 
    else if (Task.BranchType == EBranchType::Child) {
        return FHNE_AssetImporter::HandleChildBranchTask(Task, OutChildBranchQueue, OutBranchWrappers, ConnectionTracker);

    }
    return false;
}
