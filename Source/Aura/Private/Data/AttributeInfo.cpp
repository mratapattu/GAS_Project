// Copyright MNL Games


#include "Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for(FAuraAttributeInfo info:AttributeInformation)
	{
		if(info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return info;
		}
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant find info for attribute tag [%s] on AttributeInfo [%s]."),
			*AttributeTag.ToString(),*GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
