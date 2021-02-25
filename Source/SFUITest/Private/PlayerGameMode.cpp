// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\PlayerGameMode.h"
#include"Kismet\GameplayStatics.h"
#include "Engine/World.h"
#include "../Public/MyGameInstance.h"
#include "../Public/MyPlayerController.h"


void APlayerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	UMyGameInstance* inst = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());

	if (inst)
	{
		DefaultPawnClass = inst->playerTemplate;
	}

	Super::InitGame(MapName, Options, ErrorMessage);
}
