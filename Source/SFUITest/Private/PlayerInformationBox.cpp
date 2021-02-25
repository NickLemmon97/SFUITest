// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/PlayerInformationBox.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "../Public/MyGameInstance.h"

void UPlayerInformationBox::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	SelectButton->OnClicked.AddDynamic(this, &UPlayerInformationBox::SelectPlayer);
}

void UPlayerInformationBox::SetPlayerInformation(FPlayerInformation player)
{
	NameText->SetText(player.PlayerName );
	DescText->SetText(player.PlayerDescription );
	LongText->SetText(player.PlayerLongDesc );

	//Percent is 0 to 1 
	HealthBar-> SetPercent((300.0f / player.Health) / 10.0f);
	OxygenBar-> SetPercent((300.0f / player.Oxygen) / 10.0f);
	StaminaBar->SetPercent((300.0f/player.Stamina)  / 10.0f);
}

void UPlayerInformationBox::SelectPlayer()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Game"));
}