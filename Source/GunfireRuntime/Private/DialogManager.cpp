#include "DialogManager.h"
#include "Templates/SubclassOf.h"

bool UDialogManager::StopDialog(AActor* Source) {
    return false;
}

bool UDialogManager::StopActiveDialog() {
    return false;
}

UDialogInstance* UDialogManager::PlayDialogFromTargetSoundSet(AActor* Source, FName SoundID, const FGunfireAudioPlayParams& PlayParams, const FGunfireAudioAttachParams& AttachParams, bool IgnoreVocalRange, bool UseFacialAnimation, TSubclassOf<UDialog_Emote> Emote, bool LocalOnly) {
    return NULL;
}

UDialogInstance* UDialogManager::PlayDialogFromSound(AActor* Source, FSoftSoundGunfire Dialog) {
    return NULL;
}

UDialogInstance* UDialogManager::PlayDialog(AActor* Source, const FDialogInfo& Info) {
    return NULL;
}

UDialogManager* UDialogManager::GetDialogManager(UObject* WorldContextObject) {
    return NULL;
}

UDialogInstance* UDialogManager::GetActiveDialog(AActor* Source) {
    return NULL;
}

UDialogManager::UDialogManager() {
    this->DialogCullDistance = 3500.00f;
}

