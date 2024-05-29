#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "DamageInfo.h"
#include "ManagedTickInterface.h"
#include "OnActionDelegateDelegate.h"
#include "OnAnyActionAppliedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "ActionComponent.generated.h"

class AActor;
class UActionBase;
class UDamageType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UActionComponent : public UActorComponent, public IManagedTickInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Actions, meta=(AllowPrivateAccess=true))
    TArray<UActionBase*> Actions;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionDelegate OnActionAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionDelegate OnActionRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActionBase>> DefaultActions;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActionBase*> OldActions;
    
public:
    UActionComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void StopActionByType(TSubclassOf<UActionBase> ActionBP);
    
    UFUNCTION(BlueprintCallable)
    void StopAction(int32 ActionID);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAnyActionAppliedListener(const FOnAnyActionAppliedDelegate& Event);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Actions();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 ModifyActionLevel(TSubclassOf<UActionBase> Action, int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionTypeRunning(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionRunning(int32 ActionID) const;
    
    UFUNCTION(BlueprintCallable)
    void InvokeEventOnAll(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void InvokeEvent(TSubclassOf<UActionBase> ActionType, FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumActionsOfType(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UActionBase*> GetAllActionsOfType(TSubclassOf<UActionBase> ActionBP, bool AllowChildClasses) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionBase* GetActionOfType(TSubclassOf<UActionBase> ActionBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActionBase* GetActionByID(int32 ID) const;
    
protected:
    UFUNCTION(BlueprintCallable,meta=(AutoCreateRefTerm="AdditionalTags, DamageInfo"))
    int32 DoActionInternal(UActionBase* Action, const FDamageInfo& DamageInfo, const TArray<FName>& AdditionalTags);
    
public:
    UFUNCTION(BlueprintCallable)
    int32 DoAction(TSubclassOf<UActionBase> Action, AActor* Cause, AActor* Target, FHitResult HitInfo, TSubclassOf<UDamageType> DamageType);
    
protected:
    UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm = "DamageInfo"))
    bool CanDoActionInternal(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& DamageInfo, UActionBase* NewAction);
    
public:
    UFUNCTION(BlueprintCallable)
    static void AddAnyActionAppliedListener(const FOnAnyActionAppliedDelegate& Event);
    
    
    // Fix for true pure virtual functions not being implemented
};

