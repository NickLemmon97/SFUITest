// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuEntirety.generated.h"

/**
 * The following class acts as a menu switcher
 * It contains the internal menus and handles switching between them
 */
UCLASS()
class SFUITEST_API UMenuEntirety : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeOnInitialized() override;
	void NativeConstruct() override;

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
