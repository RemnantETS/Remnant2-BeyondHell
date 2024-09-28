#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "LorePage.h"
#include "LoreItem.generated.h"

class UImageSet;
class UObject;

UCLASS(Blueprintable)
class REMNANT_API ALoreItem : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoOpenUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideHideReadUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLorePage> Pages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UImageSet> LoreImageSet;
    
    ALoreItem(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LoreNotify(UObject* WorldContextObject, const FLorePage& Page);
    
};

