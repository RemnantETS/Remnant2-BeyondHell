#include "ResourceType.h"

FResourceType::FResourceType() {
    this->Distribution = EResourceDistribution::Quantity;
    this->ForceEvenDistribution = false;
    this->Min = 0.00f;
    this->Max = 0.00f;
    this->ResourceDensityIsAbsolute = false;
    this->SpawnTable = NULL;
}

