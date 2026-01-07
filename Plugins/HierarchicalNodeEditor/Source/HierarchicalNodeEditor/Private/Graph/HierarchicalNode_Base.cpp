
#include "HierarchicalNode_Base.h"
#include "Graph/HierarchicalNodeGraph.h"
#include "Graph/HierarchicalArrayNode.h"

#include "HierarchicalEditInterface.h"
//#include "UObject/PropertyOptional.h"

void UHierarchicalNode_Base::InitializeNode()
{

	this->CreateNewGuid();

	if (InnerClass != nullptr) {
		UObject* NewInnerObject = NewObject<UObject>(this, InnerClass, NAME_None);
		if (InnerObject != nullptr) {

		}

		InnerObject = NewInnerObject;
	}

	SetUpInputPins();
	SetUpOutputPins();
}

void UHierarchicalNode_Base::SetUpOutputPins()
{

	for (TFieldIterator<FProperty> PropIterator(InnerClass); PropIterator; ++PropIterator) {

		if (GetFieldNamesToIgnore().Contains(PropIterator->GetName())) continue;

		bool bIsArrayField = false;
		FProperty* TestProperty = *PropIterator;

		FArrayProperty* TestArray = CastField<FArrayProperty>(*PropIterator);
		if (TestArray != nullptr) {
			TestProperty = TestArray->Inner;
			bIsArrayField = true;
		}

		FObjectPropertyBase* TestObjectProperty = CastField<FObjectPropertyBase>(TestProperty);

		if (TestObjectProperty == nullptr) continue;

		if (TestObjectProperty->PropertyClass->ImplementsInterface(UHierarchicalEditInterface::StaticClass())) {

			FEdGraphPinType PinType;
			PinType.PinSubCategory = UHierarchicalGraphSchema::SC_ChildNode;
			PinType.ContainerType = bIsArrayField ? EPinContainerType::Array : EPinContainerType::None;
			PinType.PinSubCategoryObject = TestObjectProperty->PropertyClass;

			this->CreatePin(
				EGPD_Output,
				PinType,
				PropIterator->GetName()
			);
		}
	}
}

UObject* UHierarchicalNode_Base::GetFinalizedAssetRecursive() const
{

	UE_LOG(LogTemp, Warning, TEXT("Getting Finalized"))

	//No caching, 
	UObject* OutObject = DuplicateObject<UObject>(GetInnerObject(), GetTransientPackage(), NAME_None);

	for (UEdGraphPin* Pin : Pins) {
		if (Pin->Direction != EGPD_Output) continue; // only consider output pins
		if (!Pin->LinkedTo.Num()) continue; //only consider pins with actual connections

		FEdGraphPinType PinType = Pin->PinType;

		if (PinType.PinSubCategory != UHierarchicalGraphSchema::SC_ChildNode) continue;

		FProperty* Property = InnerClass->FindPropertyByName(Pin->PinName);

		if (PinType.ContainerType == EPinContainerType::Array) {
			TArray<UObject*> ChildObjects;
			
			UHierarchicalArrayNode* ArrayNode = GetDownstreamNode<UHierarchicalArrayNode>(Pin);

			if (ArrayNode == nullptr) continue;

			//get connected child nodes from array node and add respective finalized assets
			for (UEdGraphPin* ArrayPin : ArrayNode->Pins) {
				if (ArrayPin->Direction != EGPD_Output) continue;

				UHierarchicalNode_Base* ChildNode = GetDownstreamNode< UHierarchicalNode_Base>(ArrayPin);

				if (ChildNode == nullptr) continue;

				ChildObjects.Add(ChildNode->GetFinalizedAssetRecursive());
			}

			for (UObject* Child : ChildObjects) {
				Child->Rename(nullptr, OutObject);
			}

			TArray<UObject*>* ArrayPointer = Property->ContainerPtrToValuePtr<TArray<UObject*>>(OutObject);
			*ArrayPointer = ChildObjects;
		}
		else {

			UHierarchicalNode_Base* ChildNode = GetDownstreamNode< UHierarchicalNode_Base> (Pin);

			if (ChildNode == nullptr) continue;

			UObject** ObjectPointer = Property->ContainerPtrToValuePtr<UObject*>(OutObject);

			UObject* ChildObject = ChildNode->GetFinalizedAssetRecursive();

			ChildObject->Rename(nullptr, OutObject);

			*ObjectPointer = ChildObject;
		}
	}
	
	return OutObject;
}

//Sets this node's inner object to be a duplicate of the input object, if the class matches exactly. 
void UHierarchicalNode_Base::SetInnerObject(UObject* InObject)
{
	if (InObject->GetClass() != InnerClass) return;

	InnerObject = DuplicateObject(InObject, this);
	InnerObject->ClearFlags(EObjectFlags::RF_Standalone);
	CopyPinValues(InObject);
}

//Copies values corresponding to a pin from the input object to this node's inner object. Intended to preserve FGuids after DuplicateObject calls. ClearOutPinValues should probably be called at some later point.
void UHierarchicalNode_Base::CopyPinValues(UObject* InObject) {
	for (UEdGraphPin* Pin : Pins) {
		FProperty* Prop = InnerClass->FindPropertyByName(Pin->GetFName());

		if (Prop == nullptr) continue;

		void* ValueDestination = Prop->ContainerPtrToValuePtr<void>(InnerObject);
		void* ValueSource = Prop->ContainerPtrToValuePtr<void>(InObject);

		Prop->CopyCompleteValue(ValueDestination, ValueSource);



		UE_LOG(LogTemp, Log, TEXT("%s copied: %d"), *(Pin->GetFName().ToString()), Prop->Identical(ValueDestination, ValueSource));
	}
}


//Clears all FProperty values of the inner object that correspond to the output pins of this node.
void UHierarchicalNode_Base::ClearOutPinValues(){
	TArray<UEdGraphPin*> OutputPins = Pins.FilterByPredicate([](UEdGraphPin* InspectPin) {return InspectPin->Direction == EGPD_Output; });

	for (UEdGraphPin* Pin : OutputPins) {
		FProperty* Prop = InnerClass->FindPropertyByName(Pin->GetFName());
		void* PropValue = Prop->ContainerPtrToValuePtr<void>(InnerObject);
		Prop->ClearValue(PropValue);
	}
}
