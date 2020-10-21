// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerIGuess.h"
#include "PlayerSelectMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UPlayerSelectMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:

	void NativeOnInitialized() override;
	void NativeConstruct() override;
	void NativeDestruct() override;

	void SetPlayerInformation(FPlayerInformation player);

	UPROPERTY(meta = (BindWidget))
		class UPlayerInformationBox* PlayerInfoBox = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UPlayerFaceSelect* PlayerFaceButtonBlue = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UPlayerFaceSelect* PlayerFaceButtonRed = nullptr;

	class UMenuEntirety* OwningMenuThing = nullptr;

	UWidgetAnimation* OpenAnim = nullptr;
};
