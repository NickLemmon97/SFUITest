// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.generated.h"

/**
 * The player information struct holds the information about our player
 * allows us to pass the players information around without passing the entire actor
 */

USTRUCT()
struct FPlayerInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FText PlayerName = FText::FromString("My Name");

	UPROPERTY(EditAnywhere)
		FText PlayerDescription = FText::FromString("Here is what I like");

	UPROPERTY(EditAnywhere)
		FText PlayerLongDesc = FText::FromString("A lot of information goes here and probably \n doesn't fit all on one line\n\n But Who knows");

	UPROPERTY(EditAnywhere)
		float Health = 100.0f;

	UPROPERTY(EditAnywhere)
		float Oxygen = 100.0f;

	UPROPERTY(EditAnywhere)
		float Stamina = 100.0f;

};

/**
 * The following actor is the main actor that is spawned in game
 * The blueprints created allow for many characters to be created with the same basics
 * A reference is saved in the buttons and the buttons get the players information to display to the UI
 */

UCLASS()
class SFUITEST_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacter();

	UPROPERTY(EditAnywhere)
		FPlayerInformation playerInfo;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh = nullptr;

};
