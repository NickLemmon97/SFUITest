// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/PlayerFaceSelect.h"
#include "../Public/MyGameInstance.h"

void UPlayerFaceSelect::UseMyPlayer()
{
	if (player != nullptr)
	{
		APlayerIGuess* p = Cast<APlayerIGuess>(player->GetDefaultObject());
		OwningMenu->SetPlayerInformation(p->playerInfo);

		UMyGameInstance* inst = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

		if (inst)
		{
			inst->playerTemplate = player;
		}
	}
}