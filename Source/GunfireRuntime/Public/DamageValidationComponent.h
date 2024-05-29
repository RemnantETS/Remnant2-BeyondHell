#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClientDamageInfo.h"
#include "DamageValidationComponent.generated.h"

class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDamageValidationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UDamageValidationComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerReceiveDamageResults(uint8 DamageID, bool bWasEvaded, bool bWasCounterEvade, const UObject* Source);
    
    UFUNCTION(Client, Reliable)
    void ClientValidateDamage(uint8 DamageID, uint16 DamageTimestamp, const FClientDamageInfo& DamageInfo);
    
};

