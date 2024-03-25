// Copyright MNL Games


#include "Character/EnemyCharacter.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/Aura.h"

AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
	
}

void AEnemyCharacter::Highlight()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(HIGHLIGHT_CUSTOM_DEPTH);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(HIGHLIGHT_CUSTOM_DEPTH);
	
}

void AEnemyCharacter::UnHighlight()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}


