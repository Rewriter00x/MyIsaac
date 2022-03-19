// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyIsaacGameModeBase.h"

AMyIsaacGameModeBase::AMyIsaacGameModeBase()
{
	// Set default pawn class to our character
	
	// DefaultPawnClass = AMyIsaacCharacter::GetClass();
	
	// ConstructorHelpers::FClassFinder<APawn> BP_MyPlayableCharacter(TEXT("/Game/Blueprints/Characters/BP_MyPlayableCharacter"));
	// if (BP_MyPlayableCharacter.Class != NULL)
	// 	DefaultPawnClass = BP_MyPlayableCharacter.Class;

	ConstructorHelpers::FClassFinder<APawn> BP_MyIsaacCharacter(TEXT("/Game/Blueprints/Characters/BP_MyIsaacCharacter"));
	if (BP_MyIsaacCharacter.Class != NULL)
		DefaultPawnClass = BP_MyIsaacCharacter.Class;
}
