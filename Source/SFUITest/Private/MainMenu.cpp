// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/MainMenu.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "../Public/MenuEntirety.h"
#include "../Public/SingleOnlineButtons.h"


void UMainMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	PlayButton->OnClicked.AddDynamic(this, &UMainMenu::ClickedPlay);
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMainMenu::NativeDestruct()
{
	Super::NativeDestruct();
}

void UMainMenu::ClickedPlay()
{
	OwningMenu->ModeButtons->AddToViewport();
}


