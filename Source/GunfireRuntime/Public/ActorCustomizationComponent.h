#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ActorCustomizationSlot.h"
#include "OnCustomizationsChangedEventDelegate.h"
#include "OnStreamedActorCustomizationAppliedDelegate.h"
#include "OnStreamedActorCustomizationStreamDelegate.h"
#include "OnStreamedActorCustomizationsCompleteDelegate.h"
#include "ActorCustomizationComponent.generated.h"

class UActorCustomizationSet;
class UObject;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UActorCustomizationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Seed, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorCustomizationSet* CustomizationSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FActorCustomizationSlot> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CustomizationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimSoundTags;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesValidChildMeshes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ValidChildMeshes;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStreamedActorCustomizationApplied OnStreamedCustomizationApplied;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStreamedActorCustomizationsComplete OnCustomizationStreamingComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStreamedActorCustomizationStream OnBeginStreamCustomization;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCustomizationsChangedEvent OnCustomizationsChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> StreamingAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> CachedAssets;
    
public:
    UActorCustomizationComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UpdateSlots();
    
    UFUNCTION(BlueprintCallable)
    void StopAllStreamingRequests();
    
    UFUNCTION(BlueprintCallable)
    void SetupSlaveMeshes();
    
    UFUNCTION(BlueprintCallable)
    void SetSlotEnabled(FName SlotID, bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomizationAt(FName SlotID, int32 Idx);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomization(FName SlotID, FName CustomizationID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBPCustomizationTags(const TArray<FName>& InTags);
    
    UFUNCTION(BlueprintCallable)
    void PlayCustomizationEffect(FName NameID, bool bCache);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Seed();
    
    UFUNCTION(BlueprintCallable)
    void OnCustomizationLoaded(FName SlotID, FName CustomizationID, bool bCleared);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasOutstandingStreamingRequests();
    
    UFUNCTION(BlueprintCallable)
    FName GetSlotCustomizationID(FName SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UObject> GetPreviewMeshForCustomization(FName SlotID, FName CustomizationID, bool bAllowStaticMeshes, bool bAllowSkeletalMeshes) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumCustomizationsForSlotID(FName SlotID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIconForCustomization(FName SlotID, FName CustomizationID, UPARAM(Ref) TSoftObjectPtr<UTexture2D>& OutIcon) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDisplayColorForCustomization(FName SlotID, FName CustomizationID, UPARAM(Ref) FLinearColor& OutColor) const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetCustomizationPositionInSlot(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    FName GetCustomizationAt(FName SlotID, int32 Idx);
    
    UFUNCTION(BlueprintCallable)
    bool GetAllCustomizationsForSlot(FName SlotID, UPARAM(Ref) TArray<FName>& OutCustomizations);
    
    UFUNCTION(BlueprintCallable)
    void ClearCustomization(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    void AddBPCustomizationTags(const TArray<FName>& InTags);
    
};

