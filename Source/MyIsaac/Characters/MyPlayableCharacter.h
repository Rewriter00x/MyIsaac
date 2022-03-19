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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USpringArmComponent* SpringArm;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UCameraComponent* Camera;
    
public:
    AMyPlayableCharacter();
	
};
