// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "SingleOnlineButtons.generated.h"

/**
 * 
 */
UCLASS()
class SFUITEST_API USingleOnlineButtons : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeOnInitialized() override;
	void NativeConstruct() override;
	void NativeDestruct() override;

	UFUNCTION()
	void SingleClicked();

	class UMenuEntirety* overallMainMenu = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UButton* SingleButton = nullptr;

	UPROPERTY(meta = (BindWidget))
		class UButton* OnlineButton = nullptr;

	void SetOpenAnim();
	UWidgetAnimation* OpenAnim = nullptr;

};
