// Copyright Nick Lemmon


#include "../Public/MenuEntirety.h"
#include "../Public/MainMenu.h"
#include "../Public/PlayerSelectMainMenu.h"
#include "../Public/SingleOnlineButtons.h"

void UMenuEntirety::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//Set up the owning widgets
	//Set up the initial screen layout
	MainMenu->AddToViewport();
	MainMenu->OwningMenu = this;
	ModeButtons->RemoveFromViewport();
	ModeButtons->overallMainMenu = this;
	PlayerSelect->RemoveFromViewport();
	PlayerSelect->OwningMenu = this;


	//Look for and find the animations that are part of this objects properties
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
					if (WidgetAnim->MovieScene->GetFName() == "SkyStill")
						StillSkyAnim = WidgetAnim;
					if (WidgetAnim->MovieScene->GetFName() == "FastMoveTo")
						FastMoveTo = WidgetAnim;
				}
			}
		}
		Prop = Prop->PropertyLinkNext;
	}
}

void UMenuEntirety::NativeConstruct()
{
	Super::NativeConstruct();

	if (StillSkyAnim)
		PlayAnimation(StillSkyAnim, 0.0f, 0, EUMGSequencePlayMode::Forward, 0.5f, false);

}

void UMenuEntirety::PlayFastMoveTo()
{
	if (FastMoveTo)
	{
		PlayAnimation(FastMoveTo, 0.0f, 1, EUMGSequencePlayMode::Reverse, 3.0f);
	}
}
