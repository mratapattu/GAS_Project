// Copyright MNL Games

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interaction/ActorHighlightInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ACharacterBase, public IActorHighlightInterface
{
	GENERATED_BODY()

	

public:

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	virtual int32 GetPlayerLevel() override;

protected:
	
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	AEnemyCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults")
	int32 Level = 1;
	
	
};
