#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EAffiliation.h"
#include "Templates/SubclassOf.h"
#include "FactionManager.generated.h"

class UFaction;
class UFactionComponent;
class UFactionManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UFactionManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FactionOverridePropogationRadius;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFactionComponent*> FactionComponents;
    
public:
    UFactionManager();
    UFUNCTION(BlueprintCallable)
    void PropagateFactionOverrideAtLocation(const FVector& Location, TSubclassOf<UFaction> Faction, TSubclassOf<UFaction> FactionToOverride, EAffiliation NewAffiliation, float PropogationRadiusOverride);
    
    UFUNCTION(BlueprintCallable)
    void PropagateFactionOverride(UFactionComponent* Source, TSubclassOf<UFaction> Faction, EAffiliation Affiliation, float PropogationRadiusOverride);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UFactionManager* GetFactionManager(UObject* WorldContextObject);
    
};

