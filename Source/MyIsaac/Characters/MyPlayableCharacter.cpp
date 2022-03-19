// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayableCharacter.h"
#include "Components/CapsuleComponent.h"

FName AMyPlayableCharacter::SpringArmComponentName(TEXT("SpringArm"));
FName AMyPlayableCharacter::CameraComponentName(TEXT("Camera"));

AMyPlayableCharacter::AMyPlayableCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(SpringArmComponentName);
	Camera = CreateDefaultSubobject<UCameraComponent>(CameraComponentName);

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->TargetArmLength = 200.0f;
    SpringArm->SetWorldRotation(FRotator(-90.0f,-90.0f,0.0f));
    Camera->SetProjectionMode(ECameraProjectionMode::Orthographic);
}

void AMyPlayableCharacter::MoveX(float AxisValue)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), AxisValue);
	XAxis = AxisValue;
}

void AMyPlayableCharacter::MoveY(float AxisValue)
{
	AddMovementInput(FVector(0.0f, -1.0f, 0.0f), AxisValue);
	YAxis = AxisValue;
}

void AMyPlayableCharacter::SetHeadShootingFlipbook(UPaperFlipbook* NewFlipbook)
{
	HeadSprite->SetFlipbook(NewFlipbook);
	HeadSprite->Play();
}

void AMyPlayableCharacter::CheckNotShooting()
{
	if (!Shooting)
	{
		HeadSprite->SetFlipbook(HeadDownFlipbook);
		HeadSprite->SetPlaybackPosition(0.0f, false);
		HeadSprite->Stop();
	}
}

void AMyPlayableCharacter::ShootRight()
{
	Shooting++;
	SetHeadShootingFlipbook(HeadRightFlipbook);
}

void AMyPlayableCharacter::StopShootingRight()
{
	Shooting--;
	CheckNotShooting();
}

void AMyPlayableCharacter::ShootLeft()
{
	Shooting++;
	SetHeadShootingFlipbook(HeadLeftFlipbook);
}

void AMyPlayableCharacter::StopShootingLeft()
{
	Shooting--;
	CheckNotShooting();
}

void AMyPlayableCharacter::ShootUp()
{
	Shooting++;
	SetHeadShootingFlipbook(HeadUpFlipbook);
}

void AMyPlayableCharacter::StopShootingUp()
{
	Shooting--;
	CheckNotShooting();
}

void AMyPlayableCharacter::ShootDown()
{
	Shooting++;
	SetHeadShootingFlipbook(HeadDownFlipbook);
}

void AMyPlayableCharacter::StopShootingDown()
{
	Shooting--;
	CheckNotShooting();
}

void AMyPlayableCharacter::SetStandFlipbook()
{
	BodySprite->SetFlipbook(BodyUpFlipbook);
	BodySprite->SetPlaybackPosition(0.0f, false);
	BodySprite->Stop();
	if (!Shooting)
		HeadSprite->SetFlipbook(HeadDownFlipbook);
}

void AMyPlayableCharacter::UpdateAnimations()
{
	// If animation is playing and we are standing set animation to stand
	if (BodySprite->IsPlaying() && XAxis == 0.0f && YAxis == 0.0f)
	{
		SetStandFlipbook();
		return;
	}
	
	if (YAxis != 0.0f)
	{
		BodySprite->SetFlipbook(BodyUpFlipbook);
		if (!Shooting)
			HeadSprite->SetFlipbook(YAxis < 0.0f ? HeadDownFlipbook : HeadUpFlipbook);
		if (!BodySprite->IsPlaying())
			BodySprite->Play();
		return;
	}

	if (XAxis != 0.0f)
	{
		BodySprite->SetFlipbook(BodyRightFlipbook);
		BodySprite->SetRelativeRotation(XAxis < 0.0f ? FRotator(0.0f, 180.0f, 0.0f) : FRotator(0.0f));
		if (!Shooting)
			HeadSprite->SetFlipbook(XAxis < 0.0f ? HeadLeftFlipbook : HeadRightFlipbook);
		if (!BodySprite->IsPlaying())
			BodySprite->Play();
	}
}

void AMyPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPlayableCharacter::MoveX);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &AMyPlayableCharacter::MoveY);

	PlayerInputComponent->BindAction(TEXT("ShootRight"), IE_Pressed, this, &AMyPlayableCharacter::ShootRight);
	PlayerInputComponent->BindAction(TEXT("ShootRight"), IE_Released, this, &AMyPlayableCharacter::StopShootingRight);
	PlayerInputComponent->BindAction(TEXT("ShootLeft"), IE_Pressed, this, &AMyPlayableCharacter::ShootLeft);
	PlayerInputComponent->BindAction(TEXT("ShootLeft"), IE_Released, this, &AMyPlayableCharacter::StopShootingLeft);
	PlayerInputComponent->BindAction(TEXT("ShootUp"), IE_Pressed, this, &AMyPlayableCharacter::ShootUp);
	PlayerInputComponent->BindAction(TEXT("ShootUp"), IE_Released, this, &AMyPlayableCharacter::StopShootingUp);
	PlayerInputComponent->BindAction(TEXT("ShootDown"), IE_Pressed, this, &AMyPlayableCharacter::ShootDown);
	PlayerInputComponent->BindAction(TEXT("ShootDown"), IE_Released, this, &AMyPlayableCharacter::StopShootingDown);
}

void AMyPlayableCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateAnimations();
}


