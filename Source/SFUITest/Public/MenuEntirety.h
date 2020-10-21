// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuEntirety.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UMenuEntirety : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeOnInitialized() override;
	void NativeConstruct() override;
	void NativeDestruct() override;

	void PlayFastMoveTo();

	UWidgetAnimation* StillSkyAnim = nullptr;
	UWidgetAnimation* FastMoveTo = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UMainMenu* MainMenu = nullptr;

	UPROPERTY(meta = (BindWidget))
		class USingleOnlineButtons* ModeButtons = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UPlayerSelectMainMenu* PlayerSelect = nullptr;

};
