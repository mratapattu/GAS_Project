// Copyright MNL Games


#include "UI/AuraUserWidget.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidget)
{
	WidgetController = InWidget;
	OnWidgetControllerSet();
}

