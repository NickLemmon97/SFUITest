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
		GetWorld()->GetFirstPlayerController() ;
		TArray<AActor*> actors;

		UGameplayStatics::GetAllActorsWithTag(GetWorld(), inst->searchTag, actors);
		if (actors.IsValidIndex(0))
		{
			GetWorld()->GetFirstPlayerController()->UnPossess();
			GetWorld()->GetFirstPlayerController()->Possess(Cast<APawn>(actors[0]));
		}

		if (actors.IsValidIndex(0))
		{
			actors[0]->SetActorLocation( FVector(0,0,10) );
		}
				
	}

}
