#include "MapTileInfo.h"

AMapTileInfo::AMapTileInfo() {
    this->RegisterTile = true;
    this->ResourceDensity = 1.00f;
    this->Direction = ETileDirection::None;
    this->Flags = 255;
    this->PathCost = 1;
    this->OriginPointActor = NULL;
}

