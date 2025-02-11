// Fill out your copyright notice in the Description page of Project Settings.

#include "Pokemon/PokeAttack.h"
#include "Pokemon/PokemonCharacter.h"

float UPokeAttack::GetEfficiency(const FGameplayTag& InDefenseType)
{
	const float Efficiency = 1.0f;

	TArray<FElementEfficiency*> OutData;
	EfficiencyData->GetAllRows(TEXT(""), OutData);

	if(!OutData.IsEmpty())
	{
		FElementEfficiency** Attr = OutData.FindByPredicate([this](FElementEfficiency* Row)
		{
			return Row->ElementTag.MatchesTag(AttackType);
		});
			
		if(Attr) AttackEfficiency = *Attr;
	}
	
	if(AttackEfficiency)
	{
		for (const TPair<FGameplayTag, float>& AttackEffective : AttackEfficiency->Efficiency)
		{
			if(AttackEffective.Key.MatchesTag(InDefenseType)) return AttackEffective.Value;
		}
	}
	return Efficiency;
}

void UPokeAttack::Init(const FPokeAttackInfo& PokeAttackInfo)
{
	AttackType = PokeAttackInfo.ElementTag;
	Damage = PokeAttackInfo.Damage;
	AttackUses = PokeAttackInfo.MaxUses;
}

void UPokeAttack::Attack(APokemonCharacter* Instigator, APokemonCharacter* Target)
{
	const float Efficiency = GetEfficiency(Target->ElementType);

	FString AttackInfo = FString::Printf(TEXT("%s ataca a %s haciendole %.1f de daño con una eficacia de %.1f (%s contra %s)"),
		*Instigator->PokemonName,
		*Target->PokemonName,
		Damage * Efficiency,
		Efficiency,
		*AttackType.ToString(),
		*Target->ElementType.ToString());
	
	GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Orange, AttackInfo);
}