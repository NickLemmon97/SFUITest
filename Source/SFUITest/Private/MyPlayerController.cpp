// Copyright Nick Lemmon


#include "../Public/MyPlayerController.h"


void AMyPlayerController::BeginPlay()
{
	//Now we only work on the UI
	FInputModeUIOnly ui;
	SetInputMode(ui);
	bShowMouseCursor = true;
}
