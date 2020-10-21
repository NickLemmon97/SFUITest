// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\MyHUD.h"
#include "..\Public\MenuEntirety.h"

void AMyHUD::BeginPlay()
{
	if (THEMainMenuClass)
	{
		Menu = CreateWidget<UMenuEntirety>(GetWorld(), THEMainMenuClass);
		if (Menu)
			Menu->AddToViewport();
	}
}
