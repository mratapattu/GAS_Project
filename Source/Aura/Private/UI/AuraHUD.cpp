// Copyright MNL Games


#include "UI/AuraHUD.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraHUD::InitOverlayWidget(APlayerState* PS, APlayerController* PC, UAttributeSet* AS, UAbilitySystemComponent* ASC)
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
