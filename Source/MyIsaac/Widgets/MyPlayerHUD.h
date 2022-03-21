// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYISAAC_API UMyPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBox;

protected:
	virtual void NativeConstruct() override;
};
