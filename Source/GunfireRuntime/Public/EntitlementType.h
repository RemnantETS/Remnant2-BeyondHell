#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EntitlementEntry.h"
#include "Templates/SubclassOf.h"
#include "EntitlementType.generated.h"

class UEntitlementType;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEntitlementType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEntitlementEntry> PlatformEntitlements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText MissingEntitlementStatusMessage;
    
    UEntitlementType();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool IsLicensedObject(UObject* WorldContextObject, UObject* Object);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool IsLicensedClass(UObject* WorldContextObject, UClass* Class);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool HasEntitlement(UObject* WorldContextObject, TSubclassOf<UEntitlementType> Entitlement);
    
};

