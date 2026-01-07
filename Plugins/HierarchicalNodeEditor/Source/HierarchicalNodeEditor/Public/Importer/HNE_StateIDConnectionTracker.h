#pragma once

#include "HNE_ConnectionBuilder.h"

class FHNE_StateIDConnectionTracker : public FHNE_ConnectionTracker {
public:
	virtual bool RegisterValuePin(UEdGraphPin* InPin, FProperty* InProperty, void* ValuePtr) override;
	virtual bool RegisterArrayPins(TArray<UEdGraphPin*> InPins, FArrayProperty* InProperty, void* ValuePtr) override;
	virtual void SetUpConnections() override;
protected:
	void SetErrorMessages(TArray<UEdGraphPin*> Pins, FGuid StateID);
protected:
	TMap<FGuid, TArray<UEdGraphPin*>> PinsByID;
};