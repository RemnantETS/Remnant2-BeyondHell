#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemDelegateDelegate.h"
#include "ItemInstanceData.generated.h"

UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class GUNFIRERUNTIME_API UItemInstanceData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    uint8 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDelegate OnChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDelegate OnVisuallyChanged;
    
    UItemInstanceData();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MinorChange();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_InstanceData();
    
};

