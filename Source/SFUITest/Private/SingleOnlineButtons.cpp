// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/SingleOnlineButtons.h"
#include "Components/Button.h"
#include "../Public/PlayerSelectMainMenu.h"
#include "../Public/MenuEntirety.h"
#include "../Public/MainMenu.h"

void USingleOnlineButtons::NativeOnInitialized()
{
	SingleButton->OnClicked.AddDynamic(this, &USingleOnlineButtons::SingleClicked);	
}

void USingleOnlineButtons::NativeConstruct()
{
	Super::NativeConstruct();
	SetOpenAnim();
	if (OpenAnim)
	{
		PlayAnimation(OpenAnim, 0.0f, 1, EUMGSequencePlayMode::Forward, 1.0f, false);
	}
}

void USingleOnlineButtons::NativeDestruct()
{
	Super::NativeDestruct();
}

void USingleOnlineButtons::SetOpenAnim()
{
	UProperty* Prop = GetClass()->PropertyLink;
	while (Prop)
	{
		if (Prop->GetClass() == UObjectProperty::StaticClass())
		{
			UObjectProperty* ObjProp = Cast<UObjectProperty>(Prop);

			if (ObjProp->PropertyClass == UWidgetAnimation::StaticClass())
			{
				UObject* Obj = ObjProp->GetObjectPropertyValue_InContainer(this);
				UWidgetAnimation* WidgetAnim = Cast<UWidgetAnimation>(Obj);

				if (WidgetAnim && WidgetAnim->MovieScene)
				{
					OpenAnim = WidgetAnim;
				}
			}
		}
		Prop = Prop->PropertyLinkNext;
	}
}

void USingleOnlineButtons::SingleClicked()
{
	overallMainMenu->PlayerSelect->AddToViewport();
	overallMainMenu->MainMenu->RemoveFromViewport();
	RemoveFromViewport();
}
