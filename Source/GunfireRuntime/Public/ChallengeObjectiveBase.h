#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "EObjectiveType.h"
#include "HierarchicalEditInterface.h"
#include "ChallengeObjectiveBase.generated.h"

class UChallenge;
class UChallengeManager;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UChallengeObjectiveBase : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UChallenge* Challenge;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UChallengeManager* ChallengeManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 RankIdx;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ID;
    
public:
    UChallengeObjectiveBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EObjectiveType GetObjectiveType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetObjectiveCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    FText GetDisplayLabel(UObject* WorldContextObject) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanIncrement() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

