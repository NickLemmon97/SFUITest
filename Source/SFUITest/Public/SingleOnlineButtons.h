// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "SingleOnlineButtons.generated.h"

/**
 * A User widget to hold 2 buttons that are part of a widget that animates
 */
UCLASS()
class SFUITEST_API USingleOnlineButtons : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//Overriden functions from UUserWidget
	void NativeOnInitialized() override;
	void NativeConstruct() override;
	void NativeDestruct() override;

	//to be bound to SingleButton OnClicked
	UFUNCTION()
	void SingleClicked();


	//The parent widget this is a part of
	class UMenuEntirety* overallMainMenu = nullptr;

	//Binding the buttons of our widget so we can access them in C++
	UPROPERTY(meta = (BindWidget))
		class UButton* SingleButton = nullptr;
	UPROPERTY(meta = (BindWidget))
		class UButton* OnlineButton = nullptr;

	//Handles our animation
	void SetOpenAnim();
	UWidgetAnimation* OpenAnim = nullptr;

};
