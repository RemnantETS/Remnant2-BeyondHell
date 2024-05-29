#include "OnlineSessionDetailsRemnant.h"

FOnlineSessionDetailsRemnant::FOnlineSessionDetailsRemnant() {
    this->CharacterType = ERemnantCharacterType::Standard;
    this->PowerLevel = 0;
    this->Difficulty = 0;
    this->GameMode = EQuestMode::Campaign;
    this->NumPlayers = 0;
    this->Platform = (EMatchmakingPlatform)0;

}

