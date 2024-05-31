// Copyright MNL Games


#include "Actor/EffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Serialization/GameplayEffectContextNetSerializer.h"


AEffectActor::AEffectActor()
{
 	PrimaryActorTick.bCanEverTick = false;
	
}




void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEffectActor::ApplyGameplayEffect(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	check(Cast<IAbilitySystemInterface>(TargetActor));
	
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass,ActorLevel, EffectContextHandle);
	FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinite && InfiniteRemovalPolicy==EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}

}

void AEffectActor::OnOverlap(AActor* TargetActor)
{
	if(InstantApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyGameplayEffect(TargetActor,InstantGameplayEffect);
	}
	if(DurationApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyGameplayEffect(TargetActor,DurationGameplayEffect);
	}
	if(InfiniteApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyGameplayEffect(TargetActor,InfiniteGameplayEffect);
	}
}

void AEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if(InstantApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyGameplayEffect(TargetActor,InstantGameplayEffect);
	}
	if(DurationApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyGameplayEffect(TargetActor,DurationGameplayEffect);
	}
	if(InfiniteApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyGameplayEffect(TargetActor,DurationGameplayEffect);
	}
	if(InfiniteRemovalPolicy==EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;

		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair:ActiveEffectHandles)
		{
			if (TargetASC == HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key,1);
				HandlesToRemove.Add(HandlePair.Key);
			}
			for (FActiveGameplayEffectHandle& handle:HandlesToRemove)
			{
				ActiveEffectHandles.FindAndRemoveChecked(handle);
			}
		}
	}
}


