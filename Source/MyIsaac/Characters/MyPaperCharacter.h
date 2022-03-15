// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"

#include "GameFramework/Character.h"
#include "MyPaperCharacter.generated.h"

UCLASS()
class MYISAAC_API AMyPaperCharacter : public ACharacter
{
	GENERATED_BODY()
	
	static FName HeadSpriteComponentName;
	static FName BodySpriteComponentName;

protected:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UPaperFlipbookComponent* HeadSprite;
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	UPaperFlipbookComponent* BodySprite;
public:

	AMyPaperCharacter();

	UPaperFlipbookComponent* GetHeadSprite() const { return HeadSprite; }
	UPaperFlipbookComponent* GetBodySprite() const { return BodySprite; }
};
