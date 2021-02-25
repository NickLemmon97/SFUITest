// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerIGuess.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere)
		TSubclassOf<class APlayerIGuess> playerTemplate;
};
