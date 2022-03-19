// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyIsaacGameModeBase.h"

AMyIsaacGameModeBase::AMyIsaacGameModeBase()
{
	// Set default pawn class to our character
	//DefaultPawnClass = AMyPlayableCharacter::GetClass();
	ConstructorHelpers::FClassFinder<APawn> BP_MyPlayableCharacter(TEXT("/Game/Blueprints/Characters/BP_MyPlayableCharacter"));
	if (BP_MyPlayableCharacter.Class != NULL)
		DefaultPawnClass = BP_MyPlayableCharacter.Class;
}
