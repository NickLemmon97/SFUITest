// Copyright Nick Lemmon


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

void UMainMenu::ClickedPlay()
{
	OwningMenu->ModeButtons->AddToViewport();
}
