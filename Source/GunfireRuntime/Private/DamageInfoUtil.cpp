#include "DamageInfoUtil.h"
#include "Templates/SubclassOf.h"

void UDamageInfoUtil::SetPower(FDamageInfo& Info, int32 Power) {
}

void UDamageInfoUtil::SetIsSecondaryDamage(FDamageInfo& Info, bool IsSecondaryDamage) {
}

void UDamageInfoUtil::SetDamageType(FDamageInfo& Info, TSubclassOf<UDamageType> DamageType) {
}

void UDamageInfoUtil::SetDamage(FDamageInfo& Info, int32 Damage) {
}

void UDamageInfoUtil::ModifyDamage(FDamageInfo& Info, float Damage, float DamageMod, float DamageScalar) {
}

void UDamageInfoUtil::ModifyCrit(FDamageInfo& Info, float CritChance, float CritDamageMod) {
}

void UDamageInfoUtil::MarkRequiresClientAuthorization(FDamageInfo& Info) {
}

void UDamageInfoUtil::MarkClientAuthorizedDamage(FDamageInfo& Info) {
}

float UDamageInfoUtil::GetTotalAppliedDamage(const FDamageInfo& Info) {
    return 0.0f;
}

UDamageInfoUtil::UDamageInfoUtil() {
}

