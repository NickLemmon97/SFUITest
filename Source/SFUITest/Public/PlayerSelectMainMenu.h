// Copyright Nick Lemmon

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

	//Overridden functions from UUSerWidget
	void NativeOnInitialized() override;
	void NativeConstruct() override;


	//Takes a Player info to display on the menu
	void SetPlayerInformation(FPlayerInformation player);

	//Binding our menu items to be accessed in c++
	UPROPERTY(meta = (BindWidget))
		class UPlayerInformationBox* PlayerInfoBox = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UPlayerFaceSelect* PlayerFaceButtonBlue = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UPlayerFaceSelect* PlayerFaceButtonRed = nullptr;


	class UMenuEntirety* OwningMenu = nullptr;


	UWidgetAnimation* OpenAnim = nullptr;
};
