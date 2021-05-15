// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * The main menu HUD class that spawns the main menu switcher widget on screen
 */
UCLASS()
class SFUITEST_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMenuEntirety> THEMainMenuClass = nullptr;
	class UMenuEntirety* Menu = nullptr;

	virtual void BeginPlay() override;

};
