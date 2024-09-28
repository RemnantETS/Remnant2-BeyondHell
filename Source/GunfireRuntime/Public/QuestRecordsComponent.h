#pragma once
#include "CoreMinimal.h"
#include "QuestRecordsComponent.generated.h"

class APlayerState;
class AQuest;
class UPlayerRecords;
class UQuestRecordsInfoSet;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UQuestRecordsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuestRecordsInfoSet* QuestRecordsRules;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<UPlayerRecords*> Records;
    
public:
    UQuestRecordsComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void StartNewRecordsSession(AQuest* RootQuest);
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitializeRecordsForQuest(AQuest* Quest);
    
    UFUNCTION(BlueprintCallable)
    void InitializeRecordsForPlayer(APlayerState* ContextPlayer);
    
};

