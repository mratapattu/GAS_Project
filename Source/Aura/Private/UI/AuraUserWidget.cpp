// Copyright MNL Games


#include "UI/AuraUserWidget.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnWidgetControllerSet();
}

