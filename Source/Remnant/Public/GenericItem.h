#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "SpawnList.h"
#include "EGenerationType.h"
#include "GenericDropInfo.h"
#include "GenericItem.generated.h"

class AActor;
class UInventoryComponent;
class USpawnTable;

UCLASS(Blueprintable)
class REMNANT_API AGenericItem : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpawnTable* RandomizedDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenerationType GenerationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UsePlayerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnList CachedSpawnList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CachedSpawnInfo, meta=(AllowPrivateAccess=true))
    TArray<FGenericDropInfo> CachedSpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGeneratedObjectPickupSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddToInventory;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSaveOnAward;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceSyncLoad;
    
    AGenericItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidatePickupHandled(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateAddToInventory(UInventoryComponent* Inventory);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CachedSpawnInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishedItemInit();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HasMaxSpawnsForCharacter(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HandleAward(UInventoryComponent* Inventory, bool bForceNoSharing);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetRewardItemLevel(AActor* Receipient);
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishSpawnInit();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void ClientSetSpawnInfo(const TArray<FGenericDropInfo>& SpawnInfo);
    
};

