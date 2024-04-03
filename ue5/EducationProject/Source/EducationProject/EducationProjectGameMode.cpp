// Copyright Epic Games, Inc. All Rights Reserved.

#include "EducationProjectGameMode.h"
#include "EducationProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEducationProjectGameMode::AEducationProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
