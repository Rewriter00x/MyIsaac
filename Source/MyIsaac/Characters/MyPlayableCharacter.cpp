// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayableCharacter.h"
#include "Components/CapsuleComponent.h"

FName AMyPlayableCharacter::SpringArmComponentName(TEXT("SpringArm"));
FName AMyPlayableCharacter::CameraComponentName(TEXT("Camera"));

AMyPlayableCharacter::AMyPlayableCharacter()
{
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
}

void AMyPlayableCharacter::MoveY(float AxisValue)
{
	AddMovementInput(FVector(0.0f, -1.0f, 0.0f), AxisValue);
}

void AMyPlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPlayableCharacter::MoveX);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &AMyPlayableCharacter::MoveY);
}


