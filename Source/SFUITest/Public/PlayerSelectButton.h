// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "PlayerCharacter.h"
#include "PlayerSelectMenu.h"
#include "PlayerSelectButton.generated.h"

/**
 * The following is the player select button
 * Originally named for the plan to have an image appear inside the button of the chosen character
 */
UCLASS()
class SFUITEST_API UPlayerSelectButton : public UButton
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<APlayerCharacter> player = nullptr;

	UPlayerSelectMenu* OwningMenu = nullptr;

	
	UPlayerSelectButton()
	{
		OnClicked.AddDynamic(this, &UPlayerSelectButton::UseMyPlayer);
	}

	UFUNCTION()
		void UseMyPlayer();
};
