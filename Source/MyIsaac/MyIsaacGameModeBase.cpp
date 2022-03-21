// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyIsaacGameModeBase.h"
#include "Blueprint/UserWidget.h"

#include "Widgets/MyPlayerHUD.h"

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

	ConstructorHelpers::FClassFinder<UUserWidget> BP_MyPlayerWidget(TEXT("/Game/Blueprints/Widgets/BP_MyPlayerHUD"));
	if (BP_MyIsaacCharacter.Class != NULL)
		WidgetClass = BP_MyPlayerWidget.Class;

	
}

void AMyIsaacGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(WidgetClass))
	{
		PlayerHUD = Cast<UMyPlayerHUD>(CreateWidget(GetWorld(), WidgetClass));
		if(PlayerHUD)
			PlayerHUD->AddToViewport();
	}
}
