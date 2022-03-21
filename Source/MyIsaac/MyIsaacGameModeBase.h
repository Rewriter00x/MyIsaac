// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyIsaacGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYISAAC_API AMyIsaacGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> WidgetClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UMyPlayerHUD* PlayerHUD;

public:
	AMyIsaacGameModeBase();

	virtual void BeginPlay() override;;
	
};
