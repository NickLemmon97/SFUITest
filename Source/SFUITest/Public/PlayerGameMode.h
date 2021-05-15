// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerGameMode.generated.h"

/**
 * The following game mode handles spawning our selected player
 * in the map by changing the 'defaultpawn' in the game mode InitGame()
 */
UCLASS()
class SFUITEST_API APlayerGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
};
