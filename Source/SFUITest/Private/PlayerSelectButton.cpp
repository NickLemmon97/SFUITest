// Copyright Nick Lemmon


#include "../Public/PlayerSelectButton.h"
#include "../Public/MyGameInstance.h"

void UPlayerSelectButton::UseMyPlayer()
{
	if (player != nullptr)
	{
		//Get the player information from the Default Object and set it on the menu
		APlayerCharacter* p = Cast<APlayerCharacter>(player->GetDefaultObject());
		OwningMenu->SetPlayerInformation(p->playerInfo);

		//Notify the game instance of our selected player that we would like to spawn
		UMyGameInstance* inst = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		if (inst)
		{
			inst->playerTemplate = player;
		}
	}
}