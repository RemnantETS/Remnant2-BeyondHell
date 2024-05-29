#pragma once
#include "CoreMinimal.h"
#include "ActionBase.h"
#include "ActionInfiniteStamina.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UActionInfiniteStamina : public UActionBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AIMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> OutOfCombatTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HasInfiniteStamina, meta=(AllowPrivateAccess=true))
    bool bHasInfiniteStamina;
    
public:
    UActionInfiniteStamina();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateInfiniteStamina();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_HasInfiniteStamina();
    
};

