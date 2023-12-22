#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HierarchicalEditInterface.h"
#include "InheritableObject.h"
#include "ActorCustomizationID.generated.h"

class UActorCustomization;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UActorCustomizationID : public UInheritableObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorCustomization*> Customizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequireIDsForColorDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DisplayColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLinearColor> ColorsByID;
    
    UActorCustomizationID();
    
    // Fix for true pure virtual functions not being implemented
};

