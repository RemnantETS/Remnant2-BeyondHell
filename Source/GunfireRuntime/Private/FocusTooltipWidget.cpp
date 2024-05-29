#include "FocusTooltipWidget.h"

void UFocusTooltipWidget::OnParentShowTooltip(UWidget* SourceWidget) {
}

void UFocusTooltipWidget::OnParentHideTooltip(UWidget* SourceWidget) {
}

bool UFocusTooltipWidget::IsTooltipShowing() const {
    return false;
}

UFocusTooltipWidget::UFocusTooltipWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->TooltipParentWidget = NULL;
    this->ParentWidgetFocusButton = NULL;
}

