#pragma once
#include "CoreMinimal.h"
#include "E:\Epic Games\UE_5.2\Engine\Source\Runtime\Engine\Classes\Components\SplineComponent.h"
#include "SplineData.h"
#include "SplineComponentGunfire.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USplineComponentGunfire : public USplineComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Increments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumPoints;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> PointDistances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplineData> SplineData;
    
public:
    USplineComponentGunfire(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    TArray<FSplineData> SubdivideSpline();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSplineData> GetSplineData() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FSplineData> ComputeParallelTransport(const TArray<float> DistsAlongSpline);
    
};

