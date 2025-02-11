// Fill out your copyright notice in the Description page of Project Settings.

#include "Pokemon/PokemonCharacter.h"
#include "Pokemon/PokeAttack.h"

// Sets default values
APokemonCharacter::APokemonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APokemonCharacter::InitAttacksData()
{
	if (AttackData && AttackList.Num() > 0)
	{
		TArray<FPokeAttackInfo*> OutData;
		AttackData->GetAllRows(TEXT(""), OutData);

		if (!OutData.IsEmpty())
		{
			for (FGameplayTag Attack : AttackList)
			{
				for (const FPokeAttackInfo* AttackInfo : OutData)
				{
					if (AttackInfo && AttackInfo->AttackTag.MatchesTag(Attack))
					{
						UPokeAttack* AttackInstance = NewObject<UPokeAttack>(GetTransientPackage(), AttackInfo->AttackClass);
						AttackInstance->Init(*AttackInfo);
						AttacksSelected.Add(AttackInstance, AttackInfo->MaxUses);
						break;
					}
				}
			}
		}
	}
}

bool APokemonCharacter::TryToAttack(UPokeAttack* AttackAction)
{
	if(!PokemonTarget) return false;
	
	AttackAction->Attack(this, PokemonTarget);
	return true;
}

// Called when the game starts or when spawned
void APokemonCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAttacksData();
	
	if(AttackList.Num() > 0)
	{
		for (auto It = AttacksSelected.CreateIterator(); It; ++It)
		{
			UPokeAttack* AttackClass = It.Key();
			int32& RemainingAttackUses = It.Value();
		
			if(RemainingAttackUses == 0) continue;
		
			if(TryToAttack(AttackClass))
			{
				RemainingAttackUses--;			
			}
		}
	}
}

// Called every frame
void APokemonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APokemonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

