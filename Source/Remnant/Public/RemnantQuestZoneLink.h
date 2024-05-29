#pragma once
#include "CoreMinimal.h"
#include "EZoneLinkType.h"
#include "RemnantQuestComponent.h"
#include "Templates/SubclassOf.h"
#include "ZoneLinkInfo.h"
#include "RemnantQuestZoneLink.generated.h"

class AActor;
class AQuest;
class AZoneActor;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestZoneLink : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZoneLinkType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZoneLinkNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Destination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanBeRespawnLink;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMainPath;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WorldMapID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> WaypointBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WaypointSpawnPointTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool OwnsLink;
    
public:
    URemnantQuestZoneLink();
    UFUNCTION(BlueprintCallable)
    void TravelTo();
    
    UFUNCTION(BlueprintCallable)
    void SetWaypointDisabled(bool Disabled);
    
    UFUNCTION(BlueprintCallable)
    void SetAsCheckpoint();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetLinkDisabled(AZoneActor* Zone, bool Disabled);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetLinkActive(AZoneActor* Zone, bool Active);
    
protected:
    UFUNCTION(BlueprintCallable)
    void MapLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    static TArray<FZoneLinkInfo> GetWaypointsForMapLocation(AQuest* Quest, FName InWorldMapID);
    
    UFUNCTION(BlueprintCallable)
    FZoneLinkInfo GetLinkInfo();
    
protected:
    UFUNCTION(BlueprintCallable)
    void DestinationZoneLoaded();
    
    UFUNCTION(BlueprintCallable)
    void DestinationMapLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateWaypoint();
    
    UFUNCTION(BlueprintCallable)
    void ActivateWaypoint(bool SetAsRespawnPoint);
    
};

