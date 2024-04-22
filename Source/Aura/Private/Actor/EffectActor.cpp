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
	
	UAbilitySystemComponent* ActorASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	FGameplayEffectContextHandle EffectContextHandle = ActorASC->MakeEffectContext();
	FGameplayEffectSpecHandle EffectSpecHandle = ActorASC->MakeOutgoingSpec(GameplayEffectClass,1.0f, EffectContextHandle);
	ActorASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


