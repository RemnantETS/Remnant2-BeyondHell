#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapGenAttribute.h"
#include "QuestVoidDelegateDelegate.h"
#include "TileSpawnList.h"
#include "QuestZonePlayerDelegateDelegate.h"
#include "RemnantQuestComponent.h"
#include "Templates/SubclassOf.h"
#include "RemnantQuestZone.generated.h"

class APlayerController;
class URemnantQuestTile;
class USpawnTable;
class UTexture2D;
class UTileSet;
class UWorld;
class UZoneDef;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestZone : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UZoneDef> ZoneDef;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Static;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequestedID;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceLevelOffset;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ForceLevelOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> MapTemplates;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTileSet* TileSet;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileSpawnList> SpawnLists;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> SkyBox;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapGenAttribute> Attributes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ThemeTag;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMin;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> Slots;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnZoneLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnPreZoneUnloaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestVoidDelegate OnZoneUnloaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestZonePlayerDelegate OnPlayerEnteredZone;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestZonePlayerDelegate OnPlayerExitedZone;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<URemnantQuestTile*> QuestTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool OwnsZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool AssetsGathered;
    
public:
    URemnantQuestZone(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ZoneUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void ZoneLoaded();
    
    UFUNCTION(BlueprintCallable)
    void TravelToParent();
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnTableOverride(USpawnTable* SpawnTable);
    
    UFUNCTION(BlueprintCallable)
    void PreZoneLoaded();
    
    UFUNCTION(BlueprintCallable)
    void PlayerExitedZone(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void PlayerEnteredZone(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void ParentMapLoaded();
    
    UFUNCTION(BlueprintCallable)
    void MapLoaded();
    
};

