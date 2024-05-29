#include "EntitlementType.h"
#include "Templates/SubclassOf.h"

bool UEntitlementType::IsLicensedObject(UObject* WorldContextObject, UObject* Object) {
    return false;
}

bool UEntitlementType::IsLicensedClass(UObject* WorldContextObject, UClass* Class) {
    return false;
}

bool UEntitlementType::HasEntitlement(UObject* WorldContextObject, TSubclassOf<UEntitlementType> Entitlement) {
    return false;
}

UEntitlementType::UEntitlementType() {
}

