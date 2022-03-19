// Fill out your copyright notice in the Description page of Project Settings.


#include "MyIsaacCharacter.h"
#include "PaperFlipbook.h"

AMyIsaacCharacter::AMyIsaacCharacter()
{
	HeadDownFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Head/FB_IsaacHeadDown"));
	HeadLeftFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Head/FB_IsaacHeadLeft"));
	HeadRightFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Head/FB_IsaacHeadRight"));
	HeadUpFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Head/FB_IsaacHeadUp"));
	BodyRightFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Body/FB_IsaacBodyRight"));
	BodyUpFlipbook = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Flipbooks/Characters/Isaac/Body/FB_IsaacBodyUp"));

	HeadSprite->SetFlipbook(HeadDownFlipbook);
	BodySprite->SetFlipbook(BodyUpFlipbook);
}
