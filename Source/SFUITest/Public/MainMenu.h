// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void NativeOnInitialized() override;


	UFUNCTION()
	void ClickedPlay();

	class UMenuEntirety* OwningMenu = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TitleText = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UImage* ShipImage = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton= nullptr;
	UPROPERTY(meta = (BindWidget))
		class UButton* OptionsButton= nullptr;
	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton= nullptr;

};
