// Copyright Nick Lemmon

#include "../Public/SingleOnlineButtons.h"
#include "Components/Button.h"
#include "../Public/PlayerSelectMenu.h"
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

void USingleOnlineButtons::SetOpenAnim()
{
	FProperty* Prop = GetClass()->PropertyLink;
	while (Prop)
	{
		if (Prop->GetClass() == FObjectProperty::StaticClass())
		{
			FObjectProperty* ObjProp = Cast<FObjectProperty>(Prop);

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
