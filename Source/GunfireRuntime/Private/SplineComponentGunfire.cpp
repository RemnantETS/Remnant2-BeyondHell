#include "SplineComponentGunfire.h"

USplineComponentGunfire::USplineComponentGunfire(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Increments = 500.00f;
    this->Length = 0.00f;
    this->NumPoints = 0;
}

TArray<FSplineData> USplineComponentGunfire::SubdivideSpline() {
    return TArray<FSplineData>();
}

TArray<FSplineData> USplineComponentGunfire::GetSplineData() const {
    return TArray<FSplineData>();
}

TArray<FSplineData> USplineComponentGunfire::ComputeParallelTransport(const TArray<float> DistsAlongSpline) {
    return TArray<FSplineData>();
}


