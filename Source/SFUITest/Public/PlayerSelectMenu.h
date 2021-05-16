// Copyright Nick Lemmon

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCharacter.h"
#include "PlayerSelectMenu.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API UPlayerSelectMenu : public UUserWidget
{
	GENERATED_BODY()
public:

	//Overridden functions from UUSerWidget
	void NativeOnInitialized() override;
	void NativeConstruct() override;


	//Takes a Player info to display on the menu
	void SetPlayerInformation(FPlayerInformation player);

	//Binding our menu items to be accessed in c++
	UPROPERTY(meta = (BindWidget))
		class UPlayerInformationBox* PlayerInfoBox = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UPlayerSelectButton* PlayerButtonBlue = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UPlayerSelectButton* PlayerButtonRed = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UPlayerSelectButton* PlayerButtonGreen = nullptr;


	class UMenuEntirety* OwningMenu = nullptr;


	UWidgetAnimation* OpenAnim = nullptr;
};
