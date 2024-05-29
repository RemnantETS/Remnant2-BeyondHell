#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageInfo.h"
#include "HealingInfo.h"
#include "GreyHealthDelegateDelegate.h"
#include "GreyHealthDeltaDelegateDelegate.h"
#include "GreyHealthComponent.generated.h"

class AActor;
class ACharacterGunfire;
class UGreyHealthComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API UGreyHealthComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GreyHealthRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GreyHealthRegen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GreyHealthBonusSegments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ForcedGreyHealthPercentStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialGreyhealthSegments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeThresholdForMultiHitGrouping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeAfterHitForRegenStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGreyHealthDeltaDelegate OnGreyHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGreyHealthDelegate OnComponentActiveStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGreyHealthDeltaDelegate OnServerGreyHealthHealedOwnerHealth;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool GreyHealthDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_GreyHealth, meta=(AllowPrivateAccess=true))
    TArray<float> GreyHealthSegments;
    
public:
    UGreyHealthComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void Reset(float InitialValue, bool Notify);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_GreyHealth(const TArray<float>& PreviousSegments);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPostComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerHealthRegen(ACharacterGunfire* Character, float RegenAmount);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerHealed(const FHealingInfo& HealingInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerDamageTaken(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGreyHealthDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumSegments() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxSegments() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealableGreyHealth() const;
    
    UFUNCTION(BlueprintCallable)
    static UGreyHealthComponent* GetGreyHealthComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGreyHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetForcedGreyHealthPercent() const;
    
    UFUNCTION(BlueprintCallable)
    FString GetDebugInfo(int32 DebugLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanRegenHealth();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ApplyDeltaReplicated(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void ApplyDelta(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void Append(float AppendAmount, bool CreateNewSegment, bool Notify);
    
};

