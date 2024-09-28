#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "EPrismSegmentCategory.h"
#include "PrismHasNumSegmentsCondition.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UPrismHasNumSegmentsCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredSements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredSegmentsLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredComboSements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredSegmentsOfCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPrismSegmentCategory> RequiredCategories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPrismSegmentCategory> CategoriesThatCountTwice;
    
    UPrismHasNumSegmentsCondition();

};

