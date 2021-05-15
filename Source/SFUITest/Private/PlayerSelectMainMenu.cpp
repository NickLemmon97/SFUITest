// Copyright Nick Lemmon


#include "../Public/PlayerSelectMainMenu.h"
#include "../Public/PlayerInformationBox.h"
#include "../Public/PlayerFaceSelect.h"
#include "../Public/MenuEntirety.h"
#include "Kismet/GameplayStatics.h"

void UPlayerSelectMainMenu::NativeOnInitialized()
{
	PlayerFaceButtonBlue ->OwningMenu = this;
	PlayerFaceButtonRed  ->OwningMenu = this;
	PlayerFaceButtonGreen->OwningMenu = this;

	//Search for the animation and set it
	FProperty* Prop = GetClass()->PropertyLink;
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

void UPlayerSelectMainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (OpenAnim)
	{
		PlayAnimation(OpenAnim, 0.0f, 1, EUMGSequencePlayMode::Forward, 2.0f, false);
	}
	
	if (OwningMenu)
	{
		OwningMenu->PlayFastMoveTo();
	}
}

void UPlayerSelectMainMenu::SetPlayerInformation(FPlayerInformation player)
{
	PlayerInfoBox->SetPlayerInformation(player);
}
