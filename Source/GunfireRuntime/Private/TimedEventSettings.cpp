#include "TimedEventSettings.h"

UTimedEventSettings::UTimedEventSettings() {
    this->EventFileName = TEXT("events.json");
    this->EventFileRefreshRate = 10;
    this->VariableContext = TEXT("TimedEvent");
}

