// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tarea1_GameplayTagsGameMode.h"
#include "Tarea1_GameplayTagsPlayerController.h"
#include "Tarea1_GameplayTagsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATarea1_GameplayTagsGameMode::ATarea1_GameplayTagsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATarea1_GameplayTagsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}