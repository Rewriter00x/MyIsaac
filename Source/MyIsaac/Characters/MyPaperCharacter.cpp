// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"

FName AMyPaperCharacter::HeadSpriteComponentName(TEXT("HeadSprite"));
FName AMyPaperCharacter::BodySpriteComponentName(TEXT("BodySprite"));

AMyPaperCharacter::AMyPaperCharacter()
{
	HeadSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(HeadSpriteComponentName);
	BodySprite = CreateDefaultSubobject<UPaperFlipbookComponent>(BodySpriteComponentName);

	HeadSprite->SetupAttachment(GetCapsuleComponent());
	BodySprite->SetupAttachment(GetCapsuleComponent());
}


