#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/DataTable.h"
#include "DamageInfo.h"
#include "EActorModifierScope.h"
#include "HealingInfo.h"
#include "InspectInfo.h"
#include "ActorModifier.generated.h"

class AActor;
class ACharacter;
class UStatInfoSet;
class UStatsComponent;
class UTexture2D;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UActorModifier : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EActorModifierScope Scope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Stats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Level, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = true))
    FText FlavorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> DisplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStatInfoSet* InspectStats;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
public:
    UActorModifier();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    virtual UWorld* GetWorld() const override;

    UFUNCTION(BlueprintCallable)
    void SetOwner(AActor* NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void SetLevel(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue);
    
    UFUNCTION(BlueprintCallable)
    void PostComputeStats();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTick(float DeltaSeconds);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnTakeDamage(const FDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Level();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostComputeStats();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLevelChanged();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnHitTarget(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeStats();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeDerivedStats();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAdded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifyTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void NotifyHitTarget(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void ModifyStat(FName Stat, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyInspectInfo(AActor* Actor, int32 InspectLevel, UPARAM(Ref) FInspectInfo& Info, bool& Rtn);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyIncomingHealing(UPARAM(Ref) FHealingInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyIncomingDamage(UPARAM(Ref) FDamageInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyHealing(UPARAM(Ref) FHealingInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ModifyDamage(UPARAM(Ref) FDamageInfo& Info);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetOwningCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetOwner() const;
    
    UFUNCTION(BlueprintCallable)
    FInspectInfo GetInspectInfo(AActor* Actor, int32 InspectLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetDebugText();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FilterIncomingHealing(UPARAM(Ref) FHealingInfo& HealingInfo, float& HealingOut, bool& ShouldApplyHealing);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FilterIncomingFallDamage(const float& Damage, float& DamageInfoOut, bool& ShouldApplyDamage);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FilterIncomingDamage(UPARAM(Ref) FDamageInfo& DamageInfo, float& DamageOut, bool& ShouldApplyDamage);
    
    UFUNCTION(BlueprintCallable)
    void ComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void ComputeDerivedStats();
    
};

