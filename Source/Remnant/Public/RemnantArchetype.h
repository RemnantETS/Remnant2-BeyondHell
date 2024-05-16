#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ArchetypeStartingTrait.h"
#include "Templates/SubclassOf.h"
#include "RemnantArchetype.generated.h"

class AItem;
class UArchetype;
class URemnantArchetype;
class UTexture2D;

UCLASS(Blueprintable)
class REMNANT_API URemnantArchetype : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = "true"))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true, MultiLine = "true"))
    FText BriefDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> FlavorTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Difficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Image;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UArchetype> Archetype;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> Engram;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AItem>> StartingGear;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArchetypeStartingTrait> StartingTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UITags;
    
    URemnantArchetype();
    UFUNCTION(BlueprintCallable)
    static TSoftClassPtr<AItem> GetEngramItem(TSoftClassPtr<URemnantArchetype> ArchetypeSoft);
    
    UFUNCTION(BlueprintCallable)
    static TSoftClassPtr<UArchetype> GetArchetypeTrait(TSoftClassPtr<URemnantArchetype> ArchetypeSoft);
    
};

