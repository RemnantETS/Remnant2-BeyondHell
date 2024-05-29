#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UseDetails.h"
#include "UseableItemActivationInstance.generated.h"

class AActor;
class AUseableItem;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UUseableItemActivationInstance : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseDetails UseDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AUseableItem* OwningItem;
    
    UUseableItemActivationInstance();
    UFUNCTION(BlueprintCallable)
    void OnOwnerStateChange(const FName& StateName, const FName& PreviousStateName);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerInteractive(const FName& StateName, AActor* Other);
    
};

