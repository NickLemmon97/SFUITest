// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\PlayerGameMode.h"
#include"Kismet\GameplayStatics.h"
#include "Engine/World.h"
#include "../Public/MyGameInstance.h"
#include "../Public/MyPlayerController.h"

void APlayerGameMode::BeginPlay()
{

	UMyGameInstance* inst = Cast<UMyGameInstance> ( GetWorld()->GetGameInstance() );

	if (inst)
	{
		FActorSpawnParameters params{ };

		APlayerIGuess* pla = GetWorld()->SpawnActor<APlayerIGuess>(inst->playerTemplate, params);
		
		GetWorld()->GetFirstPlayerController()->UnPossess();
		GetWorld()->GetFirstPlayerController()->Possess(pla);
	}
}
