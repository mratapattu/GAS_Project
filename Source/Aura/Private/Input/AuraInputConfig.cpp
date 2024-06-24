// Copyright MNL Games


#include "Input/AuraInputConfig.h"

UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(FGameplayTag& InputTag)
{
	for (FAuraInputAction& InputAction:AbilityInputActions)
	{
		if(InputAction.InputTag == InputTag)
		{
			return InputAction.InputAction;
		}
	}

	return nullptr;
}
