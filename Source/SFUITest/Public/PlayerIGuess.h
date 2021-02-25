// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerIGuess.generated.h"


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


UCLASS()
class SFUITEST_API APlayerIGuess : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerIGuess();

	UPROPERTY(EditAnywhere)
		FPlayerInformation playerInfo;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh = nullptr;

};
