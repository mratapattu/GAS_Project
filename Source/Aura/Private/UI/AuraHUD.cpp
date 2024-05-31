// Copyright MNL Games


#include "UI/AuraHUD.h"

#include "UI/AuraUserWidget.h"
#include "UI/AttributeMenuWidgetController.h"
#include "UI/OverlayWidgetController.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraHUD::InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,  UAttributeSet* AS)
{
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(),OverlayWidgetClass);
	//OverlayWidget->AddToViewport();

	OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
	OverlayWidgetController->BindCallbacksToDependencies();
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();

	OverlayWidget->AddToViewport();
	
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController==nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return  OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& Params)
{
	if (AttributeMenuWidgetController==nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(Params);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}

	return  AttributeMenuWidgetController;
}


