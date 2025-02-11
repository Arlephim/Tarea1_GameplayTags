// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "PokemonCharacter.generated.h"

class UPokeAttack;

USTRUCT()
struct FPokeAttackInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FGameplayTag AttackTag;
	UPROPERTY(EditAnywhere)	FText Name;
	UPROPERTY(EditAnywhere)	FGameplayTag ElementTag;
	UPROPERTY(EditAnywhere)	TSubclassOf<UPokeAttack> AttackClass;
	UPROPERTY(EditAnywhere)	float Damage;
	UPROPERTY(EditAnywhere)	int32 MaxUses;
};

UCLASS()
class TAREA1_GAMEPLAYTAGS_API APokemonCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* AttackData;
	
	void InitAttacksData();

public:
	// Sets default values for this character's properties
	APokemonCharacter();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	FString PokemonName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	TMap<UPokeAttack*, int32> AttacksSelected;	

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon)
	APokemonCharacter* PokemonTarget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	TArray<FGameplayTag> AttackList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag ElementType;

	UFUNCTION(BlueprintCallable)
	virtual bool TryToAttack(UPokeAttack* AttackAction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
