// Copyright MNL Games


#include "UI/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerState = WCParams.PlayerState;
	PlayerController= WCParams.PlayerController;
	AttributeSet = WCParams.AttributeSet;
	AbilitySystemComponent=WCParams.AbilitySystemComponent;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	
}
