// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerIGuess.h"
#include "MyGameInstance.generated.h"

/**
 * The following game instance saves a reference to the player that was selected
 */
UCLASS()
class SFUITEST_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class APlayerIGuess> playerTemplate;
};
