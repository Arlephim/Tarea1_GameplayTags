// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeAttack.generated.h"

USTRUCT(BlueprintType)
struct FElementEfficiency : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ElementTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, float> Efficiency;
};

struct FPokeAttackInfo;
class APokemonCharacter;
class UPokeAttack;

UCLASS(BlueprintType, Blueprintable)
class TAREA1_GAMEPLAYTAGS_API UPokeAttack : public UObject
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	FGameplayTag AttackType;

	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	float Damage;
	
	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 AttackUses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* EfficiencyData;
	
	FElementEfficiency* AttackEfficiency;

	float GetEfficiency(const FGameplayTag& DefenseType);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttackIdTag;

	virtual void Init(const FPokeAttackInfo& PokeAttackInfo);

	virtual void Attack(APokemonCharacter* Instigator, APokemonCharacter* Target);
};
