#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/HitResult.h"
#include "ActorModifier.h"
#include "CameraEffect.h"
#include "DamageInfo.h"
#include "OnActionCompleteDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "ActionBase.generated.h"

class AActor;
class APlayerControllerGunfire;
class UActionBase;
class UActionComponent;
class UDamageType;
class UDamageTypeGunfire;

UCLASS(Blueprintable, Config=Game)
class GUNFIRERUNTIME_API UActionBase : public UActorModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraEffect CameraEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 ActionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActionCameraEffectHandleID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true, ExposeOnSpawn = true))
    FDamageInfo DamageInfo;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ApplyOnKilled;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowChildrenClassesToValidate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionCompleteDelegate OnActionComplete;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopOnCinematic;
    
public:
    UActionBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ValidateAction(AActor* Actor, AActor* Target) const;
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void SetCause(AActor* Cause);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActionStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActionStart();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionFinished() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetHitInfo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UDamageType> GetDamageType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCauseOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCause() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionComponent* GetActionComponent() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* FireProjectile(AActor* CauseActor, FName SourceSocket, AActor* TargetActor, TSubclassOf<AActor> ProjectileBP, float Speed, bool bOrientTowardsTarget, float AutoArcHeight, float GravityScale);
    
    UFUNCTION(BlueprintCallable)
    void FinishAction();
    
    UFUNCTION(BlueprintCallable)
    static void DoInstantHitFromAimVector(AActor* CauseActor, const FVector& Start, const FVector& End, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    static void DoInstantHit(AActor* CauseActor, FName SourceSocket, float Range, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    void ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, FHitResult HitInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AllowStopAction();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AllowAction(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& InDamageInfo, UActionBase* NewAction);
    
};

