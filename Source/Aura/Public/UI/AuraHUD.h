// Copyright MNL Games

#pragma once

#include "CoreMinimal.h"
#include "AuraUserWidget.h"
#include "OverlayWidgetController.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	void InitOverlayWidget(APlayerState* PS, APlayerController* PC, UAttributeSet* AS,
	UAbilitySystemComponent* ASC);

	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
