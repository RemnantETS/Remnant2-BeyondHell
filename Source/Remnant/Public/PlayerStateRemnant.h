#pragma once
#include "CoreMinimal.h"
#include "PlayerStateGunfire.h"
#include "LocalPlayerTargetChangedDelegate.h"
#include "OnReplicatedPlatformUpdateDelegate.h"
#include "PlayerStateRemnant.generated.h"

UCLASS(Blueprintable)
class REMNANT_API APlayerStateRemnant : public APlayerStateGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalPlayerTargetChanged OnLocalPlayerTargetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReplicatedPlatformUpdate OnCrossplayPlatformReplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CrossplayPlatform, meta=(AllowPrivateAccess=true))
    uint8 CrossplayPlatform;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Traveling, meta=(AllowPrivateAccess=true))
    bool bTraveling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocalPlayerTarget;
    
public:
    APlayerStateRemnant();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetIsLocalPlayerTarget(bool IsTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Traveling();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CrossplayPlatform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTraveling() const;
    
};

