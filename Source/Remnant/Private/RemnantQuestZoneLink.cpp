#include "RemnantQuestZoneLink.h"

void URemnantQuestZoneLink::TravelTo() {
}

void URemnantQuestZoneLink::SetWaypointDisabled(bool Disabled) {
}

void URemnantQuestZoneLink::SetAsCheckpoint() {
}

void URemnantQuestZoneLink::MulticastSetLinkDisabled_Implementation(AZoneActor* Zone, bool Disabled) {
}

void URemnantQuestZoneLink::MulticastSetLinkActive_Implementation(AZoneActor* Zone, bool Active) {
}

void URemnantQuestZoneLink::MapLoaded() {
}

TArray<FZoneLinkInfo> URemnantQuestZoneLink::GetWaypointsForMapLocation(AQuest* Quest, FName InWorldMapID) {
    return TArray<FZoneLinkInfo>();
}

FZoneLinkInfo URemnantQuestZoneLink::GetLinkInfo() {
    return FZoneLinkInfo{};
}

void URemnantQuestZoneLink::DestinationZoneLoaded() {
}

void URemnantQuestZoneLink::DestinationMapLoaded() {
}

void URemnantQuestZoneLink::DeactivateWaypoint() {
}

void URemnantQuestZoneLink::ActivateWaypoint(bool SetAsRespawnPoint) {
}

URemnantQuestZoneLink::URemnantQuestZoneLink() {
    this->Type = EZoneLinkType::Link;
    this->StartsActive = false;
    this->CanBeRespawnLink = true;
    this->IsMainPath = false;
    this->WaypointBP = NULL;
    this->WaypointSpawnPointTag = TEXT("Waypoint");
    this->OwnsLink = true;
}

