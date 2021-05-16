// Copyright Nick Lemmon


#include "../Public/PlayerSelectMenu.h"
#include "../Public/PlayerInformationBox.h"
#include "../Public/PlayerSelectButton.h"
#include "../Public/MenuEntirety.h"
#include "Kismet/GameplayStatics.h"

void UPlayerSelectMenu::NativeOnInitialized()
{
	PlayerButtonBlue ->OwningMenu = this;
	PlayerButtonRed  ->OwningMenu = this;
	PlayerButtonGreen->OwningMenu = this;

	//Search for the animation and set it
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

void UPlayerSelectMenu::NativeConstruct()
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

void UPlayerSelectMenu::SetPlayerInformation(FPlayerInformation player)
{
	PlayerInfoBox->SetPlayerInformation(player);
}
