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
			APawn* oldPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			GetWorld()->GetFirstPlayerController()->UnPossess();
			oldPawn->SetActorLocation(FVector(0, 0, -5000));
			oldPawn->Destroy();

			GetWorld()->GetFirstPlayerController()->Possess(Cast<APawn>(actors[0]));
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(0, 0, 25));
		}	
	}
}
