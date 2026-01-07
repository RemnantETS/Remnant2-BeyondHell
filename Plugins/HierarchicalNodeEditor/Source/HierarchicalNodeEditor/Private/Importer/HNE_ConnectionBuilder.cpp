#include "HNE_ConnectionBuilder.h"

bool FHNE_MultiConnectionBuilder::RegisterValuePin(UEdGraphPin* InPin, FProperty* InProperty, void* ValuePtr)
{
    UE_LOG(LogTemp, Log, TEXT("Register pin with multi tracker"));
    FEdGraphPinType PinType = InPin->PinType;

    TSharedPtr<FHNE_ConnectionTracker>* Tracker = TrackersBySubcategory.Find(PinType.PinSubCategory);

    if (Tracker == nullptr) return false;

    UE_LOG(LogTemp, Log, TEXT("Found matching tracker"));
    return (*Tracker)->RegisterValuePin(InPin, InProperty, ValuePtr);
}

bool FHNE_MultiConnectionBuilder::RegisterArrayPins(TArray<UEdGraphPin*> InPins, FArrayProperty* InProperty, void* ValuePtr)
{
    UE_LOG(LogTemp, Log, TEXT("Register pin array with multi tracker"));
    TArray<UEdGraphPin*> OutputPins = InPins.FilterByPredicate([](UEdGraphPin* InspectPin) {return InspectPin->Direction == EGPD_Output; });

    if (!OutputPins.Num()) return true;

    UEdGraphPin* FirstOutput = *(OutputPins.begin());
    
    FEdGraphPinType PinType = FirstOutput->PinType;

    TSharedPtr<FHNE_ConnectionTracker>* Tracker = TrackersBySubcategory.Find(PinType.PinSubCategory);

    if (Tracker == nullptr) return false;

    UE_LOG(LogTemp, Log, TEXT("Found matching tracker"));
    return (*Tracker)->RegisterArrayPins(OutputPins, InProperty, ValuePtr);
}

void FHNE_MultiConnectionBuilder::SetUpConnections()
{
    for (TPair<FName, TSharedPtr<FHNE_ConnectionTracker>> CategoryTracker : TrackersBySubcategory) {
        CategoryTracker.Value->SetUpConnections();
    }
}
