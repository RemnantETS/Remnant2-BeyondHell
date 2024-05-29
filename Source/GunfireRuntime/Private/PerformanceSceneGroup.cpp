#include "PerformanceSceneGroup.h"

UPerformanceSceneGroup::UPerformanceSceneGroup() {
    this->Type = EPerfComponentType::None;
    this->State = EPerfSceneState::None;
    this->Visible = true;
    this->BurnUntilProfileFrameCount = 10;
    this->TotalProfileFrameCount = 16;
    this->CurProfileFrameCount = -1;
}

