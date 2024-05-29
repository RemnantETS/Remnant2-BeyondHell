#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnRegisterAttackDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "AICoordinatorBase.generated.h"

class AActor;
class UAICoordinatorBase;
class UCombatClass;
class UObject;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAICoordinatorBase : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCombatClass> DefaultCombatClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCombatClass> PlayerCombatClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRegisterAttackDelegate OnRegisterAttack;
    
    UAICoordinatorBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargeted(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCloselyTargeted(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAICoordinatorBase* GetAICoordinator(UObject* WorldContextObject);
    
};

