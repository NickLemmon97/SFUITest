// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "PlayerIGuess.h"
#include "PlayerSelectMainMenu.h"
#include "PlayerFaceSelect.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UPlayerFaceSelect : public UButton
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<APlayerIGuess> player = nullptr;

	UPlayerSelectMainMenu* OwningMenu = nullptr;

	
	UPlayerFaceSelect()
	{
		OnClicked.AddDynamic(this, &UPlayerFaceSelect::UseMyPlayer);
	}

	UFUNCTION()
		void UseMyPlayer();
};
