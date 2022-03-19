// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPaperCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYISAAC_API AMyPlayableCharacter : public AMyPaperCharacter
{
	GENERATED_BODY()

	static FName SpringArmComponentName;
	static FName CameraComponentName;
	
	float XAxis;
	float YAxis;
	int32 Shooting = 0;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USpringArmComponent* SpringArm;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* HeadDownFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
    UPaperFlipbook* HeadLeftFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* HeadRightFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* HeadUpFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* BodyRightFlipbook;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* BodyUpFlipbook;
    
public:
    AMyPlayableCharacter();

private:
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void SetHeadShootingFlipbook(UPaperFlipbook* NewFlipbook);
	void CheckNotShooting();
	void ShootRight();
	void StopShootingRight();
	void ShootLeft();
	void StopShootingLeft();
	void ShootUp();
	void StopShootingUp();
	void ShootDown();
	void StopShootingDown();
	void SetStandFlipbook();
	void UpdateAnimations();

public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds) override;
};
