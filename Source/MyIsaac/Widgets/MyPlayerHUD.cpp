// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerHUD.h"

#include "Components/TextBlock.h"

void UMyPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();

	TextBox->SetText(FText::FromString("HELLO WORLD"));
}
