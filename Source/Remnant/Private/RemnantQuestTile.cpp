#include "RemnantQuestTile.h"

void URemnantQuestTile::SetTileActive(int32 ID, bool Active) {
}

AActor* URemnantQuestTile::GetZoneLink(FName ZoneLinkNameID) {
    return NULL;
}

bool URemnantQuestTile::GetTileAttribute(FName Key, FMapGenAttribute& Out) {
    return false;
}

URemnantQuestTile::URemnantQuestTile() {
    this->IsWorldMapLocation = false;
    this->IsMainPath = false;
    this->Exclusive = true;
    this->IsOptionalForPlacement = false;
    this->OverrideFlags = 255;
    this->TileID = 0;
}

