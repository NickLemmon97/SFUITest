// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::BeginPlay()
{
	//Now we only work on the UI
	FInputModeUIOnly ui;
	SetInputMode(ui);
	bShowMouseCursor = true;
}
