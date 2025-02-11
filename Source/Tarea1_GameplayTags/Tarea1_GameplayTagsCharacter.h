// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "Tarea1_GameplayTagsCharacter.generated.h"

class UBaseAttack;

USTRUCT()
struct FCharacterAttributes : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FGameplayTag CharacterClassTag;
	UPROPERTY(EditAnywhere)	float Health;
	UPROPERTY(EditAnywhere)	float AttackStrength;
	UPROPERTY(EditAnywhere)	float Speed;
	UPROPERTY(EditAnywhere)	UAnimMontage* AttackAnimation;
	UPROPERTY(EditAnywhere)	TSubclassOf<UBaseAttack> PrimaryAttack;
};

UCLASS(Blueprintable)
class ATarea1_GameplayTagsCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FGameplayTag CharacterClassTag;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FCharacterAttributes* CharacterAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	UDataTable* CharacterData;

public:
	ATarea1_GameplayTagsCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void Attack();

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};
