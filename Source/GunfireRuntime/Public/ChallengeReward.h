#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "ChallengeReward.generated.h"

class AActor;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UChallengeReward : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UChallengeReward();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HasBeenAwarded(AActor* Recepient);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GiveReward(AActor* Recepient);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetDisplayLabel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetDescription() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

