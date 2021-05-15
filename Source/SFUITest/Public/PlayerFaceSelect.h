// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "PlayerIGuess.h"
#include "PlayerSelectMainMenu.h"
#include "PlayerFaceSelect.generated.h"

/**
 * The following is the player select button
 * Originally named for the plan to have an image appear inside the button of the chosen character
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
