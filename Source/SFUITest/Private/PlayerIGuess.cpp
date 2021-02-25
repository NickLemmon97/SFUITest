// Copyright Nick Lemmon


#include "../Public/PlayerIGuess.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlayerIGuess::APlayerIGuess()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

