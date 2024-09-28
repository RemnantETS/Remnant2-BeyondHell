#include "BossRushComponent_Base.h"
#include "Templates/SubclassOf.h"

UBossRushComponent_Base::UBossRushComponent_Base(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BRBuffTable = NULL;
}

void UBossRushComponent_Base::Reset_Implementation() {
}

void UBossRushComponent_Base::RefreshStoredBuffInfo(TSubclassOf<UActionBase> ActionFilterClass) {
}

FBossRushDataTableRow UBossRushComponent_Base::GetRowDataByNameID(FName NameID) const {
    return FBossRushDataTableRow{};
}

TArray<FName> UBossRushComponent_Base::GetBuffOptions() {
    return TArray<FName>();
}

TSubclassOf<UActionBuff> UBossRushComponent_Base::GetActionByNameID(FName NameID) {
    return NULL;
}

void UBossRushComponent_Base::DoBuff_Implementation(FName RowName) {
}

FName UBossRushComponent_Base::ChooseBuff(TArray<FPotentialBuff> PotentialBuffs) {
    return NAME_None;
}

bool UBossRushComponent_Base::CanGetBuff_Implementation(TSubclassOf<UActionBase> ActionClass) {
    return false;
}

bool UBossRushComponent_Base::CanGetAnyBuff_Implementation() {
    return false;
}


