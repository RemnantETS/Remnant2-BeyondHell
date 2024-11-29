#include "RemnantQuestZoneLink.h"

URemnantQuestZoneLink::URemnantQuestZoneLink(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = EZoneLinkType::Link;
    this->GenerateZoneLink = true;
    this->StartsActive = false;
    this->CanBeRespawnLink = true;
    this->IsMainPath = false;
    this->WaypointBP = NULL;
    this->WaypointSpawnPointTag = TEXT("Waypoint");
    this->OwnsLink = true;
}

void URemnantQuestZoneLink::TravelTo(FName Context) {
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


