// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseAttack.generated.h"

UCLASS()
class TAREA1_GAMEPLAYTAGS_API UBaseAttack : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Attack(AActor* AttackOwner);
};
