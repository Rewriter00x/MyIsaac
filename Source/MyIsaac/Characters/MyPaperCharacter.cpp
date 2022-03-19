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
	BodySprite->SetupAttachment(HeadSprite);

	HeadSprite->SetWorldLocation(FVector(0.0f, -3.0f, 0.0f));
	HeadSprite->SetUsingAbsoluteRotation(true);
	HeadSprite->SetWorldRotation(FRotator(0.0f,0.0f,-90.0f));

	BodySprite->SetRelativeLocation(FVector(0.0f, -1.0f, -15.0f));
	
	HeadSprite->Stop();
	BodySprite->Stop();

	GetCapsuleComponent()->SetCapsuleRadius(17.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(17.0f);
}


