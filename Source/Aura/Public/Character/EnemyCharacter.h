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

	virtual void Highlight() override;
	virtual void UnHighlight() override;

	virtual void BeginPlay() override;
	
	AEnemyCharacter();
	
};
