#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "BossRushDataTableRow.h"
#include "PotentialBuff.h"
#include "Templates/SubclassOf.h"
#include "BossRushComponent_Base.generated.h"

class UActionBase;
class UActionBuff;
class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API UBossRushComponent_Base : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* BRBuffTable;
    
public:
    UBossRushComponent_Base(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Reset();
    
    UFUNCTION(BlueprintCallable)
    void RefreshStoredBuffInfo(TSubclassOf<UActionBase> ActionFilterClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBossRushDataTableRow GetRowDataByNameID(FName NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetBuffOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UActionBuff> GetActionByNameID(FName NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DoBuff(FName RowName);
    
    UFUNCTION(BlueprintCallable)
    FName ChooseBuff(TArray<FPotentialBuff> PotentialBuffs);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanGetBuff(TSubclassOf<UActionBase> ActionClass);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanGetAnyBuff();
    
};

