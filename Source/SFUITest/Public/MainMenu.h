// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * This class is the main menu
 * It contains all the UI items that would appear on the main menu
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
