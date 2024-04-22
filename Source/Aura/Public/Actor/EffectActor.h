// Copyright MNL Games

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "EffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AEffectActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> InstantGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DurationGameplayEffect;
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffect(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
};
