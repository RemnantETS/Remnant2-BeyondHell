#pragma once
#include "CoreMinimal.h"
#include "EdGraph/EdGraphPin.h"

class FHNE_ConnectionTracker {
public:
	virtual bool RegisterValuePin(UEdGraphPin* InPin, FProperty* InProperty, void* ValuePtr) { return false; };
	virtual bool RegisterArrayPins(TArray<UEdGraphPin*> InPins, FArrayProperty* InProperty, void* ValuePtr) { return false; };
	virtual void SetUpConnections() {};
};

class FHNE_MultiConnectionBuilder : public FHNE_ConnectionTracker {
public:
	FHNE_MultiConnectionBuilder(TMap<FName, TSharedPtr<FHNE_ConnectionTracker>> Trackers) {TrackersBySubcategory = Trackers; }

	virtual bool RegisterValuePin(UEdGraphPin* InPin, FProperty* InProperty, void* ValuePtr) override;
	virtual bool RegisterArrayPins(TArray<UEdGraphPin*> InPins, FArrayProperty* InProperty, void* ValuePtr) override;
	virtual void SetUpConnections() override;
protected:
	TMap<FName, TSharedPtr<FHNE_ConnectionTracker>> TrackersBySubcategory;
};