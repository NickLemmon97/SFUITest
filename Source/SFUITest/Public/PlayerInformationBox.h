// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerIGuess.h"
#include "PlayerInformationBox.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UPlayerInformationBox : public UUserWidget
{
	GENERATED_BODY()
public:

	void NativeOnInitialized() override;

	UFUNCTION()
	void SelectPlayer();

	void SetPlayerInformation(FPlayerInformation player);

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* NameText = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* DescText = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* LongText = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* StaminaBar = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* OxygenBar = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UButton* SelectButton = nullptr;
};
