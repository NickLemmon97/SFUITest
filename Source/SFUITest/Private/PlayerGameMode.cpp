// Copyright Nick Lemmon


#include "..\Public\PlayerGameMode.h"
#include"Kismet\GameplayStatics.h"
#include "Engine/World.h"
#include "../Public/MyGameInstance.h"
#include "../Public/MyPlayerController.h"


void APlayerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	//Set the default pawn to our selected pawn
	UMyGameInstance* inst = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (inst)
	{
		DefaultPawnClass = inst->playerTemplate;
	}

	Super::InitGame(MapName, Options, ErrorMessage);
}
